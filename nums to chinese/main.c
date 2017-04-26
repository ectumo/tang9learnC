/// 程序目的：将阿拉伯数字转换成大写中文字，并配合合适单位
/// 1.采集数字          分析后决定用字符串录入，提取后转化。如果用double不好操作。
/// 2.输入验证          由于采用字符串录入，因此要避免出现非法字符。
/// 3.数据格式化        解决中间连续零去除的问题！及首尾无效零！通过给对应的每个字符
///                      设置一个打印标签，符合的打印不符合的不打！
/// 4.转换字符并添      字符的转换相对简单，只要去和字符匹配然后转换即可，单位添加
///   加合适的单位      阶段比较复杂。经过分析将分为3个部分。整数，个位数，及小数
///                      通过字符串长度函数,及小数点位置区分出整数，个位，及小数部分
///                      需要考虑小循环十百千，及大循环万，亿，兆。
///
/// ///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 20;             //支持的转换位数，小数点算1位。可修改！
int main (void)
{

    int numlen;                 //字符串长度
    int numilen;                //整数部分长途
    int count;                  //调整位数计数
    int temp;                   //临时变量，存储临时数据
    int indexpoint = -1;        //初始化小数点位置
    int errorcount = MAX + 1;   //验证错误数
    int pointcount = 0;         //初始化小数点个数
    int i, j;                   //循环变量
    int zeroindex[MAX];         //零下标记录后作打印参照标签,值为9打印，其余不打印。
    char snums[MAX];            //存放用户输入的数字字符串
    char uppernums[11][3] = {"零", "壹", "贰", "弎", "肆", "伍",
                                "陆", "柒", "捌", "玖", "点"};                   //数字对应转换 最字符串宽度为2byte+1个\0为3;
    char upperbit1[6][3] = {"拾", "佰", "仟", "萬", "亿", "兆"};                 //整数位数对应转换     //便于今后更新维护
    char upperbit2[3][3] = {"角", "分", "厘"};                                   //小数位数对应转换     //分开整数小数部分
    char nums[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};     //对应中文大写

    printf("这是一个阿拉伯数字转汉字大写的程序"
           "可根据需要调整支持位数目前支持%d位(小数点算1位)\n", MAX);
    printf("整数部分最大单位到兆位，超出后循环；小数部分最小单位到厘，超出后不再添加单位\n\n");
    printf("请输入一个有效数字：");
    scanf("%s", snums);
    /// 验证用户输入是否符合规定，不符合重新输入 ///////////////////////
    numlen = strlen(snums); //取字符串长度 numlen - (indexpoint + 1)整数位数
    //验证输入是否合法 长度不超过MAX位，小数点算1位。
    while (errorcount != 0 )
    {
        for (i = 0; i < numlen; i++)
        {
            if ( snums[i] == '.' && pointcount < 1 &&
                 numlen < MAX && indexpoint != 0)                                    //判断是否等于'.' 并且 个数不能超过1个
            {                                                                        //字符长度不能超过位数，小数点不能在首位。
                //printf("%c", snums[i]); //校验字符.和输入的对比
                indexpoint = i;
                pointcount++;
                continue;
            }
            else if (snums[i] >= '0' && snums[i] <= '9' &&
                      pointcount < 2 && numlen < MAX && indexpoint!= 0)
            {
                //printf("%c", snums[i]); //校验字符0-9和输入的对比
                continue;
            }
            else //非法字符(不是字符0-9，字符.)或小数点超限，位数超限
            {
                printf("\n");
                printf("输入错误,位数过长或含有非法字符！\n");
                printf("\n请重新输入一个有效数字：");
                scanf("%s", snums);
                numlen = strlen(snums);    //重新初始化字符长度
                pointcount = 0;            //重新初始化小数点个数
                i = -1;                    //i = -1; 循环结束后i++ 后重新初始化i = 0,防止i >= numlen跳出循环；
            }
        }
        errorcount = 0;
    }
    /// 验证输入结束///////////////////////////////////////////////////////



    /// 数据格式化，连续零，首尾无零，全零情况等考虑了多种不同极端情况下的状况///////////
    //初始化zeroindex[MAX]为1
    for (i = 0; i < numlen; i++)
    {
        zeroindex[i] = 9;
    }
    //判断字符串中是否有零，如有有零则将相应的标签改为0
    for (i = 0; i < numlen; i++)
    {
       if (snums[i] == '0')
       {
           zeroindex[i] = 0;
       }
       else if (snums[i] == '.' )
       {
           zeroindex[i] = 8;
       }
    }

    //打印测试
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("转换结束\n");

    //比对zeroindex中的零是否连续，如果连续就向前合并
    for (i = 0; i < numlen - 1; i++)
    {
        if (0 == zeroindex[i] && 0 == zeroindex[i + 1])
        {
            zeroindex[i] = 1;
        }
    }

    //打印测试
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("合并结束\n");

    //去除头部无效零,直到首位数字非零

    for (i = 0; i < numlen - 1; i++)
    {
        if (zeroindex[i] != 9 && zeroindex[i + 1] < 8)
        {
            zeroindex[i] = 1;
            zeroindex[i + 1] = 1;
        }
        else
        {
            break;
        }
    }

    //打印测试
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("头部去除\n");

    //小数点后头部无效零去除，直到小数点后首位非零
    if (indexpoint != -1)
    {
        for (i = indexpoint; i < numlen - 1; i++)
        {
            if (zeroindex[i + 1] != 9)
            {
                zeroindex[i] = 1;
                zeroindex[i + 1] = 1;
            }
            else
            {
                break;
            }
        }
    }

    //打印测试
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("小数头部去除\n");

    //尾部无效零去除
    for (i = numlen; i > 1; i--)
    {
        if (zeroindex[i] != 9 && zeroindex[i - 1] != 9 )
        {
            zeroindex[i] = 1;
            zeroindex[i - 1] = 1;
        }
        else
        {
            break;
        }
    }

    //打印测试
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("尾部转换结束\n");

    //将zeroindex中可以零转换为9,只有当index中为9时才需要打印
     for (i = 0; i < numlen; i++)
    {
        if (0 == zeroindex[i])
        {
            zeroindex[i] = 9;
        }
    }

    //打印测试
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("转换结束\n");

    //判断是否需要调整个位数的状态
    temp = 0;     //此处作为统计有效数的计数用
    for (i = 0; i < numlen; i++)
    {
        if(zeroindex[i] == 9)
        {
            temp ++; //有效数加1
            break;
        }
    }

    //判断是否是整数(有没有小数点)
    if (indexpoint == -1)
    {
        numilen = numlen;               //整数长度等于字符串长度
    }
    else
    {
        numilen = indexpoint - 1;       //整数长度等于小数点下标
    }
    //判断是否有有效数字
    if (temp == 0)
    {
        zeroindex[numilen - 1] = 9;   //数字为全零，或零和小数点时，调整个位打印标签
    }

    //打印测试
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("最终转换结束\n");


    /// 数据格式化完毕，//////////////////////////////////////////////////////////

    //打印阿拉伯数字

    printf("\n输入的阿拉伯数字为：\t");
    for (i = 0; i < numlen; i++)
    {
        printf("%-2c", snums[i]);
    }
    printf("\n\n");

    //打印转换中文大写的数字，不带位数
    printf("中文不带单位大写为：\t");
    for (i = 0; i < numlen; i++)
    {
        for (j = 0; j < 11; j++)
        {
            if(snums[i] == nums[j])
            {
                printf("%s", uppernums[j]);
            }
        }
    }
    printf("\n\n");
    printf("中文带单位大写为：\t");
     /// 转换汉字 ///////////////////////////////////////////////////////
     numilen -= 1; // (numilen - 1); 减去个位。
     count = numilen % 4; //超出循环的余数额外的位数
    //转换成中文汉字第一部分 转换整数部分% 4不等于0的额外位数
    if (count != 0)
    {
        for(i = 0; i < count; i++)
        {
            for (j = 0; j < 10; j++)                //与(0-9)数字比对
            {
                if (snums[i] == nums[j] && zeroindex[i] == 9) ///符合要求的就打印
                {
                    printf("%s",uppernums[j]);  //打印对应的中文大写
                    break;
                }
            }
            if (zeroindex[i] == 9)
            {
                printf("%s", upperbit1[count - i - 1]);
            }
        }
        //尾数全为零时当大于万位时，最高位单位补足
        if(zeroindex[count]==1&&numilen>4)
            printf("%s",upperbit1[numilen/4+2]);
        numilen -= count; //转换需要减去%4的额外的位数
    }

    //转换成中文汉字第二部分 %4等于0的额外位数
    i = numilen;  //循环变量i 等于 剩余转换位数的最高位
    while (i > 0)
    {
             for (j = 0; j < 10; j++)                //与(0-9)数字比对
            {
                if (snums[count + numilen - i] == nums[j]  && zeroindex[count + numilen - i] == 9 ) //相等
                {
                    printf("%s",uppernums[j]);      //打印对应的中文大写
                    if (i % 4 == 0)                 //每4位进一位
                    {
                        printf("%s", upperbit1[3 + (i - 1) % 3]);
                    }
                    else
                    {
                        printf("%s", upperbit1[i % 4 - 1]);
                    }
                break;
                }
            }
            i--;
    }
    //转换个位数和小数
    //判断是否是整数(有没有小数点)
    if (indexpoint == -1)
    {
        for (j = 0; j < 10; j++)                //与(0-9)数字比对
        {
            if (snums[numlen - 1] == nums[j] && zeroindex[numlen - 1] == 9) //相等
            {
                printf("%s",uppernums[j]);     //打印对应的中文大写
                break;
            }
        }
        printf("圆整\n");
    }
    else
    {
        for (j = 0; j < 10; j++)                //与(0-9)数字比对
        {
            if (snums[numlen - 1] == nums[j] && zeroindex[i] == 9) //相等
            {
                printf("%s",uppernums[j]);     //打印对应的中文大写
                break;
            }
        }
        if (temp == 0)
        {
            printf("零圆整");
        }
        else
        {
            printf("圆");
        }
        for (i = indexpoint + 1; i < numlen; i++)
        {
            for (j = 0; j < 10; j++)                //与(0-9)数字比对
            {
                if (snums[i] == nums[j] && zeroindex[i] == 9) //相等
                {
                    printf("%s",uppernums[j]);     //打印对应的中文大写
                    if (i < indexpoint + 4)
                    {
                        printf("%s", upperbit2[i - (indexpoint + 1)]);
                    }
                    break;
                }
            }
        }
    }
    printf("\n\n");
    printf("本次转换结束！\n");
    printf("按任意键退出\n");
    getchar();
    getchar();
    /// 转换汉字结束 ////////////////////////////////////////////////////

    return 0;
}
