#ifndef SIGBASEIO_GLOBAL_H
#define SIGBASEIO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIGBASEIO_LIBRARY)
#  define SIGBASEIO_EXPORT Q_DECL_EXPORT
#else
#  define SIGBASEIO_EXPORT Q_DECL_IMPORT
#endif

#endif // SIGBASEIO_GLOBAL_H
