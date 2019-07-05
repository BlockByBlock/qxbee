#ifndef QXBEE_FRAME_H
#define QXBEE_FRAME_H

#include <QHash>
#include <QMutex>
#include <QScopedPointer>
#include "FrameData.h"

namespace QXbee {

/*!
 * \class The QXbee Frame
 */
class Frame
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
   * \brief Wrap a payload w delimiter, length and checksum
   * \param Data payload
   * \return Complete Xbee frame with appropriate flag
   */
  QByteArray wrapPayload(const quint8 type, const QByteArray& data);

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

  /*!
   * \brief Extract hash from frameData
   * \return payload hash
   */
  QHash<QString, QByteArray> extractHash();

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

  QMutex                    mutex;
  QScopedPointer<FrameData> frameData;
};

}
#endif // QXBEE_FRAME_H

