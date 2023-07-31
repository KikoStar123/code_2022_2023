/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-03-02 23:00:10
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-03-02 23:00:14
 * @FilePath: \CODE\C++(2)\3_2test.cpp\test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum week
{
    sun,
    mon,
    tue,
    wed,
    thu,
    fri,
    sat
};
/*结构体类型struct tm的定义
struct tm
{
    int tm_sec;  //秒，正常范围0-59， 但允许至61
    int tm_min;  //分钟，0-59
    int tm_hour; //小时， 0-23
    int tm_mday; //日，即一个月中的第几天，1-31
    int tm_mon;  //月， 从一月算起，0-11// 1+p->tm_mon;
    int tm_year;  //年， 从1900至今已经多少年// 1900＋ p->tm_year;
    int tm_wday; //星期，一周中的第几天， 从星期日算起，0-6
    int tm_yday; //从今年1月1日到目前的天数，范围0-365
    int tm_isdst; //日光节约时间的旗标
};*/

int main()
{
    enum week today;

    struct tm *p; // struct tm类型的指针，后续使p指向localtime(&t)
    // 接收时间的变量
    time_t t; // 表示时间的unsigned int;
    // time_t其实就是相对于1970年的秒数值

    // 获取时间
    time(&t); // time() 是指返回自 Unix 纪元（January 1 1970 00:00:00 GMT）起的
    // 当前时间的秒数的函数，主要用来获取当前的系统时间，
    // 返回的结果是一个time_t类型。代码中是把这个系统时间写入t的值里面；

    // 调整代码
    p = localtime(&t); // 由于获取的时间是GMT格林威治标准时间，和当地电脑可能不一样，所以要用到localtime转化一下
    //today = p->tm_wday;

    switch (today)
    {
    case mon:
    case tue:
    case wed:
    case thu:
    case fri:
        printf("干活\n");
        break;
    case sat:
    case sun:
        printf("放假\n");
        break;
    default:
        printf("error\n");
    }

    printf("\n");
    printf("%d-%d-%d 星期%d %d:%d:%d\n",
           1900 + p->tm_year, p->tm_mon + 1, p->tm_mday,
           p->tm_wday,
           p->tm_hour, p->tm_min, p->tm_sec);

    return 0;
}
