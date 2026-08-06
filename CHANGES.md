# sistools-common-c - Changes <!-- omit in toc -->


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
