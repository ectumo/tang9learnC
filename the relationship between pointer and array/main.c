#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int nums[6] = {100, 99, 88, 77, 66, 55};
    int nums1[6] = {1100, 199, 188, 177, 166, 155};
    int * ptr_nums; //定义指针
    int * ptr_nums1;// int * ptr_nums = & nums[0]; 等价于int * ptr_nums = nums;
    //ptr_nums = &nums[0]; //将nums[0]赋值给指针变量ptr_nums;

    //ptr_nums = &nums[0];
    //ptr_nums1 = &nums1[0];// 等价于ptr_nums1 = nums1;
    ptr_nums = nums;
    ptr_nums1 = nums1;
    //printf("当前ptr_nums所指向的地址: %p\t nums[0]的内存地址是%p\n",ptr_nums ,&nums);
    //printf("当前ptr_nums1所指向的地址: %p\t nums1[0]的内存地址是%p\n",ptr_nums1, &nums1);
    //printf("nums的地址是: %p\tnums1的地址是: %p\n",&nums, &nums1);
    //printf("nums的地址是: %p\tnums1的地址是: %p\n",ptr_nums, ptr_nums1);

    ///方法一: 调用数组变量
    printf("方法一: 传统方法调用数组变量读取数值\n");
    printf("\n############################################################################################################\n\n");
    for (i = 0; i < 6; i++)
    {
        printf("数组num第%d的个元素的值为: %d\t地址为: %p\t",i + 1, ptr_nums[i], &ptr_nums[i]);
        printf("数组num1第%d的个元素的值为: %d\t地址为: %p\n",i + 1, ptr_nums1[i], &ptr_nums1[i]);

    }
    printf("\n");
    ///方法二: 调用指针实现数据读取 指针位置不变  推荐新手
    printf("方法二: 调用指针实现数据读取 指针位置不变  推荐新手\n");
    printf("\n############################################################################################################\n\n");
    for (i = 0; i < 6; i++)
    {
        printf("数组num第%d的个元素的值为: %d\t地址为: %p\t",i + 1, *(ptr_nums + i), ptr_nums + i);
        printf("数组num1第%d的个元素的值为: %d\t地址为: %p\n",i + 1,*(ptr_nums1 + i), ptr_nums1 + i);

    }
    printf("\n");
    ///方法三: 用指针实现数据读取,指针位置变化 再次使用需要调整指针复位!!!!!否则再次读取数组数据出错!!!!
    printf("方法三: 用指针实现数据读取,指针位置变化\n");
    printf("\n############################################################################################################\n\n");
    for (i = 0; i < 6; i++)
    {
        printf("数组num第%d的个元素的值为: %d\t地址为: %p\t",i + 1, *ptr_nums++, ptr_nums);//*ptr_nums++ 后指针位置发生变化
        printf("数组num1第%d的个元素的值为: %d\t地址为: %p\n",i + 1,*ptr_nums1++, ptr_nums1);//*ptr_nums1++ 后指针位置发生变化

    }
    printf("\n");
    ///方法三为初始化指针,读取错误!!
    printf("方法三为初始化指针,读取错误!!\n");
    printf("\n############################################################################################################\n\n");
    for (i = 0; i < 6; i++)
    {
        printf("数组num第%d的个元素的值为: %d\t地址为: %p\t",i + 1, *ptr_nums++, ptr_nums);//*ptr_nums++ 后指针位置发生变化
        printf("数组num1第%d的个元素的值为: %d\t地址为: %p\n",i + 1,*ptr_nums1++, ptr_nums1);//*ptr_nums1++ 后指针位置发生变化

    }

    printf("\n");
    ///方法三初始化指针,读取正确!!
    printf("方法三初始化指针,读取正确!!\n");
    printf("\n############################################################################################################\n\n");
    ptr_nums1 = nums1;// 初始化指针位置指向nums1[0] 等价于 ptr_nums1 = &nums1[0]
    ptr_nums = nums;// 初始化指针位置指向nums[0]    等价于 ptr_nums = &nums[0]
    for (i = 0; i < 6; i++)
    {
        printf("数组num第%d的个元素的值为: %d\t地址为: %p\t",i + 1, *ptr_nums++, ptr_nums);
        printf("数组num1第%d的个元素的值为: %d\t地址为: %p\n",i + 1,*ptr_nums1++, ptr_nums1);

    }





    return (0);
}
