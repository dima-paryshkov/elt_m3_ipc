sharedMemory: sharedMemory1.c sharedMemory2.c
	gcc sharedMemory1.c -o sharedMemory1
	gcc sharedMemory2.c -o sharedMemory2

sharedMemory1: sharedMemory1.c
	gcc sharedMemory1.c -o sharedMemory1

sharedMemory2: sharedMemory2.c
	gcc sharedMemory2.c -o sharedMemory2

