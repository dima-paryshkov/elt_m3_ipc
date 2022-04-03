#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <errno.h>

int main()
{
    const char pathname[] = "sharedMemory_1";
    const int proj_id = 2;
    key_t key;

    const int size = 2000;
    char *array;
    int shmid;

    if ((key = ftok(pathname, proj_id)) == -1)
    {
        perror("Error: Can't create key");
        return 1;
    }

    if ((shmid = shmget(key, size * sizeof(char), 0)) == -1)
    {
        perror("Error: Can't find shared memory");
        return 2;
    }

    if ((array = (char *)shmat(shmid, NULL, 0)) == (char *)(-1))
    {
        perror("Error: Can't attach shared memory");
        return 3;
    }

    fprintf(stdout, "%s\n", array);

    if (shmdt((void *)array) == -1)
    {
        perror("Error: Can't detach shared memory");
        return 4;
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("Error: Can't find chared memory");
        return 5;
    }

    return 0;
}