# blinky_atmega328p

## Build the project

To build the project use the following command:

```{bash}
ceedling test:all release
```

If you require the commands used for building use the following command:

```{bash}
ceedling logging test:all release
```

## Code coverage report

To get the code coverage report in HTML format use the following command:

```{bash}
ceedling gcov:all utils:gcov
```