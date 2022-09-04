![alt text](docs/pics/header.png "Project name")

## Description
---

Sets of various small helper functions useful when developing firmware for microcontrollers.

## Repository structure
---

Folder structure of repository:

```bash
├── README.md
├── src
│   ├── 3rdparty
|   |   ├── json
|   |   |   ├── jfes
|   |   |   ├── jsmn
|   |   ├── regexp
|   |   |   ├── slre
|   |   ├── xprintf
│   ├── atomic
|   |   ├── atomic.h
│   ├── conversion
|   |   ├── conversion.c
|   |   ├── conversion.h
│   ├── crc
|   |   ├── crc.c
|   |   ├── crc.h
│   ├── delay
|   |   ├── delay.h
│   ├── environment
|   |   ├── compiler.h
|   |   ├── constants.h
|   |   ├── host.h
│   ├── macros
|   |   ├── align.h
|   |   ├── arithmetics.h
|   |   ├── bits.h
|   |   ├── cast.h
|   |   ├── guard.h
|   |   ├── utils.h
│   ├── profiler
|   |   ├── profiler.h
└── test
    ├── macros
    |   ├── test_align.h
    |   ├── test_arithmetics.h
    |   ├── test_bits.h
    |   ├── test_utils.h
    ├── test_conversion.c
    └── test_crc.c
    └── test_sfloat.c
```

### Installation
---

Simply add necessary ``c`` and ``h`` to your project, ``#include "xxx.h"``.

### Running unit tests
---

TBD

### License

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the
use of this software.

Permission is granted to anyone to use this software for any purpose, including
commercial applications.
