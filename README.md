# sistools-common-c <!-- omit in toc -->

Common C helper functions and utilities shared across **sistools** programs.


![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/sistools/sistools-common-c.svg)](https://github.com/sistools/sistools-common-c/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/sistools/sistools-common-c)](https://github.com/sistools/sistools-common-c/commits/master)
[![CI](https://github.com/sistools/sistools-common-c/actions/workflows/ci.yml/badge.svg)](https://github.com/sistools/sistools-common-c/actions/workflows/ci.yml)


## Introduction

**sistools-common-c** is a small C library of helper functions and utilities intended for reuse by the various **sistools** command-line programs.


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Installation](#installation)
- [Components](#components)
	- [Constants](#constants)
	- [Enumerations](#enumerations)
	- [Features](#features)
	- [Functions](#functions)
	- [Macros](#macros)
	- [Structures](#structures)
	- [(Simple) Types](#simple-types)
- [Examples](#examples)
- [Project Information](#project-information)
	- [Where to get help](#where-to-get-help)
	- [Contribution guidelines](#contribution-guidelines)
	- [Dependencies](#dependencies)
		- [Development/Testing Dependencies](#developmenttesting-dependencies)
	- [Related projects](#related-projects)
	- [License](#license)


## Installation

**CMake** configuration files are provided, along with helper scripts. Detailed
instructions are in [INSTALL.md](./INSTALL.md).

A minimal build/installation:

1. Perform the CMake configuration

	```bash
	export SIS_CMAKE_BUILD_DIR=/tmp/sis/sistools-common-c
	./prepare_cmake.sh -E -T
	```

2. Build the library

	```bash
	./build_cmake.sh
	```

3. Install

	```bash
	sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release | grep -i -v up-to-date
	```

Consumers include the umbrella header as `#include <sistools/common.h>` and
link **`sistools-common-c::core`**.



## Components


### Constants

No public constants are defined at this time.


### Enumerations

No public enumerations are defined at this time.


### Features

No public library-specific features are defined at this time.


### Functions

The following public functions are defined in the current version:

```C
/** Obtains the sistools-common-c version (at time of compilation). */
stcc_uint32_t
stcc_api_version(void);
```


### Macros

The following public macros are defined in the current version:

* `STCC_VER_MAJOR`, `STCC_VER_MINOR`, `STCC_VER_PATCH`, `STCC_VER_ALPHABETA`, `STCC_VER`;
* `STCC_CALL`, `STCC_NOEXCEPT`;


### Structures

No public structures are defined at this time.


### (Simple) Types

The following public types are defined in the current version:

```C
typedef uint32_t stcc_uint32_t;
```


## Examples

No examples are defined at this time. When present, they will live under the
`examples` directory and be indexed in [EXAMPLES.md](./EXAMPLES.md).


## Project Information


### Where to get help

[GitHub Page](https://github.com/sistools/sistools-common-c "GitHub Page")


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on [the **sistools-common-c** GitHub page](https://github.com/sistools/sistools-common-c).


### Dependencies

* [**Diagnosticism**](https://github.com/synesissoftware/Diagnosticism);


#### Development/Testing Dependencies

For unit-testing, **sistools-common-c** depends additionally on:

* [**STLSoft**](https://github.com/synesissoftware/STLSoft);
* [**xTests**](https://github.com/synesissoftware/xTests);


### Related projects

**sistools** programs that are intended to consume this library include:

* [**chomp**](https://github.com/sistools/chomp);
* [**errni**](https://github.com/sistools/errni);
* [**lnunique**](https://github.com/sistools/lnunique);
* [**lstrip**](https://github.com/sistools/lstrip);
* [**mksock**](https://github.com/sistools/mksock);
* [**realpath**](https://github.com/sistools/realpath);
* [**rstrip**](https://github.com/sistools/rstrip);


### License

**sistools-common-c** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->
