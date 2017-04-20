#include <stdio.h>
#include <stdlib.h>
#include <string.h> //支持字符串操作
#include <time.h>
#include <conio.h>
#include <windows.h> //用了sleep函数
#include <mmsystem.h>
#pragma comment (lib, "Winmm.Lib")
#define MAX 8

///招满MAX=8个妃子，且有一个妃子成为皇后游戏胜利
int main()
{
    int i, j, temp; // 循环变量和临时整型;
    int count = 7; //初始化时登录的妃子个数;
    int choice;             //皇帝的选择 1-4之间
    int days = 0; //统计天数
    int randomnum; //随机数觉得皇上吟诗
    int serchIndex = -1;         //用来存放查找临时存放的下标
    int tempint; // 等级好感度临时存放
    char emperroName[50];   //皇帝的名号
    char tempName[20]; //存放临时名字
    char names[MAX][20] = {"貂蝉", "杨玉环" ,"西施" , "王昭君" , "高圆圆", "贾静雯", "小泽玛利亚"};
    //嫔妃的级别数组
    char levelNames[7][10] = {"答应", "常在", "贵人", "嫔妃", "贵妃", "皇贵妃", "皇后"};
    //用来存放每位妃子的级别,每个数组元素对应每个妃子的当前级别
    int levels[MAX] = {3, 4, 3, 3, 2, 0, 0, -1};
    //loves属猪中的每个元素对应每个妃子的好感度,初始情况,每个人的好感度为100
    int loves[MAX] = {100, 100, 100, 100, 100, 100, 100, -1};
    /*
    printf("测试代码: 查看当前嫔妃的状态\n");
    printf("%-14s级别\t好感度\n","姓名");
    for(i = 0; i < count; i++)
    {
        printf("%-14s%s\t %d\n", names[i], levelNames[levels[i]], love[i]);
    }
    */
    printf("请输入当前皇帝的登记名号：");
    scanf("%s",emperroName);

menu:
    for (i = 0; i < count - 1; i ++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if(levels[j] < levels[j + 1])
            {
                tempint = levels[j];
                levels[j] = levels[j + 1];
                levels[j + 1] = tempint;
                tempint = loves[j];
                loves[j] = loves[j + 1];
                loves[j + 1] = tempint;
                strcpy(tempName,names[j]);
                strcpy(names[j],names[j + 1]);
                strcpy(names[j + 1],tempName);
           }
        }
    }
    PlaySound(TEXT("sounds\\背景.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    printf("\n");
    printf("\n");
    printf("              后宫●佳丽     \n");
    printf("\n");
    printf("\n");
    printf("##########################################\n");
    printf("## %-14s#  后宫等级  #  好感度 ##\n","姓名");
    for(i = 0; i < count; i++)
    {
    printf("## %-14s#   %-6s   #   %-3d   ##\n", names[i], levelNames[levels[i]], loves[i]);
    }
    printf("##########################################\n");
    printf("\n");
    Sleep(500);
    days++;
    printf("*************\n");
    printf("  当前第%d天  \n", days);
    printf("*************\n");
    printf("\n");
    Sleep(500);
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("$                                                   $\n");
    printf("$       皇帝  @@%-6s驾临,有事上奏,无事退朝!       $\n",emperroName);
    printf("$                                                   $\n");
    printf("$  1. 皇帝下旨选妃:                    (增加妃子)   $\n");
    printf("$  2. 翻牌宠幸:                        (修改状态)   $\n");
    printf("$  3. 打入冷宫:                        (删除状态)   $\n");
    printf("$  4. 单独召见爱妃去小树林做纯洁的事。 (吟诗一首)   $\n");
    printf("$                                                   $\n");
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("陛下请选择: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1://皇帝下旨选妃: \t\t (增加妃子)
        //1.增加前需要判断妃子是否已满 数组是否有空间
        //2.增加一个妃子 增加names[] levelNames[] levels[] loves[] 数组;
        PlaySound(TEXT("sounds\\选妃.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        if (count < MAX)
        {
            //添加操作
            printf("\n请输入娘娘的名讳:");
            scanf("%s",names[count]);
            //将count个元素的状态初始化
            levels[count] = 0;
            loves[count] = 100;
            count++;
            Sleep(500);
            printf("\n恭喜皇上<%s>,后宫新添一位娘娘<%s>\n",emperroName,names[count - 1]);
            Sleep(500);
            printf("\n后宫其他娘娘好感度降低10\n");
            for (i = 0; i < count - 1; i++)
            {
                loves[i] -= 10;
            }


        }
        else
        {
           printf("\n陛下,要注意龙体啊,后宫已经人满为患!\n添加失败!\n");
        }
        break;
    case 2://翻牌宠幸: \t\t (修改状态)
        //1.找到要宠幸妃子的下标
        //2.修改这个妃子的状态 好感度+10,级别+1, 如果最高级就不在升级
        //3.修改其他妃子的状态 由于羡慕嫉妒恨, 其他妃子好感度下降-10;
        PlaySound(TEXT("sounds\\翻牌.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("\n陛下,请输入今天要翻牌娘娘的的名讳: ");
        scanf("%s",&tempName);
        //字符的查找strcmp, 需要引入,<string.h>
        //strcmp(tempName, "abc") 0-两个字符串相等; 1-前一个大于后一个 2-前一个小于后一个
        for (j = 0; j < count; j ++)
        {
            if (strcmp(tempName,names[j]) == 0)
            {
                for (i = 0; i < count; i++)
                {
                    if (strcmp(tempName,names[i]) == 0)
                    {
                        loves[i] += 10;
                        //要注意,级别不能超过上限,levelNames中的字符串个数
                        levels[i] = levels[i] >= 6 ? 6 : levels[i] + 1;
                        serchIndex++;
                    }
                    else
                    {
                        loves[i] -=10;
                    }

                }
                break;
            }
        }
        if ( -1 == serchIndex)
        {
            printf("\n后宫传闻:\n");
            printf("\n昨夜皇上下落不明!\n");
            printf("\n大内护卫丑时巡逻期间捕获一名衣衫褴褛名叫%s的女子\n",tempName);
            printf("\n后宫佳丽担忧过度,所有等级降低一级!\n");
            for (i = 0; i < count; i++)
            {
                levels[i] = levels[i] <= 0 ? 0 : levels[i] - 1;
            }
        }
        else
        {
            serchIndex = -1;
        }
        break;
    case 3://打入冷宫: \t\t (删除状态)
        //1.查找
        //2.后面一个赋值给前面一个元素
        //3.总数--
        //4其他娘娘好感度+10
        PlaySound(TEXT("sounds\\冷宫.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("\n陛下,请输入要打入冷宫的娘娘名讳: ");
        scanf("%s", &tempName);
        for (i = 0; i < count; i++)
        {
            if (strcmp(tempName,names[i]) == 0)
            {
                serchIndex = i;
                break;
            }
        }
        printf("%d",serchIndex);
        if (-1 == serchIndex)
        {
            printf("\n虚惊一场,无人打入冷宫,该吃吃该喝喝!\n");
        }
        else
        {
            for (i = serchIndex; i < count -1; i++)
            {
               //names[i] = namse[i + 1]; 因为是字符数组,C语言中不支持字符数组的直接赋值
               //我们需要使用strcpy函数实现字符数组的赋值
               strcpy(names[i], names[i + 1]);
               loves[i] = loves[i + 1];
               levels[i] = levels[i + 1];
            }
            count--;
            serchIndex = -1;
        }
        //其他娘娘好感度+10
        for (i = 0; i < count; i++)
        {
            loves[i] += 10;
        }
        break;
    case 4://4. 单独召见爱妃去小树林做纯洁的事。
        PlaySound(TEXT("sounds\\小树林.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("\n陛下,请输入带入小树林去的娘娘名讳: ");
        scanf("%s", &tempName);
        for (i = 0; i < count; i++)
        {
            if (strcmp(tempName,names[i]) == 0)
            {
            loves[i] += 10;
            serchIndex = i;
            break;
            }
        }
        if (-1 == serchIndex)
        {
            printf("\n坊间传闻:\n");
            printf("\n昨日在怡红院有一宫装男子为头牌%s豪掷千金!\n",tempName);
        }
        else
        {
            printf("\n皇上诗兴大发,为博娘娘%s一笑,淫诗一首!\n",tempName);
            serchIndex = -1;

            srand((unsigned) time(NULL));
            randomnum = rand() % 5 + 1;
            switch(randomnum)
            {
            case 1:
                printf("一一一一一\n");
                break;
            case 2:
                printf("二二二二二\n");
                break;
            case 3:
                printf("三三三三三\n");
                break;
            case 4:
                printf("四四四四四\n");
                break;
            case 5:
                printf("五五五五五\n");
                break;
            }
        }
        break;
    default:
        printf("\n君无戏言,陛下请慎重行事!\n");
        printf("\n皇上闭门思过耗时7天\n");
        days += 6;
        printf("\n");Sleep(200);fflush(stdout);
        printf("时");Sleep(200);fflush(stdout);
        printf("光");Sleep(200);fflush(stdout);
        printf("飞");Sleep(200);fflush(stdout);
        printf("逝");Sleep(200);fflush(stdout);
        printf(",");Sleep(200);fflush(stdout);
        printf("转");Sleep(200);fflush(stdout);
        printf("眼");Sleep(200);fflush(stdout);
        printf("已");Sleep(200);fflush(stdout);
        printf("过");Sleep(200);fflush(stdout);
        printf("7");Sleep(200);fflush(stdout);
        printf("天\n");
        for( i=0;i<7;i++ )
        {
            Sleep(500);    /* windows 使用Sleep，参数为毫秒 */
            printf(".");
            fflush(stdout);//强制刷新缓存，输出显示
        }
        printf("\n");
        fflush(stdin);
        break;
    }
    //按等级降序排序
    if (count >= MAX && levels[0] >= 6)
    {
        PlaySound(TEXT("sounds\\人身赢家.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        days++;
        printf("\n昭告天下:皇帝[%s]自登基来,不辞辛劳,整顿后宫,终于完成后宫霸业!\n", emperroName);
        printf("\n皇帝[%s]执政%d天,在皇帝的日夜扶持下,[%s]荣升皇后娘娘!\n", emperroName, days, names[0]);
        printf("\n后宫佳丽%d位,团结互助,为皇上分忧使出浑身媚数!\n",count);
        printf("\n皇城内每晚都会传出了和谐欢快的音乐\n",count);
        printf("\n按任意键退出游戏...\n");//提示信息
        getch();//等待终端输入任意字符
        exit (0);
    }
    else
    {
        printf("\n新的一天即将开始了~!\n");
        for( i=0;i<5;i++ )
        {
            Sleep(500);    /* windows 使用Sleep，参数为毫秒 */
            printf(".");
            fflush(stdout);//强制刷新缓存，输出显示
        }
        printf("\n");
        goto menu;
    }






    return 0;
}
