/* /////////////////////////////////////////////////////////////////////////
 * File:    src/usage.c
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <sistools/common/usage.h>

#include <diagnosticism/version_string.h>

/* TinyCC is unknown to STLSoft, so skip PlatformSTL on that translator. */
#if defined(__TINYC__)
# if !defined(_WIN32)
#  include <stdlib.h>
#  include <sys/ioctl.h>
#  include <unistd.h>
# endif /* !_WIN32 */
#else /* ? __TINYC__ */
# include <platformstl/system/console_functions.h>
#endif /* __TINYC__ */

#include <stddef.h>


/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

#define USAGE_TAB_SIZE                                      (-4)
#define USAGE_BLANKS_BETWEEN_ITEMS                          1


/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

/** Console column count for \c clasp_showBody, or -1 if unknown. */
static
int
console_width_(void)
{
#if defined(__TINYC__)
# if defined(_WIN32)

    return -1;
# else /* ? _WIN32 */

    struct winsize  ws;
    char const*     columns = getenv("COLUMNS");

    if (NULL != columns)
    {
        char*   ep = NULL;
        long    n  = strtol(columns, &ep, 10);

        if (NULL != ep &&
            '\0' == *ep &&
            n > 0)
        {
            return (int)n;
        }
    }

    if (-1 != ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) &&
        0 != ws.ws_col)
    {
        return (int)ws.ws_col;
    }

    return -1;
# endif /* _WIN32 */
#else /* ? __TINYC__ */

    return (int)platformstl_C_get_console_width();
#endif /* __TINYC__ */
}

/** Writes "<toolName> v<diagnosticism-version>\n" to @a stm. */
static
void
print_tool_version_line_(
    FILE*       stm
,   char const* toolName
,   int         verMajor
,   int         verMinor
,   int         verPatch
,   int         verAlphaBeta
)
{
    char    vs[100];
    size_t  n = 0;

    /* Failure is ignored: buffer is ample for any plausible version string. */
    diagnosticism_calc_version_string(
        vs, sizeof(vs)
    ,   verMajor, verMinor, verPatch, verAlphaBeta
    ,   &n
    );

    fprintf(stm, "%s v%.*s\n", toolName, (int)n, vs);
}


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

STCC_CALL(void)
stcc_show_version(
    FILE*       stm
,   char const* toolName
,   int         verMajor
,   int         verMinor
,   int         verPatch
,   int         verAlphaBeta
) STCC_NOEXCEPT
{
    print_tool_version_line_(
        stm
    ,   toolName
    ,   verMajor, verMinor, verPatch, verAlphaBeta
    );
}

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
) STCC_NOEXCEPT
{
    if (NULL != summary &&
        '\0' != summary[0])
    {
        fprintf(stm, "%s\n", summary);
    }

    print_tool_version_line_(
        stm
    ,   toolName
    ,   verMajor, verMinor, verPatch, verAlphaBeta
    );

    if (NULL != copyright &&
        '\0' != copyright[0])
    {
        fprintf(stm, "%s\n", copyright);
    }

    if (NULL != description &&
        '\0' != description[0])
    {
        fprintf(stm, "%s\n", description);
    }

    fprintf(stm, "\n");
    fprintf(stm, "%s\n", usage);
    fprintf(stm, "\n");

    clasp_showBody(
        args
    ,   specifications
    ,   clasp_showBodyByFILE
    ,   stm
    ,   0
    ,   console_width_()
    ,   USAGE_TAB_SIZE
    ,   USAGE_BLANKS_BETWEEN_ITEMS
    );
}


/* ///////////////////////////// end of file //////////////////////////// */
