#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

int main()
{
    const char pathname[] = "sem";
    const int proj_id = 1;
    key_t key;

    int semid;
    struct sembuf sembuf;

    if ((key = ftok(pathname, proj_id)) == -1)
    {
        perror("Error: Can't create key (ftok)");
        return 1;
    }

    if ((semid = semget(key, 1, 0)) == -1)
    {
        perror("Error: Can't find semaphore");
        return 3;
    }

    if (semctl(semid, 1, IPC_RMID) == -1)
    {
        perror("Error: Can't delete semaphore");
        return 4;
    }

    return 0;
}