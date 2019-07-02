#ifndef QXBEE_FRAME_H
#define QXBEE_FRAME_H

#include <QSharedData>
#include <QScopedPointer>
#include "FrameData.h"

namespace QXbee {

/*!
 * \class The QXbee Frame
 * \brief Implicity shared data class
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
  explicit Frame(const QByteArray& input);

  /*! Virtual Destructor */
  virtual ~Frame() = default;

  /*! Copy Constructor */
  Frame(const Frame &other);

  /*!
   * \brief Populate frame data structures with input
   * \param Raw input from Xbee
   */
  void populateFrame(const QByteArray& input);

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

private:

  bool          hasDelimiter;
  bool          isComplete;
  int           indexDelimiter;
  quint8        frameType;
  quint8        frameLen;
  quint8        checksum;

  QScopedPointer<FrameData> frameData;
};

}
#endif // QXBEE_FRAME_H

