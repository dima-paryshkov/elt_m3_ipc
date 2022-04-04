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

    const char pathnameShm[] = "sharedMemory_1";
    key_t keyShm;

    int shmid;

    if ((keySem = ftok(pathnameSem, proj_id)) == -1)
    {
        perror("Error: Can't create key for semaphore");
        return 1;
    }

    if ((semid = semget(keySem, 1, 0)) == -1)
    {
        perror("Error: Can't get semaphore");
        return 2;
    }

    if (semctl(semid, 1, IPC_RMID) == -1)
    {
        perror("Error: Can't delete semaphore");
        return 3;
    }

    if ((keyShm = ftok(pathnameShm, proj_id)) == -1)
    {
        perror("Error: Can't create key for shared memory");
        return 4;
    }

    if ((shmid = shmget(keyShm, 3 * sizeof(int), 0)) == -1)
    {
        perror("Error: Can't find shared mamory");
        return 5;
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("Error: Can't delete shared memory");
        return 6;
    }

    return 0;
}