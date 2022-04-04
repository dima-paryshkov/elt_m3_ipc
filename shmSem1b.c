#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <errno.h>
#include <stdbool.h>

int main()
{
    const char pathnameSem[] = "sem";
    const int proj_id = 3;
    key_t keySem;

    int semid;
    struct sembuf sembuf;

    const char pathnameShm[] = "sharedMemory_1";
    key_t keyShm;
    int *array;

    int shmid;

    bool new = true;

    if ((keySem = ftok(pathnameSem, proj_id)) == -1)
    {
        perror("Error: Can't create key for semaphore");
        return 1;
    }

    if ((semid = semget(keySem, 1, IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        if (errno == EEXIST)
        {
            if ((semid = semget(keySem, 1, 0)) == -1)
            {
                perror("Error: Can't get semaphore");
                return 2;
            }
        }
        else
        {
            perror("Error: Can't create semaphore");
            return 3;
        }
    }

    sembuf.sem_num = 0;
    sembuf.sem_op = 1;
    sembuf.sem_flg = 0;

    if (semop(semid, &sembuf, 1) == -1)
    {
        perror("Error: Can't execute operation A(0, 1) for semaphore");
        return 4;
    }

    if ((keyShm = ftok(pathnameShm, proj_id)) == -1)
    {
        perror("Error: Can't create key for shared memory");
        return 5;
    }

    if ((shmid = shmget(keyShm, 3 * sizeof(int), IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        if (errno == EEXIST)
        {
            if ((shmid = shmget(keyShm, 3 * sizeof(int), 0)) == -1)
            {
                perror("Error: Can't find shared mamory");
                return 6;
            }
            new = false;
        }
        else
        {
            perror("Error: Can't create chared memory");
            return 7;
        }
    }

    if ((int*)(array = (int*)shmat(shmid, NULL, 0)) == (int*)(-1))
    {
        perror("Error: Can't attach shared memory");
        return 7;
    }

    if (new)
    {
        array[0] = 0;
        array[1] = 1;
        array[2] = 1;
    }
    else
    {
        array[1]++;
        array[2]++;
    }

    fprintf(stdout, "P2: program 1 was spawn %d times, program 2 - %d times, total - %d times\n", array[0], array[1], array[2]);

    sembuf.sem_op = 1;

    if (semop(semid, &sembuf, 1) == -1)
    {
        perror("Error: Can't execute operation P(0, 1) for semaphore");
        return 8;
    }

    if (shmdt((void*)array) == -1)
    {
        perror("Error: Can't detach shared memory");
        return 9;
    }

    return 0;
}