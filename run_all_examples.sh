#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
[[ -n "$MSYSTEM" ]] && DefaultMakeCmd=mingw32-make.exe || DefaultMakeCmd=make
MakeCmd=${SIS_CMAKE_MAKE_COMMAND:-${SIS_CMAKE_COMMAND:-$DefaultMakeCmd}}
ProjectNameFile="$Dir/.sis/project_name.txt"
ProjectName=$(tr -d '[:space:]' < "$ProjectNameFile")

ListOnly=0
RunMake=1


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
    --list-only|-l)

      ListOnly=1
      ;;
    --no-make|-M)

      RunMake=0
      ;;
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Runs all (matching) example programs

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -l
    --list-only
        lists the target programs but does not execute them

    -M
    --no-make
        does not execute CMake and make before running examples


    standard flags:

    --help
        displays this help and terminates

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

status=0

if [ $RunMake -ne 0 ]; then

  if [ $ListOnly -eq 0 ]; then

    echo "Executing build (via command \`${SisClr_Blue}${SisClr_Bold}$MakeCmd${SisClr_None}\`) and then running all ${ProjectName} example programs"

    mkdir -p $CMakeDir || exit 1

    cd $CMakeDir

    $MakeCmd
    status=$?

    cd ->/dev/null
  fi
else

  if [ ! -d "$CMakeDir" ] || [ ! -f "$CMakeDir/CMakeCache.txt" ] || [ ! -d "$CMakeDir/CMakeFiles" ]; then

    >&2 echo "$ScriptPath: ${SisClr_Red}${SisClr_Bold}cannot run in '--no-make' mode without a previous successful build step${SisClr_None}"

    exit 1
  fi
fi

if [ $status -eq 0 ]; then

  if [ $ListOnly -ne 0 ]; then

    echo "Listing all ${ProjectName} example programs"
  else

    echo "Running all ${ProjectName} example programs"
  fi

  # Prefer named example binaries (b64/Pantheios style); also accept anything
  # executable under the examples/ build tree (Diagnosticism style).
  for f in $(
    {
      find "$CMakeDir" -type f '(' -name 'example.c.*' -o -name 'example.cpp.*' ')' -exec test -x {} \; -print
      if [ -d "$CMakeDir/examples" ]; then

        find "$CMakeDir/examples" -type f -exec test -x {} \; -print
      fi
    } | sort -u
  )
  do

    if [ $ListOnly -ne 0 ]; then

      echo "would execute ${SisClr_Blue}${SisClr_Bold}$f${SisClr_None}:"

      continue
    fi

    echo
    echo "executing ${SisClr_Blue}${SisClr_Bold}$f${SisClr_None}:"

    # NOTE: we do not break on fail, so one failing example does not hide others
    $f
  done
fi

exit $status


# ############################## end of file ############################# #
