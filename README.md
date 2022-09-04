![alt text](docs/pics/header.png "Project name")

## Description
---

Sets of various small helper functions useful when developing firmware for microcontrollers.

## Repository structure
---

Folder structure of repository:

- **3rdparty** - useful 3rdparty libraries
  - **json** - 3rdparty libraries for work with json
    - [jfes](https://github.com/dmitrii-eremin/jfes)
    - [jsmn](https://github.com/zserge/jsmn)
  - **regexp** - 3rdparty libraries for regular expration
    - [slre](https://github.com/cesanta/slre)
- **atomic** - functions and macros for atomic operations.
- **conversion** - functions different conversion string into num, num into string, bcd into num etc.
- **crc** - functions for calculate CRC
- **dalay** - functions for time delays.
- **environment** - .
  - **compiler.h** - compiler specific function, macros.
  - **constants.h** - common constants.
  - **host.h** - host specific function, macros.
- **macros** - .
  - **align.h** - macros for align.
  - **arithmetics.h** - macros for ariphmetic operations.
  - **bits.h** - bits operation macros.
  - **cast.h** - macros for different types of cast.
  - **guards.h** - guards macros.
  - **utils.h** - other types of macros.
- **types** - specific and useful types and functions for work with it.




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
