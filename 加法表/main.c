#include <stdio.h>
#include <stdlib.h>
 //ѭ������N���µĹ�����������N���µ�ƽ�����ʣ�
 //��ʼֵ����Ҫѭ�����Σ�N�Ρ�



/*void main()
{
    int input_num;//����һ���û����������
    int i;//����һ��ѭ�����Ʊ���
    printf("������һ������");
    scanf("%d", &input_num);//�û�����һ����
    printf("�ӷ���\n");
    for (i = 1; i < input_num; i += 2)//����i ���ڿ��ƴ�ӡ����
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
    int input_num;//����һ���û����������
    int i;//����һ��ѭ�����Ʊ���
    printf("������һ������");
    scanf("%d", &input_num);//�û�����һ����
    printf("�ӷ���\n");
    for (i = 1; i < input_num; i ++)//����i ���ڿ��ƴ�ӡ����
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
