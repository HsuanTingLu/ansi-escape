# Ansi-Escape  ![GitHub](https://img.shields.io/github/license/hsuantinglu/ansi-escape) ![GitHub release (latest SemVer including pre-releases)](https://img.shields.io/github/v/release/HsuanTingLu/ansi-escape?include_prereleases)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/HsuanTingLu/ansi-escape)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/18170c1dd8f746328ac668d5fdfbb5c2)](https://www.codacy.com/manual/HsuanTingLu/ansi-escape?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=HsuanTingLu/ansi-escape&amp;utm_campaign=Badge_Grade)

ANSI escape codes wrapped in C++ string streams.

It's everything you need for advanced terminal control, wrapped in light headers ready for inclusion.

## Table of Contents

- [About Ansi-Escape \(aesc\)](#about)
- [Quickstart](#quickstart)
- [Building AESC](#build)
- [Codemap](#codemap)
- [License](#license)
- [Links](#links)

<a name="about"></a>
## About Ansi-Escape \(aesc\)
`AESC` is an effort to wrap common terminal controls and colors for prettier terminal output.
It is built and tested on macOS, but probably will work in other \*NIX systems as well.

To maximize compatibility, we choose to support C++11, with CMake-3.5 as an dependency.

<a name="quickstart"></a>
## Quickstart

Use it as a [CMake](https://cmake.org) package, or simply install it with [Homebrew](https://brew.sh)

### Install with Homebrew

```Shell
brew tap hsuantinglu/utils
brew install ansi-escape
```

### Include as a CMake package

exposes all APIs as within a single library

<a name="build"></a>
## Building AESC
[Buck](https://buck.build) is the official build system, which is supported on most major platforms and compilers. See [quickstart](#quickstart) for more information on building Abseil using the Buck build system.

If you require CMake support, please check the [CMake build instructions](CMake/README.md).

<a name="codemap"></a>
## Codemap

- [aesc](aesc/README.md):
    - [csi](aesc/csi.hpp)

<a name="license"></a>
## License
AESC is licensed under the terms of the . See [LICENSE](LICENSE) for more information.

<a name="links"</a>
## Links
Projects that use Ansi-Escape
- [cpp-logger](https://github.com/AlexFxw/cpp-logger)
