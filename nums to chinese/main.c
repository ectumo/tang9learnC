/// ����Ŀ�ģ�������������ת���ɴ�д�����֣�����Ϻ��ʵ�λ
/// 1.�ɼ�����          ������������ַ���¼�룬��ȡ��ת���������double���ò�����
/// 2.������֤          ���ڲ����ַ���¼�룬���Ҫ������ַǷ��ַ���
/// 3.���ݸ�ʽ��        ����м�������ȥ�������⣡����β��Ч�㣡ͨ������Ӧ��ÿ���ַ�
///                      ����һ����ӡ��ǩ�����ϵĴ�ӡ�����ϵĲ���
/// 4.ת���ַ�����      �ַ���ת����Լ򵥣�ֻҪȥ���ַ�ƥ��Ȼ��ת�����ɣ���λ���
///   �Ӻ��ʵĵ�λ      �׶αȽϸ��ӡ�������������Ϊ3�����֡���������λ������С��
///                      ͨ���ַ������Ⱥ���,��С����λ�����ֳ���������λ����С������
///                      ��Ҫ����Сѭ��ʮ��ǧ������ѭ�����ڣ��ס�
///
/// ///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 20;             //֧�ֵ�ת��λ����С������1λ�����޸ģ�
int main (void)
{

    int numlen;                 //�ַ�������
    int numilen;                //�������ֳ�;
    int count;                  //����λ������
    int temp;                   //��ʱ�������洢��ʱ����
    int indexpoint = -1;        //��ʼ��С����λ��
    int errorcount = MAX + 1;   //��֤������
    int pointcount = 0;         //��ʼ��С�������
    int i, j;                   //ѭ������
    int zeroindex[MAX];         //���±��¼������ӡ���ձ�ǩ,ֵΪ9��ӡ�����಻��ӡ��
    char snums[MAX];            //����û�����������ַ���
    char uppernums[11][3] = {"��", "Ҽ", "��", "�q", "��", "��",
                                "½", "��", "��", "��", "��"};                   //���ֶ�Ӧת�� ���ַ������Ϊ2byte+1��\0Ϊ3;
    char upperbit1[6][3] = {"ʰ", "��", "Ǫ", "�f", "��", "��"};                 //����λ����Ӧת��     //���ڽ�����ά��
    char upperbit2[3][3] = {"��", "��", "��"};                                   //С��λ����Ӧת��     //�ֿ�����С������
    char nums[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};     //��Ӧ���Ĵ�д

    printf("����һ������������ת���ִ�д�ĳ���"
           "�ɸ�����Ҫ����֧��λ��Ŀǰ֧��%dλ(С������1λ)\n", MAX);
    printf("�����������λ����λ��������ѭ����С��������С��λ���壬����������ӵ�λ\n\n");
    printf("������һ����Ч���֣�");
    scanf("%s", snums);
    /// ��֤�û������Ƿ���Ϲ涨���������������� ///////////////////////
    numlen = strlen(snums); //ȡ�ַ������� numlen - (indexpoint + 1)����λ��
    //��֤�����Ƿ�Ϸ� ���Ȳ�����MAXλ��С������1λ��
    while (errorcount != 0 )
    {
        for (i = 0; i < numlen; i++)
        {
            if ( snums[i] == '.' && pointcount < 1 &&
                 numlen < MAX && indexpoint != 0)                                    //�ж��Ƿ����'.' ���� �������ܳ���1��
            {                                                                        //�ַ����Ȳ��ܳ���λ����С���㲻������λ��
                //printf("%c", snums[i]); //У���ַ�.������ĶԱ�
                indexpoint = i;
                pointcount++;
                continue;
            }
            else if (snums[i] >= '0' && snums[i] <= '9' &&
                      pointcount < 2 && numlen < MAX && indexpoint!= 0)
            {
                //printf("%c", snums[i]); //У���ַ�0-9������ĶԱ�
                continue;
            }
            else //�Ƿ��ַ�(�����ַ�0-9���ַ�.)��С���㳬�ޣ�λ������
            {
                printf("\n");
                printf("�������,λ���������зǷ��ַ���\n");
                printf("\n����������һ����Ч���֣�");
                scanf("%s", snums);
                numlen = strlen(snums);    //���³�ʼ���ַ�����
                pointcount = 0;            //���³�ʼ��С�������
                i = -1;                    //i = -1; ѭ��������i++ �����³�ʼ��i = 0,��ֹi >= numlen����ѭ����
            }
        }
        errorcount = 0;
    }
    /// ��֤�������///////////////////////////////////////////////////////



    /// ���ݸ�ʽ���������㣬��β���㣬ȫ������ȿ����˶��ֲ�ͬ��������µ�״��///////////
    //��ʼ��zeroindex[MAX]Ϊ1
    for (i = 0; i < numlen; i++)
    {
        zeroindex[i] = 9;
    }
    //�ж��ַ������Ƿ����㣬������������Ӧ�ı�ǩ��Ϊ0
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

    //��ӡ����
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("ת������\n");

    //�ȶ�zeroindex�е����Ƿ������������������ǰ�ϲ�
    for (i = 0; i < numlen - 1; i++)
    {
        if (0 == zeroindex[i] && 0 == zeroindex[i + 1])
        {
            zeroindex[i] = 1;
        }
    }

    //��ӡ����
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("�ϲ�����\n");

    //ȥ��ͷ����Ч��,ֱ����λ���ַ���

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

    //��ӡ����
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("ͷ��ȥ��\n");

    //С�����ͷ����Ч��ȥ����ֱ��С�������λ����
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

    //��ӡ����
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("С��ͷ��ȥ��\n");

    //β����Ч��ȥ��
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

    //��ӡ����
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("β��ת������\n");

    //��zeroindex�п�����ת��Ϊ9,ֻ�е�index��Ϊ9ʱ����Ҫ��ӡ
     for (i = 0; i < numlen; i++)
    {
        if (0 == zeroindex[i])
        {
            zeroindex[i] = 9;
        }
    }

    //��ӡ����
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("ת������\n");

    //�ж��Ƿ���Ҫ������λ����״̬
    temp = 0;     //�˴���Ϊͳ����Ч���ļ�����
    for (i = 0; i < numlen; i++)
    {
        if(zeroindex[i] == 9)
        {
            temp ++; //��Ч����1
            break;
        }
    }

    //�ж��Ƿ�������(��û��С����)
    if (indexpoint == -1)
    {
        numilen = numlen;               //�������ȵ����ַ�������
    }
    else
    {
        numilen = indexpoint - 1;       //�������ȵ���С�����±�
    }
    //�ж��Ƿ�����Ч����
    if (temp == 0)
    {
        zeroindex[numilen - 1] = 9;   //����Ϊȫ�㣬�����С����ʱ��������λ��ӡ��ǩ
    }

    //��ӡ����
    for (i = 0; i < numlen; i++)
    {
        printf("%d", zeroindex[i]);
    }
    printf("����ת������\n");


    /// ���ݸ�ʽ����ϣ�//////////////////////////////////////////////////////////

    //��ӡ����������

    printf("\n����İ���������Ϊ��\t");
    for (i = 0; i < numlen; i++)
    {
        printf("%-2c", snums[i]);
    }
    printf("\n\n");

    //��ӡת�����Ĵ�д�����֣�����λ��
    printf("���Ĳ�����λ��дΪ��\t");
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
    printf("���Ĵ���λ��дΪ��\t");
     /// ת������ ///////////////////////////////////////////////////////
     numilen -= 1; // (numilen - 1); ��ȥ��λ��
     count = numilen % 4; //����ѭ�������������λ��
    //ת�������ĺ��ֵ�һ���� ת����������% 4������0�Ķ���λ��
    if (count != 0)
    {
        for(i = 0; i < count; i++)
        {
            for (j = 0; j < 10; j++)                //��(0-9)���ֱȶ�
            {
                if (snums[i] == nums[j] && zeroindex[i] == 9) ///����Ҫ��ľʹ�ӡ
                {
                    printf("%s",uppernums[j]);  //��ӡ��Ӧ�����Ĵ�д
                    break;
                }
            }
            if (zeroindex[i] == 9)
            {
                printf("%s", upperbit1[count - i - 1]);
            }
        }
        //β��ȫΪ��ʱ��������λʱ�����λ��λ����
        if(zeroindex[count]==1&&numilen>4)
            printf("%s",upperbit1[numilen/4+2]);
        numilen -= count; //ת����Ҫ��ȥ%4�Ķ����λ��
    }

    //ת�������ĺ��ֵڶ����� %4����0�Ķ���λ��
    i = numilen;  //ѭ������i ���� ʣ��ת��λ�������λ
    while (i > 0)
    {
             for (j = 0; j < 10; j++)                //��(0-9)���ֱȶ�
            {
                if (snums[count + numilen - i] == nums[j]  && zeroindex[count + numilen - i] == 9 ) //���
                {
                    printf("%s",uppernums[j]);      //��ӡ��Ӧ�����Ĵ�д
                    if (i % 4 == 0)                 //ÿ4λ��һλ
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
    //ת����λ����С��
    //�ж��Ƿ�������(��û��С����)
    if (indexpoint == -1)
    {
        for (j = 0; j < 10; j++)                //��(0-9)���ֱȶ�
        {
            if (snums[numlen - 1] == nums[j] && zeroindex[numlen - 1] == 9) //���
            {
                printf("%s",uppernums[j]);     //��ӡ��Ӧ�����Ĵ�д
                break;
            }
        }
        printf("Բ��\n");
    }
    else
    {
        for (j = 0; j < 10; j++)                //��(0-9)���ֱȶ�
        {
            if (snums[numlen - 1] == nums[j] && zeroindex[i] == 9) //���
            {
                printf("%s",uppernums[j]);     //��ӡ��Ӧ�����Ĵ�д
                break;
            }
        }
        if (temp == 0)
        {
            printf("��Բ��");
        }
        else
        {
            printf("Բ");
        }
        for (i = indexpoint + 1; i < numlen; i++)
        {
            for (j = 0; j < 10; j++)                //��(0-9)���ֱȶ�
            {
                if (snums[i] == nums[j] && zeroindex[i] == 9) //���
                {
                    printf("%s",uppernums[j]);     //��ӡ��Ӧ�����Ĵ�д
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
    printf("����ת��������\n");
    printf("��������˳�\n");
    getchar();
    getchar();
    /// ת�����ֽ��� ////////////////////////////////////////////////////

    return 0;
}
