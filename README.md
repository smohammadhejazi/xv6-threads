# XV6 Thread implementation
Threads functionality were added to XV6 operating system.

## Changes
Some of the files of the original [XV6 OS](https://github.com/mit-pdos/xv6-public) were changed, and some files were added.

### Makefile
Added the new program _test\ to UPROGS, test.c to EXTRA and also added the new library thread.o to ULIB.

### syscall.h
Number of the new system calls sys_clone, sys_join and the test system call sys_getyear(not used) were added.

### syscall.c
Declared the new system calls.

### usys.s
Added new system calls.

### defs.h
Declaration of the new system calls were added.

### user.h
Declared the new functions clone() and join().

### sysproc.c
sys_clone() and sys_join() were added to this file which call the functions in proc.c

### proc.c
Definition of clone() and join() were added. Also a slight to wait() and growproc() functions to support the new functionality.

### proc.h
Added a new property to proc struct, void *tstack. This pointer points to the stack of the thread.

### thread.h
A new library for creating threads. Holds the declaration of thread_create() and thread_join().

### thread.c
Holds thread_create() and thread_join() definitions.

### test.c
This file contains a few test programs that only one of the should be uncommented.
