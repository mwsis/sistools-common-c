# sistools-common-c {#mainpage}

**sistools-common-c** is a small C library of helper functions and utilities intended for reuse by the various **sistools** command-line programs.


## Components

| Unit | File(s) | Summary |
| ---- | ------- | ------- |
| Public umbrella API | `include/sistools/common.h` | Version macros, `stcc_uint32_t`, and `stcc_api_version()` |
| Usage helpers | `include/sistools/common/usage.h`, `src/usage.c` | `stcc_show_version()`, `stcc_show_help()` |


## Quick start

```C
#include <sistools/common.h>

stcc_uint32_t const v = stcc_api_version();
```

From **CMake**:

```cmake
find_package(sistools-common-c REQUIRED)

target_link_libraries(your_target
	PRIVATE
		sistools-common-c::core
)
```

Build and install instructions are in [INSTALL.md](https://github.com/sistools/sistools-common-c/blob/master/INSTALL.md).


## Related projects

* [chomp](https://github.com/sistools/chomp)
* [errni](https://github.com/sistools/errni)
* [lnunique](https://github.com/sistools/lnunique)
* [lstrip](https://github.com/sistools/lstrip)
* [mksock](https://github.com/sistools/mksock)
* [realpath](https://github.com/sistools/realpath)
* [rstrip](https://github.com/sistools/rstrip)


<!-- ########################### end of file ########################### -->
