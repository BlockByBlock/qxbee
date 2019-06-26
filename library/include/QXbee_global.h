#ifndef QXBEE_GLOBAL_H
#define QXBEE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QXBEE_LIBRARY)
#  define QXBEESHARED_EXPORT Q_DECL_EXPORT
#else
#  define QXBEESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QXBEE_GLOBAL_H
