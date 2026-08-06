#! /bin/bash

#############################################################################
# File:     generate_doxygen.sh
#
# Purpose:  Generates HTML API documentation from public headers via Doxygen
#
#############################################################################

ScriptPath=$0
Dir=$(cd "$(dirname "$ScriptPath")" && pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}


# ##########################################################
# colours

if command -v tput > /dev/null; then

  SisClr_Blue=${FG_BLUE:-$(tput setaf 4)}
  SisClr_Red=${FG_RED:-$(tput setaf 1)}
  SisClr_Bold=${FD_BOLD:-$(tput bold)}
  SisClr_None=${FD_NONE:-$(tput sgr0)}
else

  SisClr_Blue=
  SisClr_Red=
  SisClr_Bold=
  SisClr_None=
fi


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Generates HTML API documentation from public headers via Doxygen

$ScriptPath [ ... flags/options ... ]

Flags/options:

    standard flags:

    --help
        displays this help and terminates

Environment:

    SIS_CMAKE_BUILD_DIR
        CMake build directory (default: <project>/_build); documentation is
        written to <build-dir>/doxygen/html/

EOF

      exit 0
      ;;
    *)

      >&2 echo "$ScriptPath: ${SisClr_Red}${SisClr_Bold}unrecognised argument '$1'${SisClr_None}; use --help for usage"

      exit 1
      ;;
  esac

  shift
done


# ##########################################################
# main()

cd "$Dir" || exit 1

if ! command -v doxygen >/dev/null 2>&1; then

  >&2 echo "$ScriptPath: ${SisClr_Red}${SisClr_Bold}doxygen not found on PATH${SisClr_None}"

  exit 1
fi

mkdir -p "${CMakeDir}/doxygen"

{
  cat Doxyfile
  echo ""
  echo "# Output directory (overridden by ${Basename})"
  echo "OUTPUT_DIRECTORY = ${CMakeDir}/doxygen"
} | doxygen -

echo "API documentation written to ${SisClr_Blue}${SisClr_Bold}${CMakeDir}/doxygen/html/index.html${SisClr_None}"


# ############################## end of file ############################# #
