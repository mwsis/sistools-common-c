# sistools-common-c - Installation and Use <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [Requisites](#requisites)
- [Building](#building)
	- [via CMake](#via-cmake)
- [Using the library](#using-the-library)


## Requisites

Installation requires **CMake** (3.20 or later) and a supported C toolchain.

**sistools-common-c** depends on:

* [**Diagnosticism**](https://github.com/synesissoftware/Diagnosticism);

Building the project's unit tests additionally requires:

* [**STLSoft**](https://github.com/synesissoftware/STLSoft);
* [**xTests**](https://github.com/synesissoftware/xTests);

> **NOTE**: if you do not wish to build the tests, then you need not
> obtain/install the test-only dependencies (use `./prepare_cmake.sh -T`).


## Building


### via CMake

The primary choice for installation is by use of **CMake**.

1. Obtain the latest distribution of **sistools-common-c**, from
   https://github.com/sistools/sistools-common-c/, e.g.

	```bash
	$ mkdir -p ~/open-source
	$ cd ~/open-source
	$ git clone https://github.com/sistools/sistools-common-c/
	```

2. Prepare the CMake configuration, via the **prepare_cmake.sh** script, as
   in:

	```bash
	$ cd ~/open-source/sistools-common-c
	$ ./prepare_cmake.sh
	```

   Until an **examples** tree is present, you may pass `-E` to disable
   that option explicitly (the configure step also skips a missing
   `examples/` directory). Use `-T` to disable tests and avoid the
   **STLSoft** / **xTests** test-only dependencies:

	```bash
	$ ./prepare_cmake.sh -E -T
	```

   (**Hint**: execute `$ ./prepare_cmake.sh --help` for more information.)

3. Run a build of the generated **CMake**-derived build files via the
   **build_cmake.sh** script, as in:

	```bash
	$ ./build_cmake.sh
	```

   (**NOTE**: if you provide the flag `--run-make` (=== `-m`) in step 2 then
   you do not need this step.)

4. Install the library on the host, via `cmake`, as in:

	```bash
	$ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
	```


## Using the library

Include the umbrella header:

```C
#include <sistools/common.h>
```

Specific facilities will be declared under `sistools/common/` as they are
added.

From another **CMake** project:

```cmake
find_package(sistools-common-c REQUIRED)

target_link_libraries(your_target
	PRIVATE
		sistools-common-c::core
)
```


<!-- ########################### end of file ########################### -->
