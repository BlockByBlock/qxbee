#ifndef QXBEE_PRIVATE_H
#define QXBEE_PRIVATE_H

#include "Frame.h"

namespace QXbee {

/*!
 * \struct The QXbee Private Struct
 * \brief Hold data members of QXbee in PIMPL method
 */
class QXbeePrivate: public QSharedData
{
public:
  /*!
   * \brief QXbeePrivate Constructor
   */
  QXbeePrivate() = default;

  /*!
   * \brief QXbeePrivate Copy Constructor
   * \param other QXbeePrivate
   */
  QXbeePrivate(const QXbeePrivate &other);

  /*!
   * \brief QXbeePrivate Destructor
   */
  ~QXbeePrivate() = default;

  QSharedDataPointer<Frame> frame;
  QByteArray                buffer;
};

}

#endif // QXBEE_PRIVATE_H

