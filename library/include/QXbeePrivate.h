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
  QXbeePrivate();

  /*!
   * \brief QXbeePrivate Destructor
   */
  ~QXbeePrivate() = default;

  /*!
   * \brief QXbeePrivate Copy Constructor
   * \param other QXbeePrivate
   */
  QXbeePrivate(const QXbeePrivate &other);

  /*!
   * Default operation
   */
  QXbeePrivate& operator = (const QXbeePrivate &other) = default;
  QXbeePrivate(QXbeePrivate&& other) = default;
  QXbeePrivate& operator = (QXbeePrivate&& other) = default;

  QSharedDataPointer<Frame> frame;
  QByteArray                buffer;
};

}

#endif // QXBEE_PRIVATE_H

