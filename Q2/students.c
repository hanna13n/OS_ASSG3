#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>

struct msg_student
{
    long id;
    float marks;
} stu;

int main()
{
    int msgid;
    key_t key;

    if ((key = ftok(".", 1)) < 0)
    {
        printf("Failed to generate key\n");
        return 1;
    }

    if ((msgid = msgget(key, 0666 | IPC_CREAT)) < 0)
    {
        printf("Failed to get message queue\n");
        return 1;
    }

    int i = 0, pid;

    for (i = 0; i < 4; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            if ((msgrcv(msgid, &stu, sizeof(stu), i + 1, 0)) < 0)
            {
                printf("Failed to receive message\n");
                return 1;
            }
            printf("Student %d scored %.2f marks\n", i + 1, stu.marks);
            return 0;
        }
    }
    if ((msgrcv(msgid, &stu, sizeof(stu), i + 1, 0)) < 0)
    {
        printf("Failed to receive message\n");
        return 1;
    }
    printf("Student %d scored %.2f marks\n", i + 1, stu.marks);

    return 0;
}