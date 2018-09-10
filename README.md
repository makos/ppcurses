# ppcurses

[![Build Status](https://travis-ci.org/makos/ppcurses.svg?branch=master)](https://travis-ci.org/makos/ppcurses)

C++ wrapper library over old ncurses

Readme is WIP, for now see the [changelog](Changelog.md) and [design document](design_draft.md).

## Building
Required:
* CMake `>= 3.0.0`
* gcc `>= 7.0` (tested)
* clang `>= 6.0` (tested)
* On Windows:
  * PDCurses
(I think every Linux distro has ncurses nowadays)


````shell
git clone https://github.com/makos/ppcurses.git
cd ppcurses
mkdir build && cd build
cmake .. && make all
cd build/bin && ./tests
````
Use vim-style (h,j,k,l) controls to move the window.

