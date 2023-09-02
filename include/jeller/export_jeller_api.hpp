
#ifndef PUBLIC_JELLER_API_H
#define PUBLIC_JELLER_API_H

#ifdef JELLER_STATIC_DEFINE
#  define PUBLIC_JELLER_API
#  define JELLER_NO_EXPORT
#else
#  ifndef PUBLIC_JELLER_API
#    ifdef Jeller_EXPORTS
        /* We are building this library */
#      define PUBLIC_JELLER_API __declspec(dllexport)
#    else
        /* We are using this library */
#      define PUBLIC_JELLER_API __declspec(dllimport)
#    endif
#  endif

#  ifndef JELLER_NO_EXPORT
#    define JELLER_NO_EXPORT 
#  endif
#endif

#ifndef JELLER_DEPRECATED
#  define JELLER_DEPRECATED __declspec(deprecated)
#endif

#ifndef JELLER_DEPRECATED_EXPORT
#  define JELLER_DEPRECATED_EXPORT PUBLIC_JELLER_API JELLER_DEPRECATED
#endif

#ifndef JELLER_DEPRECATED_NO_EXPORT
#  define JELLER_DEPRECATED_NO_EXPORT JELLER_NO_EXPORT JELLER_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef JELLER_NO_DEPRECATED
#    define JELLER_NO_DEPRECATED
#  endif
#endif

#endif /* PUBLIC_JELLER_API_H */
