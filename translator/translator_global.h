#ifndef TRANSLATOR_GLOBAL_H
#define TRANSLATOR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TRANSLATOR_LIBRARY)
#  define TRANSLATOR_EXPORT Q_DECL_EXPORT
#else
#  define TRANSLATOR_EXPORT Q_DECL_IMPORT
#endif

#endif // TRANSLATOR_GLOBAL_H
