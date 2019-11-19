# gpio_counter_atmega328p_gcc

Blinky example project for the ATMEGA328P microcontroller with support for 
unit testing with Ceedling. Ceedling is also used to build the release files
and program the microcontroller. To get more details about the available 
commands use:

```bash
ceedling help
```

## Project structure

The project is structured in the following way:

* src: Source code
* test: Tests source code
* vendor: Ceedling files

## Build the project

To build the project, use the following command:

```bash
ceedling test:all release
```

To get the hex file required for programming, use the following command:

```bash
ceedling test:all target:hex
```

To log the commands used by the ceedling commands, put the `logging` option
first. For example:

```bash
ceedling logging test:all release
```

## Load to target

The serial port used to load the hex file to the target is configured in 
project.yml, so you have to first configure it. For exmaple:

```yml
:environment:
  - :mcu: atmega328p
  - :f_cpu: 16000000UL
  - :serial_port: /dev/tty1
  - :objcopy: avr-objcopy
```

Then run the following command from the root directory:

```bash
ceedling target:load
```

## Code coverage report

To get the code coverage report in HTML format use the following command:

```bash
ceedling gcov:all utils:gcov
```