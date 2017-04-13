#include <stdio.h>
#include <stdlib.h>
 //循环输入N个月的工资数，计算N个月的平均工资；
 //初始值，需要循环几次？N次。



/*void main()
{
    int input_num;//定义一个用户输入的数字
    int i;//定义一个循环控制变量
    printf("请输入一个数：");
    scanf("%d", &input_num);//用户输入一个数
    printf("加法表：\n");
    for (i = 1; i < input_num; i += 2)//变量i 用于控制打印次数
    {

        printf("%d + %d = %d\t", i , input_num - i, input_num);
        if (input_num - i > 1)
        {
            printf("%d + %d = %d\n", i + 1, input_num - i - 1, input_num);
        }
    }
    return 0;
}*/


void main()
{
    int input_num;//定义一个用户输入的数字
    int i;//定义一个循环控制变量
    printf("请输入一个数：");
    scanf("%d", &input_num);//用户输入一个数
    printf("加法表：\n");
    for (i = 1; i < input_num; i ++)//变量i 用于控制打印次数
    {

        printf("%d + %d = %d", i , input_num - i, input_num);
        if (i % 5 == 0)
        {
            printf("\n");
        }
        else
        {
            printf("\t");
        }
    }
    return 0;
}
