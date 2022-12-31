/**
@mainpage Firmware Toolbox

Sets of various small helper functions useful when developing firmware.

I have been collecting this functions during years of work. Some of it I wrote  by myself others I found somewhere and added into this repository.
Main goal creation of this repository was to make life firmware engineers little bit easier because each firmware engineer know this pain when you need to write
some helpful function by your own hand because you did not find or can`t add necessary library.

So please feel free to use this toolbox and add code to this toolbox if you want.


Structure:

- [align](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/align) - functions and macros which used for data align.
- [conversion](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/conversion) - functions which used for conversion different data type to each other.
- [crc](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/crc) - functions for calculate CRC.
- [delay](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/delay) - functions for time delays.
- [endian](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/endian) - functions which use for work with different byte endian order.
- [environment](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/environment)
  - [compiler.h](https://github.com/Zamuhrishka/FWToolbox/blob/develop/src/environment/compiler.h) - compiler abstraction layer.
  - [constants.h](https://github.com/Zamuhrishka/FWToolbox/blob/develop/src/environment/constants.h) - common constants.
  - [host.h](https://github.com/Zamuhrishka/FWToolbox/blob/develop/src/environment/host.h) - host specific function and macros.
- [macros](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros)
  - [arithmetics.h](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/arithmetics.h) - macros for arithmetics operations.
  - [bits.h](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/bits.h) - bits operation macros.
  - [guards.h](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/guards.h) - guards macros.
  - [misc.h](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/macros/misc.h) - various useful macros.
- [types](https://github.com/Zamuhrishka/FWToolbox/tree/develop/src/types) - specific and useful types and functions for work with it.


*/