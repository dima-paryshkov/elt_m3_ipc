#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>

int main()
{
    const char pathname[] = "sharedMemory_1";
    const int proj_id = 2;
    key_t key;

    const int size = 2000;
    char *array;
    int shmid;

    FILE* fd;
    const char filename[] = "shm2a.c";

    if ((key = ftok(pathname, proj_id)) == -1)
    {
        perror("Error: Can't create key");
        return 1;
    }

    if ((shmid = shmget(key, size * sizeof(char), IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        perror("Error: Can't create shared memory");
        return 2;
    }

    if ((int*)(array = (char *)shmat(shmid, NULL, 0)) == (int *)(-1))
    {
        perror("Error: Can't attach shared memory");
        return 3;
    }

    if ((fd = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s: \n", strerror(errno));
        return 4;
    }

    int err_code;
    if ((err_code = fread((void*)array, size * sizeof(char), 1, fd)) == -1)
    {
        perror("Error: Can't read from file or write in shared memory");
        return 5;
    }

    if (shmdt((void *)array) == -1)
    {
        perror("Error: Can't detach shared memory");
        return 6;
    }

    return 0;
}