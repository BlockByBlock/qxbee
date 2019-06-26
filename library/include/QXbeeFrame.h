#ifndef QXBEE_FRAME_H
#define QXBEE_FRAME_H

#include <QtGlobal>
#include <QSharedDataPointer>
#include "QXbee.h"
#include "QXbeeFrameData.h"

namespace QXbee {

/**
 * \class The QXbee Frame Types
 * \brief The generic data frame structure of xbee
 */
class QXbeeFrame
{
public:
  /** Bytes that need to be escaped*/
  enum EscapeByte {
    StartDelimiter = 0x7E,
    Escape = 0x7D
    //XON = 0x11,
    //XOFF = 0x13
  };

  /** Default constructor */
  QXbeeFrame();

  /** Destructor */
  ~QXbeeFrame();

  /** Clear this frame data */
  void clear();

  /**
   * @brief Set Frame Type
   * @param Frame type
   */
  void setFrameType(QXbeeFrameData::ApiFrameType type);

  /**
   * @brief Get Data Length
   * @return Length of frame
   */
  quint16 getDataLen() const;

  /**
   * @brief Set Data Length
   * @param Length to be set to frame
   */
  void setDataLen(quint16 len);

protected:
  /**
   * @brief Setup Frame
   * @param Frame type
   * @param QByteArray of frame
   * @param Length of the frame
   */
  void processData(QByteArray data);
};

}

#endif // QXBEE_FRAME_H

