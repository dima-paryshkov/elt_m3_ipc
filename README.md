### During the development of the project, the means of working with System V IPC

#### Part 1

Was developed two programm for working witn shared memory. First is sharedMemory1.c and second is sharedMemory1.c.
Really important file is sharedMemory. Don't forget about it!

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
    