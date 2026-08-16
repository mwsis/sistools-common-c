# sistools-common-c - Changes <!-- omit in toc -->


## 0.1.0 - 16th August 2026

* Added usage helpers (**`include/sistools/common/usage.h`**, **`src/usage.c`**): **`stcc_show_version()`**, **`stcc_show_help()`** (from **mksock** helpers);
* Required dependencies extended: **CLASP**, **STLSoft** (in addition to **Diagnosticism**);
* Unit test **test.unit.usage**;
* MSVC: suppress CRT secure deprecation (**C4996** / **`/wd4996`**) so **`tmpfile()`**-using unit tests compile with warnings-as-errors;
* TinyCC: **`stcc_show_help()`** uses a Unix **`ioctl`** / **`COLUMNS`** console-width fallback (**STLSoft** still rejects TinyCC after **`_STLSOFT_FORCE_ANY_COMPILER`**);


## 0.0.1 - 7th August 2026

* **Doxygen** support: **Doxyfile**, **doc/mainpage.md**, **generate_doxygen.sh**;


## 0.0.0 - 7th August 2026

* Initial release: project scaffolding for the shared **sistools** C helpers library;
* Project documentation and Git hygiene (**README.md**, **CHANGES.md**, **NEWS.md**, **TODO.md**, **INSTALL.md**, **EXAMPLES.md**, **AUTHORS.md**, **LICENSE**, **.gitignore**, **.gitattributes**);
* CMake scaffolding (**CMakeLists.txt**, **cmake/** modules, package export as **`sistools-common-c::core`**), **.sis/** metadata, and versioned stub API (**`include/sistools/common.h`**, **`stcc_api_version()`**);
* CMake helper scripts (**prepare_cmake.sh**, **build_cmake.sh**, **clean_cmake.sh**, **remove_cmake_artefacts.sh**, **run_all_*.sh** / **.cmd**);
* Test tree: scratch **test.scratch.libver** and unit **test.unit.api_version** (test-only deps **STLSoft**, **xTests**);
* Required dependency on **Diagnosticism**; **test.scratch.libver** uses **`diagnosticism_calc_version_string()`**;
* Modular GitHub Actions CI (**`ci.yml`** / **`ci-cell.yml`**) covering Linux (**Clang**/**GCC**/**TinyCC**), macOS (**Clang**), and Windows (**cl** / **MinGW**); **TinyCC** is library build/install only (**`-T`** / no unit tests) until **STLSoft** / **xTests** support it;
* Editor defaults (**`.vscode/settings.json`**, **`.vimrc`**);


<!-- ########################### end of file ########################### -->
