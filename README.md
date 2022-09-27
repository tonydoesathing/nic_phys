# nic_phys
The physical layer for the Block 2 2022 CP341 class at Colorado College.

## Introduction
This C project establishes the physical layer for the custom CP341 network.
- `nic_phys.c` is the physical layer module that should be imported to provide direct access to the NIC io.
- `nic_phys.h` is the header file for the module
- `cli_test.c` is an example CLI that makes use of the module to interactively send and receive to the different ports.

## Building and Running
Keeping with the standards of the class, this code should be built and run on a Raspberry Pi 3B+ with [pigpio](https://abyz.me.uk/rpi/pigpio/index.html) installed. 
To build the CLI, run `gcc -pthread -o cli-test cli_test.c nic_phys.c -lpigpiod_if2 -lrt`.
To run the CLI, then call `cli-test`.

## Authors
The following code was written by [Jessica Hannebert](https://github.com/Jessicat-H), [Dylan Chappell](https://github.com/dylanchapell), and [Tony Mastromarino](https://github.com/tonydoesathing).
