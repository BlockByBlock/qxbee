#ifndef QXBEE_FRAME_DATA_H
#define QXBEE_FRAME_DATA_H

#include <QByteArray>
#include <QHash>

namespace QXbee {

/*!
 * \class The QXbee Frame Data Structure
 * \brief Specific data structure
 */
struct FrameData
{
  virtual ~FrameData() = default;

 /*!
  * \brief Sort data into data fields
  * \param Xbee frame without delimiter, frame length, and checksum
  * \note this method should only be accessed from populateFrame() in Frame class
  *       for access safety
  */
  virtual void sortFields(const QByteArray& data) = 0;

  QByteArray                 payload;
  QHash<QString, QByteArray> hash;
};

}
#endif // QXBEE_FRAME_DATA_H

