#ifndef QXBEE_FRAME_DATA_H
#define QXBEE_FRAME_DATA_H

#include <QByteArray>

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
  * \param Raw xbee input
  * \note this method should only be accessed from populateFrame() in Frame class
  *       for access safety
  */
  virtual void sortFields(const QByteArray& data) = 0;

  QByteArray              payload;
};

}
#endif // QXBEE_FRAME_DATA_H

