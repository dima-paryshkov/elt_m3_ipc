### During the development of the project, the means of working with System V IPC

#### Part 1 - shared memory

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
    