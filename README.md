### During the development of the project, the means of working with System V IPC

#### Part 1 - shared memory

##### Exercise 1

Was developed two programm for working witn shared memory. First is sharedMemory1.c and second is sharedMemory1.c.
Really important file is sharedMemory. Don't forget about it!

The two programs work with a common array of three elements. For each run, they increase their own counter: for the first program, the zero element, for the second, the first element of the array, and the third by 1. The third element of the array is common. They also display information about the current state of the array.

Compile:

    make sharedMemory

or 

    gcc sharedMemory1.c -o sharedMemory1
	gcc sharedMemory2.c -o sharedMemory2
    gcc dlSharedMemory.c -o dlSharedMemory


Launch:
    
    ./sharedMemory1
    ./sharedMemory2
    
Delete shared memory:

    ./dlSharedMemory

##### Exercise 2

Two persistent programs that communicate through shared memory. The first program creates a shared memory segment and copies its own source text there, the second program must take this text, print it on the display and remove the shared memory segment from the system.

Compile:

    make shm2

or 

	gcc shm2a.c -o shm2a
	gcc shm2b.c -o shm2b

Launch:
    
    ./shm2a
    ./shm2b
