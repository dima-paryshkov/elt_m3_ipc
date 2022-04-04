sharedMemory: sharedMemory1.c sharedMemory2.c
	gcc sharedMemory1.c -o sharedMemory1
	gcc sharedMemory2.c -o sharedMemory2
	gcc dlSharedMemory.c -o dlSharedMemory

sharedMemory1: sharedMemory1.c
	gcc sharedMemory1.c -o sharedMemory1

sharedMemory2: sharedMemory2.c
	gcc sharedMemory2.c -o sharedMemory2

dlSharedMemory: dlSharedMemory.c
	gcc dlSharedMemory.c -o dlSharedMemory

shm2: shm2a.c shm2b.c
	gcc shm2a.c -o shm2a
	gcc shm2b.c -o shm2b

shm2a: shm2a.c
	gcc shm2a.c -o shm2a

shm2b: shm2b.c
	gcc shm2b.c -o shm2b

sem1: sem1a.c sem1b.c sem1dl.c
	gcc sem1a.c -o sem1a
	gcc sem1b.c -o sem1b
	gcc sem1dl.c -o sem1dl

sem1a: sem1a.c
	gcc sem1a.c -o sem1a

sem1b: sem1b.c
	gcc sem1b.c -o sem1b

sem1dl: sem1dl.c
	gcc sem1dl.c -o sem1dl

shmSem1: shmSem1a.c shmSem1b.c shmSem1dl.c
	gcc shmSem1a.c -o shmSem1a
	gcc shmSem1b.c -o shmSem1b
	gcc shmSem1dl.c -o shmSem1dl

shmSem1a: shmSem1a.c
	gcc shmSem1a.c -o shmSem1a

shmSem1b: shmSem1b.c
	gcc shmSem1b.c -o shmSem1b

shmSem1dl: shmSem1dl.c
	gcc shmSem1dl.c -o shmSem1dl

