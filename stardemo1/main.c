#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (j == 0 || j == 8 || i == 0 || i == 8)
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
