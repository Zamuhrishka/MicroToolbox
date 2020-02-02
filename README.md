# fwToolbox
> Firmware Toolbox

This project contains various small helper functions useful when developing
firmware for microcontrollers.

# Project content
- convert.[ch] - functions for different types of string transformations
into another data types.


## Installing

Simply add necessary ``c`` and ``h`` to your project, ``#include "xxx.h"``.

## Running unit tests

Building and running the tests requires the following:

* install the cmockery framework (https://github.com/google/cmockery).
* integrate files in folder **tests** in your project and run it.

## Bugs

There are plenty. Report them on GitHub, or - even better - open a pull request.
Please write unit tests for any new functions you add.

## Contribute

Fresh contributions are always welcome. Simple instructions to proceed::

1. Fork Github repository
2. Respect [C style & coding rules](https://github.com/Zamuhrishka/c-code-style) used by the library
3. Create a pull request to develop branch with new features or bug fixes

## License

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the
use of this software.

Permission is granted to anyone to use this software for any purpose, including
commercial applications.
