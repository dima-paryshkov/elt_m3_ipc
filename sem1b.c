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

    if ((semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        if (errno == EEXIST)
        {
            if ((semid = semget(key, 1, 0)) == -1)
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
        perror("Error: Can't execute semaphore operation: A(0, 1)");
        return 4;
    }

    return 0;
}