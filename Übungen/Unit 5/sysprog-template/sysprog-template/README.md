# Template for "Systemnahe Programmierung"

This repository contains a default directory structure and a generic Makefile for writing C-programs.



<u>Directories:</u>

`./src` ... contains all C-source files (.c)

`./include` ... contains all Header files (.h)

`./bin` ... executables

`./build` ... object files 

`./test` ... test scripts



`Makefile` ... universal makefile to build your programs



<u>How to customize:</u>

You can adjust the following variables in the Makefile:

- To specify arguments to your executable for "make run", specify them in the variable `RUN_ARGUMENTS`.
- To set a specific root directory alter the variable `PROJECT_ROOT `accordingly.
- To change the name of the executable, adjust the variable `TARGET_NAME` :
  	`TARGET_NAME := name you want`



<u>Usage:</u>

Build project

```sh
make 
```

Build and run project

```sh
make run
```

Run tests (this executes the runTests.sh scipt in the test directory.)

```sh
make test
```

Lint source files

```sh
make lint
```

Analyze executable with valgrind

```sh
make valgrind
```

Cleanup

```sh
make clean
```





