#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdio.h>

struct msg_student
{
    long id;
    float marks;
} stu[5];

struct msg_ta
{
    long type;
    float avg;
    char grades[5];
} ta;

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

    ta.avg = 0;
    for (int i = 0; i < 5; i++)
    {
        if (msgrcv(msgid, &stu[i], sizeof(stu[i]), i + 1, 0) < 0)
        {
            printf("Failed to receive message\n");
            return 1;
        }
        ta.avg += stu[i].marks;
        if (stu[i].marks >= 40)
            ta.grades[i] = 'S';
        else if (stu[i].marks >= 30)
            ta.grades[i] = 'A';
        else if (stu[i].marks >= 20)
            ta.grades[i] = 'B';
        else
            ta.grades[i] = 'E';
    }

    ta.avg /= 5;
    ta.type = 10;

    if (msgsnd(msgid, &ta, sizeof(ta), 0) < 0)
    {
        printf("Failed to send message\n");
    }

    return 0;
}