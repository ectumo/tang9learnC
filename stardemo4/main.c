#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int num ; //�û��������
    for (;;)
        {
            printf("����������Ҫ��ӡ�����εĳ���,�����Ǵ��ڵ���3������: ");
            scanf("%d", &num);
            if (num % 2 != 0 && num >=3 )
            {
                break;
            }
        }
    printf("\n");
    for(i = 0 ; i < num ; i++)
    {
        printf("\t\t");
        for (j = 0 ; j < num ; j ++)
        {
            if(i <= num/2 && j >= num/2 - i && j <= num/2 + i || i > num/2 && j >= num/2 + 1 + i - num && j <= num/2 - 1 -i + num)
            {
                printf("*");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }




    return 0;
}
