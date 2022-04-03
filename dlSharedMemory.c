#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <stdbool.h>

int main()
{
    const char pathname[] = "sharedMemory_1";
    const int proj_id = 1;
    key_t key;

    int *array;
    const int size = 3;
    int shmid;

    bool new = true;

    if ((key = ftok(pathname, proj_id)) == -1)
    {
        perror("Error: Can't create key");
        return 1;
    }

    if ((shmid = shmget(key, size * sizeof(int), 0)) == -1)
    {
        perror("Error: Can't find chared memory");
        return 2;
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("Error: Can't find chared memory");
        return 3;
    }

    return 0;
}