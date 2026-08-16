/* /////////////////////////////////////////////////////////////////////////
 * File:    sistools/common/usage.h
 *
 * Purpose: Help / version usage helpers for sistools programs.
 *
 * Created: 7th August 2026
 * Updated: 16th August 2026
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


/** \file sistools/common/usage.h
 *
 * [C, C++] Help / version usage helpers for sistools programs.
 */

#ifndef STCC_INCL_SISTOOLS_COMMON_H_USAGE
#define STCC_INCL_SISTOOLS_COMMON_H_USAGE

#ifndef STCC_DOCUMENTATION_SKIP_SECTION
# define STCC_VER_SISTOOLS_COMMON_H_USAGE_MAJOR  0
# define STCC_VER_SISTOOLS_COMMON_H_USAGE_MINOR  1
# define STCC_VER_SISTOOLS_COMMON_H_USAGE_PATCH  0
# define STCC_VER_SISTOOLS_COMMON_H_USAGE_EDIT   3
#endif /* !STCC_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <sistools/common.h>

#include <clasp/clasp.h>

#include <stdio.h>


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Emits the Diagnosticism-based version line used by `--version`.
 *
 * Writes "<toolName> v<diagnosticism-version>\\n" to @a stm.
 */
STCC_CALL(void)
stcc_show_version(
    FILE*       stm
,   char const* toolName
,   int         verMajor
,   int         verMinor
,   int         verPatch
,   int         verAlphaBeta
) STCC_NOEXCEPT;

/** Emits CLASP-like usage (custom header + `clasp_showBody`).
 *
 * Console width is obtained via PlatformSTL, or a TinyCC Unix ioctl /
 * COLUMNS fallback; tab size and blanks-between-items are fixed inside
 * this helper.
 *
 * @param args CLASP parsed arguments (may be NULL if unused by
 *  `clasp_showBody` for the given flags).
 * @param specifications CLASP alias array (must not be NULL).
 * @param stm Output stream (e.g. `stdout`).
 * @param toolName Program name for the version line.
 * @param summary Optional summary line (skipped if NULL or empty).
 * @param copyright Optional copyright line (skipped if NULL or empty).
 * @param description Optional description line (skipped if NULL or empty).
 * @param usage Usage synopsis line (must not be NULL).
 * @param verMajor Major version component.
 * @param verMinor Minor version component.
 * @param verPatch Patch version component.
 * @param verAlphaBeta Alpha/beta/rc encoding for **Diagnosticism**.
 */
STCC_CALL(void)
stcc_show_help(
    clasp_arguments_t const*    args
,   clasp_alias_t const*        specifications
,   FILE*                       stm
,   char const*                 toolName
,   char const*                 summary
,   char const*                 copyright
,   char const*                 description
,   char const*                 usage
,   int                         verMajor
,   int                         verMinor
,   int                         verPatch
,   int                         verAlphaBeta
) STCC_NOEXCEPT;


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STCC_INCL_SISTOOLS_COMMON_H_USAGE */

/* ///////////////////////////// end of file //////////////////////////// */
