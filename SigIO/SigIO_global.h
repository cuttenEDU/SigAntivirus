#ifndef SIGIO_GLOBAL_H
#define SIGIO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIGIO_LIBRARY)
#  define SIGIO_EXPORT Q_DECL_EXPORT
#else
#  define SIGIO_EXPORT Q_DECL_IMPORT
#endif

#endif // SIGBASEIO_GLOBAL_H