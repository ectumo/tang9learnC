#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{


    const int N; ///定义行
    const int M; ///定义列
    //用户录入行数
    printf("友情提示:\n");
    printf("录入的学生数、科目数不要过大！\n");
    printf("超过一定数量显示效果将受影响！\n");
    printf("建议学生数25，科目12以内\n");
    printf("能更好的比对数据验证！\n");
    printf("按任意键开始录入...\n");//提示信息
    getch();//等待终端输入任意字符
    printf("请输入需要生成的随机学生数:"); ///需要生成的随机二元数组的行数
    scanf("%d", &N);
    //用户录入列数
    printf("请输入需要生成的随机科目数:"); ///需要生成的随机二元数组的列数
    scanf("%d", &M);
    //int Row = N; ///列计数循环用
    //int Cloumn = M; ///行计数循环用
    srand((unsigned) time(NULL)); ///取时间函数的伪随机数
    int num1, num2, num3;
    double total = 0;
    double avg = 0;
    int answer; ///选择分支用M科+1总分 0退出
    double tempscore;///临时交换数据用
    int i, j, k;
    int namenum; ///学生学号
    int subjetnum; ///科目号
    double scores[N+3][M+3];  /// 定义一个N行M列的二元数组
                            /// 增加3列 一列学号列1 数据从1开始到M 一列总分列M+2 一列平均分列M+3
                            /// 还可增加一行科目行1 数据从1行到N行 单科总分列N+2 单科平均分行N+3
    //double scoresrand[N * M]; ///定义一个N * M个元素的一元数组
    //double totals[N]; ///定义一个总分数组
    //double avgs[N]; ///定义一个平均分数组

    //美化作用1
        printf("########");
    for (j = 0; j < M + 3; j++)
    {
       printf("###########"); ///根据列数自动调整#符数量
    }
    printf("\n");

    printf("%d个学生%d个科目的分数表为:\n",N ,M);

    //美化作用2
        printf("########");
    for (j = 0; j < M + 3; j++)
    {
       printf("###########"); ///根据列数自动调整#符数量
    }
    printf("\n");
    //初始化数组全为0
    for (i = 0; i < N + 3; i++)
     {
         for(j = 0; j <M + 3; j++)
         {
             scores[i][j] = 0;
         }
     }

    //给数组赋值随机数1值N+1行共N行 1至M+1列共M列 的N*M个随机数据
    for (i = 1; i < N + 1; i ++) ///范围1至N+1行 不包含科目行 科目总分 科目总平均分
    {
        for (j = 1; j < M + 1; j++) /// 范围1至M+1列 不包含学生学号列 总分列 总平均分列
        {
            num1 = rand() % 5 + 5;
            num2 = rand() % 10;
            num3 = rand() % 10;
            if (num1 >= 6 && num2 >=6 && num3 >=6  )/// 判断随机数是否能成为100分概率控制在6.5%左右
            {
                scores[i][j] = 100; ///赋值100分给二元数组scores[N][M]
            }
            else
            {
                scores[i][j] = num1 * 10 + num2; ///赋值非100分给二元数组scores[N][M]
            }
        }
    }
    //给数组的每一行的第一列赋值为 第N名学生 以数字表示 列 1,2,3,4...N
    for (i = 1; i < N + 1; i++) ///范围1至N+1行 不包含科目行 科目总分 科目总平均分
    {
        scores[i][0] = i;
        ///printf("%-8.2lf\n",scores[i][0]); 校验用
    }


    //给数组的每一列的第一行赋值为 第N门科目 以数字表示 列 1,2,3,4...M
    for (j = 1; j < M + 1; j++) ///范围1至M+1列 不包含学生学号列 总分列 总平均分列
    {
        scores[0][j] = j;
        ///printf("%-8.2lf\n",scores[0][j]); 校验用
    }
///printf("打印判断1\n");
/// 打印判断用 //////////////////////////////////////
//     for (i = 0; i < N + 3; i++)
//     {
//         for(j = 0; j <M + 3; j++)
//         {
//             printf("%-8.2lf",scores[i][j]);
//         }
//     printf("\n");
//     }
/// 打印判断结束 ///////////////////////////////////
    //总分 平均分排名  总分:每一行所有学科相加, 平均分：总分/科目
    //第一步总分平均分统计
    for (i = 1; i < N + 1; i++)  ///计算1至N+1名学生 重复1至N+1行
    {
        for (j = 1; j < M + 1; j++ )  ///计算1至M+1科目 重复1至M+1列
        {
            total = total + scores[i][j]; ///学生的M科分数累加
        }

        avg = total / M;
        scores[i][M+1] = total; ///总分存放至数列的M+2列
        scores[i][M+2] = avg;   ///平均分存放至数列的M+3列
        total = 0;
    }
    //第二步科目总分平均分统计
    total = 0;                      ///初始化total值
    for (j = 1; j < M + 1; j++)  /// 计算1至M+1科目 重复1至M+1列
    {
        for (i = 1; i < N + 1; i++ )///计算1至N+1行总分 重复1至N+1行
        {
            total = total + scores[i][j]; ///每名学生的分数数累加
        }

        avg = total / N;
        scores[N+1][j] = total;
        scores[N+2][j] = avg;
        total = 0;
    }
    //打印未排序的总分和平均分
    /// 打印标表格第一行 ////////////////////////////////////////////////////////////////////////
    printf("##  学 号        ");
    for (j = 1; j < M + 1; j++) ///科目存放在1行的1至M+1列
    {
        subjetnum = scores[0][j]; /// 将scores[][];的数据类型double自动调整到int型以便美化排列
        if (subjetnum < 10)
        {
            printf("#  科目%d   ",subjetnum); ///打印int类型的科目序号
        }
        else if (subjetnum < 100)
        {
            printf("#  科目%d  ",subjetnum); ///打印int类型的科目序号
        }
        else if (subjetnum < 1000)
        {
            printf("#  科目%d ",subjetnum); ///打印int类型的科目序号
        }
        else
        {
            printf("#  科目%d",subjetnum); ///打印int类型的科目序号
        }
    }
    printf("#  总 分   #  平均分  ##\n"); ///补齐M+2总分列M+3平均分列

    //美化作用
        printf("########");
    for (i = 0; i < M + 3; i++)
    {
       printf("###########");
    }
    printf("\n");
    /// 结束第一行打印 //////////////////////////////////////////////////////////////////////////

    //打印数据
    /// 打印随机取值的N行M列数据
    for (i = 1; i < N + 1; i++)         ///从1行至N+1行 共N行的数据
    {
        namenum = scores[i][0];         /// 将scores[][];的数据类型double自动调整到int型以便美化排列
        printf("##  学生%d  \t ", namenum); ///每i行的第一列打印int类型的学生学号序号
        for (j = 1; j < M + 3; j++)  /// 每一行的第二列开始至M+3列打印 M列数据 一列总分 一列平均分
        {
            printf("#  %-8.2lf", scores[i][j]);
        }
    printf("##\n");
    }
    /// 打印N+1行数据
    printf("##  科目总分     ");
    for (j = 1; j < M + 1; j++) ///科目总分存放在N+2行的1至M+1列
    {
        printf("#  %-8.2lf", scores[N+1][j]); ///打印N+2行的1至M+1列
    }
    printf("#          #          ##\n"); ///补齐M+2总分列
    /// 打印N+2行数据
    printf("##  科目平均分   ");
    for (j = 1; j < M + 1; j++) ///科目平均分存放在N+3行的1至M+1列
    {
        printf("#  %-8.2lf", scores[N+2][j]); ///打印N+3行的1至M+1列
    }
    printf("#          #          ##\n"); ///补齐M+3平均分列
    //美化作用
        printf("########");
    for (i = 0; i < M + 3; i++)
    {
       printf("###########");
    }
    printf("\n");


Choose1:
    printf("##################################################\n");
    printf("## 输入数字0:         \t不做任何操作,程序退出!  ##\n");
    printf("## 输入数字1-%d:       \t按所选科目降序排名      ##\n",M);
    printf("## 输入数字%d:         \t按总分降序排名          ##\n",M + 1);
    printf("## 输入数字%d:         \t单科总分进入下级菜单    ##\n",M + 2);
    printf("##################################################\n");
    printf("\t输入数字0-%d作出你的选择: ",M + 2);
    scanf("%d", &answer);
    if (answer == M + 2)
    {
        goto Choose2; ///跳转到行索引列降序模式
    }
    else if(answer == 0)
    {
        goto End;   ///
    }
    for (i = 1 ; i < M + 2; i ++)
    {
        if (i == answer)
        {
            goto Row;  ///跳转到列索引行降序模式
        }
    }
    //for (i = 0; i < N)
    printf("输入错误!请重新选择!\n");
    goto Choose1;/// 跳转到1级选择菜单
Row:
    ///初始化数据科目
    for(k = 0; k < M - 1; k++) ///控制排名比对轮次 次数等于M科-1科
    {
        for (j = 1; j < M - k; j++)
        {
            if (scores[0][j] > scores[0][j + 1]) ///判断如总分大于前一名则互换
            {
                for (i = 0; i < N + 3; i++)
                {
                    tempscore = scores[i][j];
                    scores[i][j] = scores[i][j + 1];
                    scores[i][j + 1] = tempscore;
                }
            }
        }
    }
    ///按选定列从大到小降序排列
    for(k = 0; k < N - 1; k++) ///控制排名比对轮次 次数等于N名-1次
    {
        for (i = 1; i < N - k; i++) ///每一轮比对次数等于N名-轮次-1
        {
            if (scores[i + 1][answer] > scores[i][answer]) ///判断如总分大于前一名则互换
            {
                for (j = 0; j < M + 3; j++)
                {
                    tempscore = scores[i][j];
                    scores[i][j] = scores[i + 1][j];
                    scores[i + 1][j] = tempscore;
                }
            }
        }
    }
    if (answer == M + 1)
    {
        printf("当前总分排行榜为:\n");
    }
    else
    {
        printf("你选择的科目%d排行榜为:\n",answer);
    }
    //美化作用
    printf("########");
    for (i = 0; i < M + 3; i++)
    {
       printf("###########");
    }
    printf("\n");
    /// 打印标表格第一行 ////////////////////////////////////////////////////////////////////////
    printf("##  学 号        ");
    for (j = 1; j < M + 1; j++) ///科目存放在1行的1至M+1列
    {
        subjetnum = scores[0][j]; /// 将scores[][];的数据类型double自动调整到int型以便美化排列
        if (subjetnum < 10)
        {
            printf("#  科目%d   ",subjetnum); ///打印int类型的科目序号
        }
        else if (subjetnum < 100)
        {
            printf("#  科目%d  ",subjetnum); ///打印int类型的科目序号
        }
        else if (subjetnum < 1000)
        {
            printf("#  科目%d ",subjetnum); ///打印int类型的科目序号
        }
        else
        {
            printf("#  科目%d",subjetnum); ///打印int类型的科目序号
        }
    }
    printf("#  总 分   #  平均分  ##\n"); ///补齐M+2总分列M+3平均分列

    //美化作用
    printf("########");
    for (i = 0; i < M + 3; i++)
    {
       printf("###########");
    }
    printf("\n");
    /// 结束第一行打印 //////////////////////////////////////////////////////////////////////////

    //打印数据
    /// 打印随机取值的N行M列数据
    for (i = 1; i < N + 1; i++)         ///从1行至N+1行 共N行的数据
    {
        namenum = scores[i][0];         /// 将scores[][];的数据类型double自动调整到int型以便美化排列
        printf("##  学生%d  \t ", namenum); ///每i行的第一列打印int类型的学生学号序号
        for (j = 1; j < M + 3; j++)  /// 每一行的第二列开始至M+3列打印 M列数据 一列总分 一列平均分
        {
            printf("#  %-8.2lf", scores[i][j]);
        }
    printf("##\n");
    }
    /// 打印N+1行数据
    printf("##  科目总分     ");
    for (j = 1; j < M + 1; j++) ///科目总分存放在N+2行的1至M+1列
    {
        printf("#  %-8.2lf", scores[N+1][j]); ///打印N+2行的1至M+1列
    }
    printf("#          #          ##\n"); ///补齐M+2总分列
    /// 打印N+2行数据
    printf("##  科目平均分   ");
    for (j = 1; j < M + 1; j++) ///科目平均分存放在N+3行的1至M+1列
    {
        printf("#  %-8.2lf", scores[N+2][j]); ///打印N+3行的1至M+1列
    }
    printf("#          #          ##\n"); ///补齐M+3平均分列
    //美化作用
        printf("########");
    for (i = 0; i < M + 3; i++)
    {
       printf("###########");
    }
    printf("\n");

        ///继续回到选择界面,进一步操作数据
        printf("按任意键继续...\n");//提示信息
        getch();//等待终端输入任意字符
        goto Choose1;

Choose2:
    printf("##################################################\n");
    printf("## 输入数字0:   \t不做任何操作,程序退出!  ##\n");
    printf("## 输入数字1-%d:     \t按学生科目分降序排序    ##\n", N);
    printf("## 输入数字%d:       \t按科目总分降序排序      ##\n",N + 1);
    printf("## 输入数字%d:       \t返回上级菜单            ##\n",N + 2);
    printf("##################################################\n");
    printf("\t输入数字0-%d作出你的选择: ",N + 2);
    scanf("%d", &answer);
    if (answer == N + 2)
    {
        goto Choose1; ///跳转到Choose1上级菜单
    }
    else if(answer == 0)
    {
        goto End;   ///
    }
    for (i = 1; i < N + 2; i++)
    {
        if (i == answer)
        {
            goto Column;
        }
    }
    printf("输入错误!请重新选择!\n");
    goto Choose2;/// 跳转到2级选择菜单
Column:
       ///初始化数据 按学生名字排序
        for(k = 0; k < N - 1; k++) ///控制排名比对轮次 次数等于N名-1次
        {
            for (i = 1; i < N - k; i++) ///每一轮比对次数等于N名-轮次-1
            {
                if (scores[i + 1][0] < scores[i][0]) ///判断如总分大于前一名则互换
                {
                    for (j = 0; j < M + 3; j++)
                    {
                        tempscore = scores[i + 1][j];
                        scores[i + 1][j] = scores[i][j];
                        scores[i][j] = tempscore;
                    }
                }
            }
        }
    //单科平均分排名  单科总分:科目每一行分数相加, 平均分：单科总分/科目数
    for(k = 0; k < M - 1; k++) ///控制排名比对轮次 次数等于M科-1科
    {
        for (j = 1; j < M - k; j++)
        {
            if (scores[answer][j] < scores[answer][j + 1]) ///判断如总分大于前一名则互换
            {
                for (i = 0; i < N + 3; i++)
                {
                    tempscore = scores[i][j];
                    scores[i][j] = scores[i][j + 1];
                    scores[i][j + 1] = tempscore;
                }
            }
        }
    }
    if (answer == N + 1)
    {
        printf("当前科目总分排行榜为:\n");
    }
    else
    {
        printf("你选择的学生%d全科成绩排序为:\n",answer);
    }
    //美化作用
    printf("########");
    for (i = 0; i < M + 3; i++)
    {
       printf("###########");
    }
    printf("\n");
    /// 打印标表格第一行 ////////////////////////////////////////////////////////////////////////
    printf("##  学 号        ");
    for (j = 1; j < M + 1; j++) ///科目存放在1行的1至M+1列
    {
        subjetnum = scores[0][j]; /// 将scores[][];的数据类型double自动调整到int型以便美化排列
        if (subjetnum < 10)
        {
            printf("#  科目%d   ",subjetnum); ///打印int类型的科目序号
        }
        else if (subjetnum < 100)
        {
            printf("#  科目%d  ",subjetnum); ///打印int类型的科目序号
        }
        else if (subjetnum < 1000)
        {
            printf("#  科目%d ",subjetnum); ///打印int类型的科目序号
        }
        else
        {
            printf("#  科目%d",subjetnum); ///打印int类型的科目序号
        }
    }
    printf("#  总 分   #  平均分  ##\n"); ///补齐M+2总分列M+3平均分列

    //美化作用
    printf("########");
    for (i = 0; i < M + 3; i++)
    {
       printf("###########");
    }
    printf("\n");
    /// 结束第一行打印 //////////////////////////////////////////////////////////////////////////

    //打印总分及全部学生分数
    if (answer == N + 1)
    {
        /// 打印随机取值的N行M列数据
        for (i = 1; i < N + 1; i++)         ///从1行至N+1行 共N行的数据
        {
            namenum = scores[i][0];         /// 将scores[][];的数据类型double自动调整到int型以便美化排列
            printf("##  学生%d  \t ", namenum); ///每i行的第一列打印int类型的学生学号序号
            for (j = 1; j < M + 3; j++)  /// 每一行的第二列开始至M+3列打印 M列数据 一列总分 一列平均分
            {
                printf("#  %-8.2lf", scores[i][j]);
            }
            printf("##\n");
        }
        /// 打印N+1行数据
        printf("##  科目总分     ");
        for (j = 1; j < M + 1; j++) ///科目总分存放在N+2行的1至M+1列
        {
            printf("#  %-8.2lf", scores[N+1][j]); ///打印N+2行的1至M+1列
        }
        printf("#          #          ##\n"); ///补齐M+2总分列
        /// 打印N+2行数据
        printf("##  科目平均分   ");
        for (j = 1; j < M + 1; j++) ///科目平均分存放在N+3行的1至M+1列
        {
            printf("#  %-8.2lf", scores[N+2][j]); ///打印N+3行的1至M+1列
        }
        printf("#          #          ##\n"); ///补齐M+3平均分列
    }
    else//打印单个学生分数
    {
        printf("##  学生%d  \t ", answer);
        for (j = 1; j < M + 3; j++)  /// 每一行的第二列开始至M+3列打印 M列数据 一列总分 一列平均分
        {
            printf("#  %-8.2lf", scores[answer][j]);
        }
        printf("##\n");
    }
    //美化作用
    printf("########");
    for (i = 0; i < M + 3; i++)
    {
       printf("###########");
    }
    printf("\n");

    ///继续回到选择界面,进一步操作数据
    printf("按任意键继续...\n");//提示信息
    getch();//等待终端输入任意字符
    goto Choose2;

End:
    ///选择选项0后提示退出程序
    printf("按任意键退出程序...\n");//提示信息
    getch();//等待终端输入任意字符


    return 0;//退出程序
}


/// /////////////////////////////////////////////////////////////////////////////////////////
/*    //打印N名学生的M科目分数 不含总分和平均分
    for (i = 0; i < M ; i++)
    {
        printf("科目%d\t", i + 1); ///打印第一行科目;(如需要以后可建立字符串数组
    }
    printf("\n");

    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M + 1; j++)
        {
        printf("%-8.2lf",scores[i][j]);
        }
    printf("\n");
    }
*/
/// 所有随机数单独存放一个数组////////////////////////////////////////////////随机数间接赋值
/*
    printf("当前N为%d  M为%d\n",N ,M);
    //取N*M个随机数
    for (i = 0; i < N * M; i ++)
    {
        num1 = rand() % 9 + 1;
        num2 = rand() % 10;
        num3 = rand() % 10;
        if (num1 >= 6 && num2 >=6 && num3 >=6  )/// 判断随机数是否能成为100分概率控制在6.5%左右
        {
            scoresrand[i] = 100; ///赋值100分给一元数组scoresrand[N*M]
        }
        else
        {
            scoresrand[i] = num1 * 10 + num2; ///赋值非100分给一元数组scoresrand[N*M]
        }
    }

     //打印N名学生的M科目分数
    for (i = 0; i < M; i++)
    {
        printf("科目%d\t", i + 1); ///打印第一行科目;(如需要以后可建立字符串数组
    }
    printf("\n");
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
        scores[i][j] = scoresrand[j + i * M];
        printf("%-8.2lf",scores[i][j]);
        }
    printf("\n");
    }
*/
/// 可以校验随机数录入/////////////////////////////////////////////////////情况配合随机数间接赋值使用

    //printf("当前N*M/10+1为%d\n",N * M / 10 + 1);
    //打印随机数组看录入情况 分10列打印
/*    for (i = 0; i < N * M / 10 + 1; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (i * 10 + j + 1 > N * M)  ///超出二元数组下标极限时终止打印
            {
             break;
            }
            printf("%-8.2lf",scoresrand[i * 10 + j]);

        }
    printf("\n");
    }

   //打印随机数组校验一般 打出2行即可比对
    for (i = 0; i < Row * Cloumn; i++)
    {
        printf("%-8.2lf",scoresrand[i]);
    }
*/

/// ///////////////////////////////////////////////////////////////////////////////////////////////
