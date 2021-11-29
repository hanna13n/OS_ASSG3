#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/shm.h>
#include <wait.h>
#include <stdio.h>
#include <string.h>

#define PLEN 10

typedef struct password
{
    char p[PLEN];
    int a, s;
    char strength[7];
} password;

int main()
{

    int shmid;
    key_t key;
    password *pword;

    if ((key = ftok(".", 1)) < 0)
    {
        printf("Failed to generate key\n");
        return 1;
    }

    if ((shmid = shmget(key, sizeof(password), IPC_CREAT | 0666)) < 0)
    {
        printf("Failed to get shared memory\n");
        return 1;
    }

    if ((pword = (password *)shmat(shmid, NULL, 0)) == (void *)-1)
    {
        printf("Failed to attach shared memory\n");
        return 1;
    }

    int i;
    for (i = 0; i < PLEN; i++)
    {
        scanf("%c", &pword->p[i]);
    }
    pword->a = 0;
    pword->s = 0;

    int pid1 = fork();
    if (pid1 == 0)
    {
        for (i = 0; i < PLEN; i++)
        {
            if ((pword->p[i] >= 'a' && pword->p[i] <= 'z') || (pword->p[i] >= 'A' && pword->p[i] <= 'Z') || (pword->p[i] >= '0' && pword->p[i] <= '9'))
            {
                pword->a++;
            }
            else
            {
                pword->s++;
            }
        }

        int pid2 = fork();
        if (pid2 == 0)
        {
            if (pword->a < pword->s)
            {
                strcpy(pword->strength, "Strong");
            }
            else
            {
                strcpy(pword->strength, "Weak");
            }
        }
        else
        {
            wait(NULL);
        }
    }
    else
    {
        wait(NULL);
        printf("%s\n", pword->strength);
    }

    return 0;
}
