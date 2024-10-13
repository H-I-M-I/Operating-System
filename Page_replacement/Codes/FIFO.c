#include <stdio.h>
#include <conio.h>

int i, j, nof, nor, flag = 0, ref[50], frm[50], pf = 0, victim = -1;

void main()
{
    //clrscr();
    printf("\n \t\t\t FIF0 PAGE REPLACEMENT ALGORITHM");
    printf("\nEnter no. of Frames: ");
    scanf("%d", &nof);
    printf("Enter total no. of Pages: ");
    scanf("%d", &nor);

    printf("\nEnter the Page Nunmbers:\n");
    for (i = 0; i < nor; i++)
        scanf("%d", &ref[i]);

    printf("\nThe given Pages are:");
    for (i = 0; i < nor; i++)
        printf("%4d", ref[i]);

    for (i = 1; i <= nof; i++)
        frm[i] = -1;
    printf("\n");

    for (i = 0; i < nor; i++)
    {
        flag = 0;
        printf("\n\t page no %d->\t", ref[i]);

        for (j = 0; j < nof; j++)
        {
            if (frm[j] == ref[i])
            {
                flag = 1;
                //break;
                printf("      Hit");
            }
        }

        if (flag == 0)
        {
            pf++;
            victim++;
            victim = victim % nof;
            frm[victim] = ref[i];

            for (j = 0; j < nof; j++)
                printf("%4d", frm[j]);
        }
    }

    printf("\n\nNo.of pages faults: %d", pf);
    printf("\nNo.of Hits: %d", nor-pf);
    getch();
}
