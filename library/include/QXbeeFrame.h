#ifndef QXBEE_FRAME_H
#define QXBEE_FRAME_H

#include <QSharedData>
#include <QSharedPointer>
#include "QXbeeFrameData.h"

namespace QXbee {

/**
 * \class The QXbee Frame Class
 * \brief Hold all different frame data structure
 */
class QXbeeFrame: public QSharedData
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

  /** Copy constructor */
  QXbeeFrame(const QXbeeFrame &other);

  /** Getter and setter for QXbeeFrameData */
  int       indexDelimiter();
  void      setIndexDelimiter(int val);
  quint16   frameLen();
  void      setFrameLen(quint16 val);
  quint8    frameType();
  void      setFrameType(quint8 val);

  /**
   * @brief Check if frame is completed
   * @return True if complete frame
   */
  bool isComplete();

  /** Clear frame data */
  void clearData();

  /**
   * @brief createFrameType
   * @param type
   * @return
   */
  static QXbeeFrameData* createFrameType(quint8 type);

private:
  int                            _indexDelimiter;
  quint8                         _frameLen;
  QSharedPointer<QXbeeFrameData> d;
};

}

#endif // QXBEE_FRAME_H

