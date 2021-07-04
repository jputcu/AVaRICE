# AVaRICE

## Description

Application to debug AVR, 8-bit MCUs, by controlling a `JTAG` and providing a `gdbserver`.
It is a clone from [AVaRICE](https://sourceforge.net/projects/avarice/).

The ambition of this clone is **to get a working, cross-platform, debugging tool for AVR**.
Currently it is relying on some POSIX specific API.

## How it was born

~~~~
git svn clone https://svn.code.sf.net/p/avarice/code/trunk/avarice avarice
~~~~

## Dependencies

* [libusb](https://github.com/libusb/libusb)
* [hidapi](https://github.com/libusb/hidapi)

