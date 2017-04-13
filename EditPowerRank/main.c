#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    ///让用户输入N个战斗值
    ///1、战力值大到小排列 并打印
    ///2、用户删除某一战斗力 并重新排序 ////从下标开始 后面的值赋值给前面的值
    ///3、用户增加某一战斗力 并重新排序

    const int N; ///表示元素的个数 这里用来表示排行榜排多少位
    //让用户输入战斗力排行榜排多少名
    printf("################################\n");
    printf("欢迎来到战力排行榜系统！\n");
    printf("################################\n");
    printf("请根据需要输入战力排行榜排多少名：\n");
    scanf("%d",&N);
    printf("################################\n");
    int count = N; ///确定数组下标极限值同时以该变量count进行循环计算
    int nums[count];
    int matchIndex[count]; ///元素个数初始化值。战力相同个数
    int delnum; ///删除战力值
    int addnum; ///增加战力值
    int numstemp;///临时储存需要交换的战斗力
    int answer; ///选择分支,根据输入的数字来执行1-4不同的分支
    int i, j;
    int match_count = 0;
    printf("################################\n");
    ///录入战斗力数值
    for(i = 0; i < count; i++)
    {
        printf("请输入第%d个战力数值；",i + 1);//让用户输入N个战斗数值
        scanf("%d",&nums[i]);
    }


    //对当前数组进行排序
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - 1 - i; j++)
        {
            if(nums[j] < nums[j + 1])
            {
                numstemp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = numstemp;
            }
        }
    }
    //打印数组
    printf("################################\n");
    printf("前%d位战力排行榜为：\n", N);
    for (i = 0; i < count; i++)
    {
        printf("第%d位：    \t战力值为：%d\n",i + 1, nums[i]);
    }
    printf("################################\n");
    // 匹配结果下标初始化
    for (i = 0; i < count; i++)
    {
        matchIndex[i] = -1;
    }
choose:
    //询问是否要删除或增加数组并作出选择,选择错误重新选择
    printf("###########################################################################\n");
    printf("是否需要对排行榜进行操作？\n");
    printf("输入数字1: 删除一个战力,排行榜减少一位排名,并打印\n");
    printf("输入数字2: 增加一个新战力,自动调整排行榜排名,并打印\n");
    printf("输入数字3: 不做任何操作,程序退出!\n");
    printf("###########################################################################\n");
    for (i = 0;i < 3; i++)
    {
        printf("\t输入数字1-3作出你的选择: ");
        scanf("%d", &answer);
        if (answer == 1 || answer == 2 || answer == 3 )
        break;
        else
        {
        printf("###########################################################################\n\t输入错误!请重新输入!\n###########################################################################\n ");
        printf("输错3次强制退出!当前第%d次!",i + 1);
        }
    }
    switch(answer)  ///根据选择进入1-4个分支
    {
    case 1:         ///分之1: 删除数据
         while(1)
        {
            if (match_count != 0)
            {
                break;
            }
            printf("请输入您要删除的战力值: ");///输入要删除的战斗力
            scanf("%d",&delnum);
            printf("################################\n");
            //判断是否包含数据,包含，记录下标，匹配计数加1；
            for (j = 0; j < count; j++)     ///找的次数 等于 count赋值
            {
                if (delnum == nums[j])      ///输入的数值存在于数组中 排行榜中
                {
                    matchIndex[j] = j;      ///记录下当前的下标 放入匹配数组
                    match_count += 1;       ///匹配数累加
                }
            }
            //给匹配下标数组排序
            for (i = 0; i < count - 1; i++)             ///排序数组i控制轮次n-1
            {
                for (j = 0; j < count - 1 - i; j++)     ///排序数组j控制本轮次数n-1-i
                {
                    if(matchIndex[j] < matchIndex[j + 1])
                    {
                        numstemp = matchIndex[j];
                        matchIndex[j] = matchIndex[j + 1];
                        matchIndex[j + 1] = numstemp;
                    }
                }
            }
                   /* /// 打印匹配下标(用于校验测试，不影响结果可注释掉)
                    for (i = 0; i < count; i++)
                    {
                        printf("%d\n",matchIndex[i]);
                    }
                    */
            //判断是否找到想匹配的数据
            if (match_count != 0) ///包含数据
            {
                printf("找到了%d条符合的数据，已删除！\n",match_count);
                //对符合的数据进行删除操作
                for (i = matchIndex[0] + 1  - match_count; i < count - match_count ; i++)
                {
                    nums[i] = nums[i + match_count]; ///删除数据,根据记录的下标和匹配数将后续元素替换至前面
                }
                count -= match_count;               ///参与排位的元素相应减少
                for (i = 0; i < count; i++)
                {
                    matchIndex[i] = -1;            ///匹配数组初始化 -1
                }
                match_count = 0;                    ///匹配数初始化0
                printf("################################\n");
                printf("前%d位战力排行榜为：\n", N);
                break;
            }
            else ///不包含数据 重新输入删除的战斗力
            {
                printf("很遗憾，没有找相匹配的数据！\n");
                //打印数组
                printf("################################\n");
                printf("前%d位战力排行榜为：\n", N);
                for (i = 0; i < count; i++)
                {
                    printf("第%d位：    \t战力值为：%d\n",i + 1, nums[i]);
                }
                printf("################################\n");
                printf("请重新核对！\n");
            }
        }
        break;
    case 2:     ///分支2,增加数据
        //用户录入数据
        printf("请输入您要增加的战力值: ");///输入要删除的战斗力
        scanf("%d",&addnum);
        printf("################################\n");
        //判断是否是否有空位,如果有则增加并重新排序
        if(count == N)  ///没空位
        {
            //判断是否上榜
            if (addnum > nums[count - 1]) ///上榜
            {
                nums[count - 1] = addnum; ///替换最后一个战力值
            }
            else
            {
                printf("很遗憾,你输入的战力未能上榜\n");
            }
        }
        else///有空位
        {
            nums[count] = addnum; ///插入到最后合适位置
            count += 1; ///增加一个元素计数
        }

        //给数组排序
        for (i = 0; i < count - 1; i++)
        {
            for (j = 0; j < count - 1 - i; j++)
            {
                if(nums[j] < nums[j + 1])
                {
                    numstemp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = numstemp;
                }
            }
        }
        break;
    case 3:
        goto end;
        break;
    }

    //打印数组
    printf("################################\n");
    printf("前%d位战力排行榜为：\n", N);
    for (i = 0; i < count; i++)
    {
        printf("第%d位：    \t战力值为：%d\n",i + 1, nums[i]);
    }
    printf("################################\n");

    ///继续回到选择界面,进一步操作数据
    printf("按任意键继续...\n");//提示信息
    getch();//等待终端输入任意字符
    goto choose;

end: ///选择选项4后提示退出程序
    printf("按任意键退出程序...\n");//提示信息
    getch();//等待终端输入任意字符
    return 0;//退出程序
}
