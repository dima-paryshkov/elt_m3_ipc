#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <errno.h>
#include <stdbool.h>

int main()
{
    const char pathname[] = "sharedMemory_1";
    const int proj_id = 1;
    key_t key;

    const int size = 3;
    int *array;
    int shmid;

    bool new = true;

    if ((key = ftok(pathname, proj_id)) == -1)
    {
        perror("Can't create key");
        return 1;
    }

    if ((shmid = shmget(key, size * sizeof(int), IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        if (errno != EEXIST)
        {
            perror("Can't create chared memory");
            return 2;
        }
        else
        {
            if ((shmid = shmget(key, size * sizeof(int), 0)) == -1)
            {
                perror("Can't find chared memory");
                return 3;
            }
            new = false;
        }
    }

    if ((array = (int*)shmat(shmid, NULL, 0)) == (int*)(-1))
    {
        perror("Can't attach shared memory");
        return 4;
    }

    if (new)
    {
        array[0] = 1;
        array[1] = 0;
        array[2] = 1;
    }
    else
    {
        array[0]++;
        array[2]++;
    }

    fprintf(stdout, "P2: program 1 was spawn %d times, program 2 - %d times, total - %d times\n", array[0], array[1], array[2]);

    if (shmdt((void*)array) == -1)
    {
        perror("Can't ");
        return 5;
    }

    return 0;
}