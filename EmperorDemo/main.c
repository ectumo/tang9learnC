#include <stdio.h>
#include <stdlib.h>
#include <string.h> //֧���ַ�������
#include <time.h>
#include <conio.h>
#include <windows.h> //����sleep����
#include <mmsystem.h>
#pragma comment (lib, "Winmm.Lib")
#define MAX 8

///����MAX=8�����ӣ�����һ�����ӳ�Ϊ�ʺ���Ϸʤ��
int main()
{
    int i, j, temp; // ѭ����������ʱ����;
    int count = 7; //��ʼ��ʱ��¼�����Ӹ���;
    int choice;             //�ʵ۵�ѡ�� 1-4֮��
    int days = 0; //ͳ������
    int randomnum; //��������û�����ʫ
    int serchIndex = -1;         //������Ų�����ʱ��ŵ��±�
    int tempint; // �ȼ��øж���ʱ���
    char emperroName[50];   //�ʵ۵�����
    char tempName[20]; //�����ʱ����
    char names[MAX][20] = {"����", "����" ,"��ʩ" , "���Ѿ�" , "��ԲԲ", "�־���", "С��������"};
    //�����ļ�������
    char levelNames[7][10] = {"��Ӧ", "����", "����", "����", "����", "�ʹ���", "�ʺ�"};
    //�������ÿλ���ӵļ���,ÿ������Ԫ�ض�Ӧÿ�����ӵĵ�ǰ����
    int levels[MAX] = {3, 4, 3, 3, 2, 0, 0, -1};
    //loves�����е�ÿ��Ԫ�ض�Ӧÿ�����ӵĺøж�,��ʼ���,ÿ���˵ĺøж�Ϊ100
    int loves[MAX] = {100, 100, 100, 100, 100, 100, 100, -1};
    /*
    printf("���Դ���: �鿴��ǰ������״̬\n");
    printf("%-14s����\t�øж�\n","����");
    for(i = 0; i < count; i++)
    {
        printf("%-14s%s\t %d\n", names[i], levelNames[levels[i]], love[i]);
    }
    */
    printf("�����뵱ǰ�ʵ۵ĵǼ����ţ�");
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
    PlaySound(TEXT("sounds\\����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    printf("\n");
    printf("\n");
    printf("              �󹬡����     \n");
    printf("\n");
    printf("\n");
    printf("##########################################\n");
    printf("## %-14s#  �󹬵ȼ�  #  �øж� ##\n","����");
    for(i = 0; i < count; i++)
    {
    printf("## %-14s#   %-6s   #   %-3d   ##\n", names[i], levelNames[levels[i]], loves[i]);
    }
    printf("##########################################\n");
    printf("\n");
    Sleep(500);
    days++;
    printf("*************\n");
    printf("  ��ǰ��%d��  \n", days);
    printf("*************\n");
    printf("\n");
    Sleep(500);
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("$                                                   $\n");
    printf("$       �ʵ�  @@%-6s����,��������,�����˳�!       $\n",emperroName);
    printf("$                                                   $\n");
    printf("$  1. �ʵ���ּѡ��:                    (��������)   $\n");
    printf("$  2. ���Ƴ���:                        (�޸�״̬)   $\n");
    printf("$  3. �����乬:                        (ɾ��״̬)   $\n");
    printf("$  4. �����ټ�����ȥС������������¡� (��ʫһ��)   $\n");
    printf("$                                                   $\n");
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("������ѡ��: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1://�ʵ���ּѡ��: \t\t (��������)
        //1.����ǰ��Ҫ�ж������Ƿ����� �����Ƿ��пռ�
        //2.����һ������ ����names[] levelNames[] levels[] loves[] ����;
        PlaySound(TEXT("sounds\\ѡ��.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        if (count < MAX)
        {
            //��Ӳ���
            printf("\n���������������:");
            scanf("%s",names[count]);
            //��count��Ԫ�ص�״̬��ʼ��
            levels[count] = 0;
            loves[count] = 100;
            count++;
            Sleep(500);
            printf("\n��ϲ����<%s>,������һλ����<%s>\n",emperroName,names[count - 1]);
            Sleep(500);
            printf("\n����������øжȽ���10\n");
            for (i = 0; i < count - 1; i++)
            {
                loves[i] -= 10;
            }


        }
        else
        {
           printf("\n����,Ҫע�����尡,���Ѿ�����Ϊ��!\n���ʧ��!\n");
        }
        break;
    case 2://���Ƴ���: \t\t (�޸�״̬)
        //1.�ҵ�Ҫ�������ӵ��±�
        //2.�޸�������ӵ�״̬ �øж�+10,����+1, �����߼��Ͳ�������
        //3.�޸��������ӵ�״̬ ������Ľ���ʺ�, �������Ӻøж��½�-10;
        PlaySound(TEXT("sounds\\����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("\n����,���������Ҫ��������ĵ�����: ");
        scanf("%s",&tempName);
        //�ַ��Ĳ���strcmp, ��Ҫ����,<string.h>
        //strcmp(tempName, "abc") 0-�����ַ������; 1-ǰһ�����ں�һ�� 2-ǰһ��С�ں�һ��
        for (j = 0; j < count; j ++)
        {
            if (strcmp(tempName,names[j]) == 0)
            {
                for (i = 0; i < count; i++)
                {
                    if (strcmp(tempName,names[i]) == 0)
                    {
                        loves[i] += 10;
                        //Ҫע��,�����ܳ�������,levelNames�е��ַ�������
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
            printf("\n�󹬴���:\n");
            printf("\n��ҹ�������䲻��!\n");
            printf("\n���ڻ�����ʱѲ���ڼ䲶��һ��������������%s��Ů��\n",tempName);
            printf("\n�󹬼������ǹ���,���еȼ�����һ��!\n");
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
    case 3://�����乬: \t\t (ɾ��״̬)
        //1.����
        //2.����һ����ֵ��ǰ��һ��Ԫ��
        //3.����--
        //4��������øж�+10
        PlaySound(TEXT("sounds\\�乬.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("\n����,������Ҫ�����乬����������: ");
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
            printf("\n�龪һ��,���˴����乬,�óԳԸúȺ�!\n");
        }
        else
        {
            for (i = serchIndex; i < count -1; i++)
            {
               //names[i] = namse[i + 1]; ��Ϊ���ַ�����,C�����в�֧���ַ������ֱ�Ӹ�ֵ
               //������Ҫʹ��strcpy����ʵ���ַ�����ĸ�ֵ
               strcpy(names[i], names[i + 1]);
               loves[i] = loves[i + 1];
               levels[i] = levels[i + 1];
            }
            count--;
            serchIndex = -1;
        }
        //��������øж�+10
        for (i = 0; i < count; i++)
        {
            loves[i] += 10;
        }
        break;
    case 4://4. �����ټ�����ȥС������������¡�
        PlaySound(TEXT("sounds\\С����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("\n����,���������С����ȥ����������: ");
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
            printf("\n���䴫��:\n");
            printf("\n����������Ժ��һ��װ����Ϊͷ��%s����ǧ��!\n",tempName);
        }
        else
        {
            printf("\n����ʫ�˴�,Ϊ������%sһЦ,��ʫһ��!\n",tempName);
            serchIndex = -1;

            srand((unsigned) time(NULL));
            randomnum = rand() % 5 + 1;
            switch(randomnum)
            {
            case 1:
                printf("һһһһһ\n");
                break;
            case 2:
                printf("����������\n");
                break;
            case 3:
                printf("����������\n");
                break;
            case 4:
                printf("����������\n");
                break;
            case 5:
                printf("����������\n");
                break;
            }
        }
        break;
    default:
        printf("\n����Ϸ��,��������������!\n");
        printf("\n���ϱ���˼����ʱ7��\n");
        days += 6;
        printf("\n");Sleep(200);fflush(stdout);
        printf("ʱ");Sleep(200);fflush(stdout);
        printf("��");Sleep(200);fflush(stdout);
        printf("��");Sleep(200);fflush(stdout);
        printf("��");Sleep(200);fflush(stdout);
        printf(",");Sleep(200);fflush(stdout);
        printf("ת");Sleep(200);fflush(stdout);
        printf("��");Sleep(200);fflush(stdout);
        printf("��");Sleep(200);fflush(stdout);
        printf("��");Sleep(200);fflush(stdout);
        printf("7");Sleep(200);fflush(stdout);
        printf("��\n");
        for( i=0;i<7;i++ )
        {
            Sleep(500);    /* windows ʹ��Sleep������Ϊ���� */
            printf(".");
            fflush(stdout);//ǿ��ˢ�»��棬�����ʾ
        }
        printf("\n");
        fflush(stdin);
        break;
    }
    //���ȼ���������
    if (count >= MAX && levels[0] >= 6)
    {
        PlaySound(TEXT("sounds\\����Ӯ��.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        days++;
        printf("\n�Ѹ�����:�ʵ�[%s]�Եǻ���,��������,���ٺ�,������ɺ󹬰�ҵ!\n", emperroName);
        printf("\n�ʵ�[%s]ִ��%d��,�ڻʵ۵���ҹ������,[%s]�����ʺ�����!\n", emperroName, days, names[0]);
        printf("\n�󹬼���%dλ,�Žụ��,Ϊ���Ϸ���ʹ����������!\n",count);
        printf("\n�ʳ���ÿ���ᴫ���˺�г���������\n",count);
        printf("\n��������˳���Ϸ...\n");//��ʾ��Ϣ
        getch();//�ȴ��ն����������ַ�
        exit (0);
    }
    else
    {
        printf("\n�µ�һ�켴����ʼ��~!\n");
        for( i=0;i<5;i++ )
        {
            Sleep(500);    /* windows ʹ��Sleep������Ϊ���� */
            printf(".");
            fflush(stdout);//ǿ��ˢ�»��棬�����ʾ
        }
        printf("\n");
        goto menu;
    }






    return 0;
}
