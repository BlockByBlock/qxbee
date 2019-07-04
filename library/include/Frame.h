#ifndef QXBEE_FRAME_H
#define QXBEE_FRAME_H

#include <QSharedData>
#include <QScopedPointer>
#include "FrameData.h"

namespace QXbee {

/*!
 * \class The QXbee Frame
 */
class Frame : public QSharedData
{
public:
  /*! Bytes that need to be escaped*/
  enum EscapeByte {
    StartDelimiter = 0x7E,
    Escape = 0x7D
    //XON = 0x11,
    //XOFF = 0x13
  };

  /*! Default Constructor */
  Frame() = default;

  /*! Explicit Constructor */
  explicit Frame(QByteArray& input);

  /*! Default Destructor */
  ~Frame() = default;

  /*! Copy Constructor */
  Frame(const Frame &other);

  /*!
   * Default operation
   */
  Frame& operator = (const Frame &other) = default;
  Frame(Frame&& other) = default;
  Frame& operator = (Frame&& other) = default;

  /*!
   * \brief Clean up inputt and populate data structures
   * \param Raw input from Xbee
   */
  void populateFrame(QByteArray& input);

  /*!
   * \brief Construct specific frame type
   * \param Frame Type
   */
  FrameData* constructFrameType(quint8 type);

  /*!
   * \brief Get frame complete status
   * \return True if frame is completed
   */
  bool getComplete() const;

  /*!
   * \brief Extract payload from frameData
   * \return payload
   */
  QByteArray extractPayload();

protected:

  /*!
   * \brief Validate checksum
   * \param Data to calculate checksum for validation (w Checksum byte)
   * \return True if checksum is valid
   */
  bool validateChecksum(const QByteArray& data);

  /*!
   * \brief Calculate Xbee Checksum
   * \param Data to calculate from
   * \return A single byte of QByteArray
   */
  QByteArray calculateChecksum(const QByteArray& data);

private:

  bool          hasDelimiter {false};
  bool          isComplete {false};
  quint8        frameType {0};
  quint8        frameLen {0};

  QScopedPointer<FrameData> frameData;
};

}
#endif // QXBEE_FRAME_H

