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

    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%f", &stu[i].marks);
        stu[i].id = i + 1;

        if (msgsnd(msgid, &stu[i], sizeof(stu[i]), 0) < 0)
        {
            printf("Failed to send message\n");
            return 1;
        }

        if (msgsnd(msgid, &stu[i], sizeof(stu[i]), 0) < 0)
        {
            printf("Failed to send message\n");
            return 1;
        }
    }

    if (msgrcv(msgid, &ta, sizeof(ta), 10, 0) < 0)
    {
        printf("Failed to receive message\n");
        return 1;
    }

    printf("Average marks: %f\n\n", ta.avg);
    printf("Grades\n");
    for (i = 0; i < 5; i++)
    {
        printf("Student %d: %c\n", i + 1, ta.grades[i]);
    }
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
