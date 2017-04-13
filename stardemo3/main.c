#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2 - i; j++)
        {
            printf("%c", ' ');
        }
        for (j = 0; j <= i * 2; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            if (j == 2)
            {
                printf("%c", '*');
            }
            else
            {
                printf("%c", ' ');
            }

        }

        printf("\n");
     }

}
