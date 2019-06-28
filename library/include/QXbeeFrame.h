#ifndef QXBEE_FRAME_H
#define QXBEE_FRAME_H

#include <QSharedData>
#include <QSharedPointer>
#include "QXbeeFrameData.h"

namespace QXbee {

/*!
 * \class The QXbee Frame Class
 * \brief Hold all different frame data structure
 */
class QXbeeFrame: public QSharedData
{
public:
  /*! Bytes that need to be escaped*/
  enum EscapeByte {
    StartDelimiter = 0x7E,
    Escape = 0x7D
    //XON = 0x11,
    //XOFF = 0x13
  };

  /*! Default constructor */
  QXbeeFrame();

  /*! Destructor */
  ~QXbeeFrame();

  /*! Copy constructor */
  QXbeeFrame(const QXbeeFrame &other);

  /*! Getter and setter for QXbeeFrameData */
  int       indexDelimiter() const;
  void      setIndexDelimiter(int val);
  quint16   frameLen() const;
  void      setFrameLen(const quint16 val);
  quint8    frameType() const;
  void      setFrameType(const quint8 val);
  bool      completeFlag() const;
  void      setCompleteFlag(bool val);

  /*! Clear frame data */
  void clearData();

  /*!
   * \brief createFrameType
   * \param type
   * \return
   */
  static QXbeeFrameData* createFrameType(quint8 type);

private:
  int                            _indexDelimiter;
  quint8                         _frameLen;
  bool                           _completeFlag;
  QSharedPointer<QXbeeFrameData> d;
};

}

#endif // QXBEE_FRAME_H

