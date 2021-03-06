# Ansi-Escape  ![GitHub](https://img.shields.io/github/license/hsuantinglu/ansi-escape) ![GitHub release (latest SemVer including pre-releases)](https://img.shields.io/github/v/release/HsuanTingLu/ansi-escape?include_prereleases)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/HsuanTingLu/ansi-escape)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/18170c1dd8f746328ac668d5fdfbb5c2)](https://www.codacy.com/manual/HsuanTingLu/ansi-escape?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=HsuanTingLu/ansi-escape&amp;utm_campaign=Badge_Grade)

ANSI escape codes wrapped in C++ string streams.

It's everything you need for advanced terminal control, wrapped in light headers ready for inclusion.

## Table of Contents

- [About Ansi-Escape](#about)
- [Quickstart](#quickstart)
- [Install](#install)
- [Links](#links)

<a name="about"></a>
## About Ansi-Escape
`Ansi-Escape`, or `AESC`, is an effort to wrap common terminal controls and colors for prettier terminal output.
It is built and tested on macOS, but probably will work in other \*NIX systems as well.

To maximize compatibility, we choose to support C++11, with CMake-3.9 as a build dependency.

<a name="quickstart"></a>
## Quickstart

`AESC` implemented most ANSI escape sequences, including text coloring and cursor controlling

there are example codes in the examples/ directory, see [Install](#install) for more information.

Find detailed list of available APIs at [docs](aesc/README.md) and [wikipedia](https://en.wikipedia.org/wiki/ANSI_escape_code)

### Simple example of text coloring

```cpp
#include <iostream>
#include "aesc.hpp"
using namespace std;
using aesc::color;

int main() {
    cout << red << " foreground is red" << endl;

    cout << bright::red << bright::background::cyan
         << " background bright cyan, foreground bright red" << endl;

    cout << aesc::color256::RGB::foreground(2, 3, 0) << "256 color RGB test sequence"
         << endl;

    cout << aesc::truecolor::RGB::foreground(130, 250, 0)
         << "24-bit true color RGB test sequence" << aesc::render::reset << endl;
}
```

### Simple example of cursor control

See the provided example at [examples/show_color.cpp](examples/show_color.cpp)

<a name="install"></a>
## Install

Install it with [Homebrew](https://brew.sh), or build it using [CMake](https://cmake.org)

### Install with Homebrew

```bash
brew tap hsuantinglu/utils
brew install ansi-escape
```

### Build with CMake

CMake is the official build system. At least version 3.9 is needed.

```bash
mkdir build; cd build/

# Config and build
cmake .. && make showcolor

# execute example
./examples/showcolor
```
