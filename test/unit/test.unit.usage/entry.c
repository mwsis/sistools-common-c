/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.usage/entry.c
 *
 * Purpose: Unit-tests for stcc_show_version().
 *
 * Created: 7th August 2026
 * Updated: 7th August 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <sistools/common/usage.h>

#include <xtests/terse-api.h>

#include <stlsoft/stlsoft.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_show_version_WRITES_TOOL_AND_VERSION(void);


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.usage", verbosity))
    {
        XTESTS_RUN_CASE(TEST_show_version_WRITES_TOOL_AND_VERSION);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void TEST_show_version_WRITES_TOOL_AND_VERSION(void)
{
    char    buf[256];
    FILE*   stm;
    size_t  n;

    stm = tmpfile();
    TEST_PTR_NE(NULL, stm);

    stcc_show_version(stm, "demo-tool", 1, 2, 3, 0xFF);

    rewind(stm);
    n = fread(buf, 1, sizeof(buf) - 1, stm);
    buf[n] = '\0';
    fclose(stm);

    TEST_MS_EQ("demo-tool v1.2.3\n", buf);
}


/* ///////////////////////////// end of file //////////////////////////// */
