#include <stdio.h>

int safe_state_seq(int n, int m, int avail[], int need[n][m], int alloc[n][m], int safe_seq[])
{
    int temp[m];
    for (int i = 0; i < m; i++)
        temp[i] = avail[i];

    int f[n];
    for (int i = 0; i < n; i++)
        f[i] = 0;

    int c = 0;
    while (c < n)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > temp[j])
                        break;
                if (j == m)
                {
                    safe_seq[c++] = i;
                    for (int k = 0; k < m; k++)
                        temp[k] += alloc[i][k];

                    f[i] = 1;
                    flag = 1;
                }
            }
        }
        if (flag == 0)
            return 0;
    }
    return 1;
}

int is_safe(int n, int m, int avail[], int need[n][m], int alloc[n][m], int seq[])
{
    int temp[m];
    for (int i = 0; i < m; i++)
        temp[i] = avail[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (need[seq[i]][j] > temp[j])
                return 0;

        for (int k = 0; k < m; k++)
            temp[k] += alloc[seq[i]][k];
    }
    return 1;
}

int can_grant(int n, int m, int avail[], int need[n][m], int alloc[n][m], int p, int req[])
{
    for (int i = 0; i < m; i++)
        if (req[i] > need[p][i] || req[i] > avail[i])
            return 0;

    for (int i = 0; i < m; i++)
    {
        avail[i] -= req[i];
        alloc[p][i] += req[i];
        need[p][i] -= req[i];
    }
    int seq[n];
    int r = is_safe(n, m, avail, need, alloc, seq);
    for (int i = 0; i < m; i++)
    {
        avail[i] += req[i];
        alloc[p][i] -= req[i];
        need[p][i] += req[i];
    }
    return r;
}

int main()
{
    int n, m;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    printf("Enter the number of Resources: ");
    scanf("%d", &m);

    int alloc[n][m];
    int max[n][m];
    int total_avail[m];
    int avail[m];
    int need[n][m];

    printf("Enter the Allocation Table:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the Max Table:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the Total Available Instances per Resource:\n");

    for (int i = 0; i < m; i++)
        scanf("%d", &total_avail[i]);

    for (int i = 0; i < m; i++)
    {
        avail[i] = total_avail[i];
        for (int j = 0; j < n; j++)
        {
            avail[i] -= alloc[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    char c;
    int seq[n], req[m];

    printf("\n\na.Print the SAFE STATE Sequence\nb.Check if the sequence is in SAFE STATE\nc.Check if request can be granted\nd.Exit\n");

menu:

    printf("\n\nEnter your choice:\n");
    scanf("%c\n", &c);

    switch (c)
    {
    case 'a':

        if (safe_state_seq(n, m, avail, need, alloc, seq))
        {
            printf("\nThe SAFE STATE sequence is:\n");
            for (int i = 0; i < n; i++)
                printf("%d ", seq[i]);
        }
        else
            printf("\nThe system does't have a safe sequence.\n");
        break;

    case 'b':
        printf("\nEnter the sequence:\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &seq[i]);
        if (is_safe(n, m, avail, need, alloc, seq))
            printf("\nThe sequence is in SAFE STATE.\n");
        else
            printf("\nThe sequence is not in SAFE STATE.\n");
        break;

    case 'c':
        printf("\nEnter the Process of request:\n");
        int p;
        scanf("%d", &p);
        printf("\nEnter the Resource of request:\n");
        for (int i = 0; i < m; i++)
            scanf("%d", &req[i]);
        if (can_grant(n, m, avail, need, alloc, p, req))
            printf("\nThe request can be granted.\n");
        else
            printf("\nThe request cannot be granted.\n");
        break;
    case 'd':
        return 0;
    }
    goto menu;
}