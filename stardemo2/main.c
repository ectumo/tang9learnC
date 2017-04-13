#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j <= 1 - i; j++)
        {
          printf(" ");
        }
        for (j = 0; j <= 2 * i + 2; j++ )
        {
          if (j == 0 || j == 2 * i + 2 || i == 0)
          {
              printf("*");
          }
          else
          {
              printf(" ");
          }
        }

       printf("\n");
    }

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if ( j == 0 || j == 6)
            {
                printf("%c", '*');
            }
            else
                printf("%c", ' ');
        }
       printf("\n");
    }


    for (i = 0; i < 2; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%c", ' ');
        }

        for (j = 0; j <= 4 - 2 * i; j++)
        {
            if ( j == 0 || j == 4 - 2 * i || i == 1)
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
