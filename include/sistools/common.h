/* /////////////////////////////////////////////////////////////////////////
 * File:    sistools/common.h
 *
 * Purpose: Main header file for sistools-common-c (C-API).
 *
 * Created: 7th August 2026
 * Updated: 7th August 2026
 *
 * Home:    https://github.com/sistools/sistools-common-c/
 *
 * Copyright (c) 2026, Matthew Wilson and Synesis Information Systems
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer;
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution;
 * - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file sistools/common.h
 *
 * [C, C++] Main header file for sistools-common-c (C-API).
 */

#ifndef STCC_INCL_SISTOOLS_H_COMMON
#define STCC_INCL_SISTOOLS_H_COMMON

#ifndef STCC_DOCUMENTATION_SKIP_SECTION
# define STCC_VER_SISTOOLS_H_COMMON_MAJOR  0
# define STCC_VER_SISTOOLS_H_COMMON_MINOR  0
# define STCC_VER_SISTOOLS_H_COMMON_PATCH  1
# define STCC_VER_SISTOOLS_H_COMMON_EDIT   3
#endif /* !STCC_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

/**
 * \def STCC_VER_MAJOR
 *
 * The Major version number of the sistools-common-c library
 *
 * \def STCC_VER_MINOR
 *
 * Minor version number of the sistools-common-c library
 *
 * \def STCC_VER_PATCH
 *
 * The patch number of the sistools-common-c library
 *
 * \def STCC_VER
 *
 * The composite version of the sistools-common-c library
 */

#define STCC_VER_MAJOR          0
#define STCC_VER_MINOR          0
#define STCC_VER_PATCH          0
#define STCC_VER_ALPHABETA      0xFF

#define STCC_VER \
    (0\
        |   (   STCC_VER_MAJOR       << 24   ) \
        |   (   STCC_VER_MINOR       << 16   ) \
        |   (   STCC_VER_PATCH       <<  8   ) \
        |   (   STCC_VER_ALPHABETA   <<  0   ) \
    )


/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#include <stdint.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** \def STCC_CALL(rt)
 *
 * Calling-convention / linkage wrapper for API functions.
 */
#ifndef STCC_CALL
# ifdef __cplusplus
#  define STCC_CALL(rt)                                     extern "C" rt
# else
#  define STCC_CALL(rt)                                     rt
# endif
#endif

#if 0
#elif defined(STLSOFT_NOEXCEPT)
# define STCC_NOEXCEPT                                      STLSOFT_NOEXCEPT
#else
# if 0
# elif defined(__cplusplus)
#  if 0
#  elif __cplusplus >= 201103L
#   define STCC_NOEXCEPT                                    noexcept
#  else
#   define STCC_NOEXCEPT                                    throw()
#  endif
# else
#  define STCC_NOEXCEPT
# endif
#endif


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

typedef uint32_t                                            stcc_uint32_t;


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Obtains the sistools-common-c version (at time of compilation).
 */
STCC_CALL(stcc_uint32_t)
stcc_api_version(void) STCC_NOEXCEPT;


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STCC_INCL_SISTOOLS_H_COMMON */

/* ///////////////////////////// end of file //////////////////////////// */
