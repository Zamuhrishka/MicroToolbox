![alt text](docs/pics/header.png "Project name")

## Description
---

Sets of various small helper functions useful when developing firmware.

## Repository structure
---

Structure of repository:

- [3rdparty](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/3rdparty) - useful 3rdparty libraries
  - [json](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/3rdparty/json) - 3rdparty libraries for work with json
    - [jfes](https://github.com/dmitrii-eremin/jfes) - minimalistic json engine written in plain C
    - [jsmn](https://github.com/zserge/jsmn) - minimalistic JSON parser in C
  - [regexp](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/3rdparty/regexp) - 3rdparty libraries for regular expration
    - [slre](https://github.com/cesanta/slre) - super light regular expression library
  - [xprintf](http://elm-chan.org/fsw/strf/xprintf.html) - embedded string functions
- [atomic](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/atomic) - functions and macros for atomic operations.
- [conversion](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/conversion) - functions different conversion string into num, num into string, bcd into num etc.
- [crc](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/crc) - functions for calculate CRC
- [delay](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/delay) - functions for time delays.
- [environment](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/environment)
  - [compiler.h](https://github.com/Zamuhrishka/FWToolbox/blob/develop/src/environment/compiler.h) - compiler specific function, macros.
  - [constants.h](https://github.com/Zamuhrishka/FWToolbox/blob/develop/src/environment/constants.h) - common constants.
  - [host.h](https://github.com/Zamuhrishka/FWToolbox/blob/develop/src/environment/host.h) - host specific function, macros.
- [macros](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros)
  - [align.h](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/align.h) - macros for align.
  - [arithmetics.h](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/arithmetics.h) - macros for ariphmetic operations.
  - [bits.h](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/bits.h) - bits operation macros.
  - [cast.h](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/cast.h) - macros for different types of cast.
  - [guards.h](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/guards.h) - guards macros.
  - [utils.h](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/utils.h) - other types of macros.
- [types](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/types) - specific and useful types and functions for work with it.

### Installation
---

For installation you need to do 2 simply steps:

- Copy necessary ``c`` and ``h`` to your project
- Add ``#include "xxx.h"`` into your source code.

### Running unit tests
---

![alt text](docs/pics/under_construction.png "under constraction")

### Contributing
---

Bug reports and/or pull requests are welcome.

### License
---

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications.
