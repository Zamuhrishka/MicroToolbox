<img src="https://github.com/Zamuhrishka/FWToolbox/workflows/UnitTests/badge.svg?branch=master">

# MicroToolbox: Small-Scale Aids for Firmware Crafting

<!-- ![alt text](docs/pics/LOGO.png "Firmware Toolbox") -->
<img src="docs/pics/LOGO.png" width="200" height="200">

Sets of various small helper functions useful when developing firmware.

I have been collecting this functions during years of work. Some of it I wrote  by myself others I found somewhere and added into this repository.
Main goal creation of this repository was to make life firmware engineers little bit easier because each firmware engineer know this pain when you need to write
some helpful function by your own hand because you did not find or can`t add necessary library.

So please feel free to use this toolbox and add code to this toolbox if you want. Lets make life of firmware engineers easier!

## Modules

### [Align](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/align)

This module provides utilities for memory alignment in C. It includes macros for aligning variables, structures, and memory addresses to ensure optimal memory access and performance. The module supports both static and dynamic alignment and includes inline functions for checking and adjusting alignment. It is designed to be compiler-independent, making it suitable for various embedded systems and firmware development projects.

### [Conversion](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/conversion)

This module provides a comprehensive suite of functions for data type conversions in embedded systems. It includes functions for converting between different
numerical representations like hexadecimal, BCD, and binary, as well as utilities for converting network data types such as MAC and IP addresses. The module aims to
facilitate data manipulation and interoperability in embedded applications where data often needs to be converted between various formats for communication, storage,
and processing purposes.

### [CRC](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/crc)

This module is dedicated to calculating CRC (Cyclic Redundancy Check) values for data integrity verification in embedded systems. It supports various CRC
standards including CRC-8-Dallas/Maxim, CRC-16-CCITT, and CRC-32-IEEE 802.3, catering to different data checking requirements. The module provides both
direct calculation and table-based methods for CRC computation, ensuring flexibility and efficiency in data validation processes.

### [Delay](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/delay)

This module provides basic timing functions for creating precise microsecond and millisecond delays in embedded systems. It is essential for timing control in various
hardware interfacing and control applications. The functions `delay_us` and `delay_ms` offer microsecond and millisecond resolution respectively, suitable for scenarios
where specific timing is critical. Note that these functions are blocking, meaning they halt the execution of the program for the specified duration of time.

### [Endian](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/endian)

This module provides functions for handling and converting byte order in data for embedded systems. It supports functions to determine the byte order of
the target system, as well as to swap byte order for different data types including 16-bit, 32-bit, and 64-bit numbers. Additionally, the module includes utilities for
storing and loading values in both little-endian and big-endian formats. This is crucial in embedded systems where data interoperability between different architectures
requires correct interpretation of byte order for accurate data processing and communication.

### [Environment](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/environment)

This module seems to centralize configurations and settings that are essential for ensuring compatibility and optimal functioning of the software across different platforms, compilers, and host environments. It provides a foundational layer that other modules can rely on for consistent behavior irrespective of the underlying system or compiler specifics.

#### [Compiler](https://github.com/Zamuhrishka/FWToolbox/blob/develop/src/environment/compiler.h)

This file contains definitions and macros related to compiler-specific functionalities or attributes. These could include inline function directives, deprecated attribute definitions, or other compiler-related utilities.

#### [Constants](https://github.com/Zamuhrishka/FWToolbox/blob/develop/src/environment/constants.h)

This file is expected to define various constants that might be used across the project. These constants could range from numeric values, buffer sizes, or specific flags essential for the system's operation.

#### [Host](https://github.com/Zamuhrishka/FWToolbox/blob/develop/src/environment/host.h)

This file defines constants that depend on the host environment. For example, it might include definitions for different file path splitters based on the operating system (Windows, Linux, Unix, macOS, etc.).

### [Guards](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/guards/guards.h)

This module contains a collection of macros designed for compile-time assertions and structural validations in C. It includes macros for static assertions, guarding the size of structures, ensuring structure sizes are multiples of a specified value, and verifying the offset of structure members. These tools are crucial for ensuring data structure consistency
and memory layout expectations, especially in embedded systems programming where such guarantees are critical for reliable operation. Additionally, it provides a macro for validating the number of entries in an enumeration relative to a maximum count, further enhancing data integrity checks.

### [Macros](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros)

The module appears to be a collection of utility macros facilitating various low-level operations, primarily focused on arithmetic and bit manipulation, essential in embedded system programming.

#### [Arithmetics](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/arithmetics.h)

This file contains arithmetic-related macros, offering utilities for mathematical operations, optimizations, or shorthand functions for complex arithmetic tasks.

#### [Bits](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/bits.h)

This file provides a comprehensive set of macros for bit manipulation. These include operations like setting, clearing, toggling, testing individual bits, creating bit masks, and functions for bit mirroring in various data types (e.g., uint8_t, uint16_t, uint32_t).

#### [Misc](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/misc.h)

This file includes miscellaneous macros that do not fall under the other two categories. These could be utility macros for general-purpose use within the project.

### [Types](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/types)

This module provides a foundation of custom data types tailored for specific requirements in embedded system programming, ranging from network communication to data representation and manipulation.

#### [Sfloat](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/types/sfloat.h)

This file contains definitions or structures to a specific floating-point representation, for more efficient storage or computation in embedded systems.

#### [Types](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/types/types.h)

This file includes a variety of custom data types essential for the project. These types include constants for byte order, structures for MAC addresses, binary string representations for various integer types, IP addresses, and a BCD (Binary-Coded Decimal) data type.


## Enable/Disable Modules




## Documentation

All documentation generated by [Doxygen](https://github.com/doxygen/doxygen) you can find in [docs](https://github.com/Zamuhrishka/FWToolbox/tree/develop/docs) folder.

## Installation

For installation you need to do 2 simply steps:

- Copy necessary ``c`` and ``h`` to your project
- Add ``#include "xxx.h"`` into your source code.

## Unit tests

All unit tests in this project was write by using this [framework](https://github.com/ThrowTheSwitch/Ceedling).
So for run unit tests you need to install this framework using instruction from framework [repository](https://github.com/ThrowTheSwitch/Ceedling).

## Contributing

Bug reports and/or pull requests are welcome.

## Disclaimer

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
