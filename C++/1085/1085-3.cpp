/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-05-26 09:25:53
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-05-26 09:34:59
 * @FilePath: \cpp\1085\1085-3.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%
 */
#include <iostream>
using namespace std;

int sort(int arr[], int temp[], int begin, int mid, int end)
{
    int i = begin;
    int j = mid;
    int k = begin;
    while ()
}

int margesort(int arr[], int temp[], int begin, int end)
{
    int mid;
    if (begin < end)
    {
        mid = (begin + end) / 2;
        margesort(arr, temp, begin, mid);
        margesort(arr, temp, mid + 1, end);
        sort(arr, temp, begin, mid, end);
    }
}
int main()
{
    int a[8], b[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
    }
    int begin = 0;
    int end = 7;
    margesort(a, b, begin, end);
}