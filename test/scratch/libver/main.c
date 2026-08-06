/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/libver/main.c
 *
 * Purpose: Scratch program that prints the sistools-common-c version.
 *
 * Created: 7th August 2026
 * Updated: 7th August 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <sistools/common.h>

#include <diagnosticism/version_string.h>

#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

/** Writes "\t<libname> v<diagnosticism-version>\n" to @a stm. */
static
void
version_(
    FILE*       stm
,   char const* libname
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

    fprintf(stm, "\t%s v%.*s\n", libname, (int)n, vs);
}


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char* argv[])
{
    ((void)argc);
    ((void)argv);

    version_(
        stdout
    ,   "sistools-common-c"
    ,   STCC_VER_MAJOR
    ,   STCC_VER_MINOR
    ,   STCC_VER_PATCH
    ,   STCC_VER_ALPHABETA
    );

    version_(
        stdout
    ,   "Diagnosticism"
    ,   DIAGNOSTICISM_VER_MAJOR
    ,   DIAGNOSTICISM_VER_MINOR
    ,   DIAGNOSTICISM_VER_PATCH
    ,   DIAGNOSTICISM_VER_ALPHABETA
    );

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */
