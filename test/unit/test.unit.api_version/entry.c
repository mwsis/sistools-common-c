/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.api_version/entry.c
 *
 * Purpose: Unit-tests for stcc_api_version().
 *
 * Created: 7th August 2026
 * Updated: 7th August 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <sistools/common.h>

#include <xtests/terse-api.h>

#include <stlsoft/stlsoft.h>

#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_api_version_matches_STCC_VER(void);


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.api_version", verbosity))
    {
        XTESTS_RUN_CASE(TEST_api_version_matches_STCC_VER);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void TEST_api_version_matches_STCC_VER(void)
{
    TEST_INT_EQ(STCC_VER, stcc_api_version());
}


/* ///////////////////////////// end of file //////////////////////////// */
