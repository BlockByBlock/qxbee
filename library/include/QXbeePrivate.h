#ifndef QXBEE_PRIVATE_H
#define QXBEE_PRIVATE_H

#include "Frame.h"

namespace QXbee {

/*!
 * \struct The QXbee Private Struct
 * \brief Hold data members of QXbee in PIMPL method
 */
class QXbeePrivate
{
public:
  /*!
   * \brief QXbeePrivate Constructor
   */
  QXbeePrivate();

  /*!
   * \brief QXbeePrivate Destructor
   */
  ~QXbeePrivate() = default;

  QScopedPointer<Frame> frame;
  QByteArray            buffer;
};

}

#endif // QXBEE_PRIVATE_H

