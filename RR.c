#include <stdio.h>

int main()
{

    int burst[10];
    int turnout[10];
    int waiting[10];
    int TQ;
    int TP;
    int temp[10];
    int totalturn = 0;
    int pturns[10];
    printf("Enter number of process you want to enter: ");
    scanf("%d", &TP);
    for (int i = 0; i < TP; i++)
    {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &burst[i]);
    }
    printf("Enter time quantum: ");
    scanf("%d", &TQ);
    int td = TP;
    for (int i = 0; i < TP; i++)
    {
        if (burst[i] % TQ != 0)

        {
            temp[i] = -1;
        }

        pturns[i] = burst[i] / TQ;
        totalturn++;
    }
    for (int i = 0; i < 3; i++)
    {
        if (i == 1)
        {
            printf("Gantt Chart");
        }
        else
            printf("-------------------------------------------");
    }
    printf("\n");
    int pcount = 0;
    int counter = 0;
    while (counter != TP)
    {

        if (pturns[pcount] > 0)
        {
            printf("|P%d|", pcount + 1);

            burst[pcount] -= TQ;
            for (int i = 0; i < TQ; i++)
            {
                printf("-");
            }
            pturns[pcount]--;
        }
        else if (burst[pcount] < TQ && burst[pcount] != 0)
        {
            printf("|P%d|", pcount + 1);
            for (int s = 0; s < burst[pcount]; s++)
            {
                printf("-");
            }
            counter++;
            burst[pcount] = 0;
        }

        pcount = (pcount + 1) % TP;
    }
    return 0;
}