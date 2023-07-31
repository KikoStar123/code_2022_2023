
#include <iostream>
using namespace std;

//比较相邻序列
void Merge(int arr[], int temp[], int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;
    //将较小值放入申请序列
    while (i != mid + 1 && j != end + 1)
    {
        if (arr[i] > arr[j])
            temp[k++] = arr[j++];
        else
            temp[k++] = arr[i++];
    }

    //将多余的数放到序列末尾
    while (i != mid + 1)
        temp[k++] = arr[i++];

    while (j != end + 1)
        temp[k++] = arr[j++];

    //更新序列
    for (i = start; i <= end; i++)
        arr[i] = temp[i];
}

void MergeSort(int arr[], int temp[], int start, int end)
{
    int mid;
    if (start < end)
    {
        //避免堆栈溢出
        mid = start + (end - start) / 2;
        //递归调用
        MergeSort(arr, temp, start, mid);
        MergeSort(arr, temp, mid + 1, end);
        Merge(arr, temp, start, mid, end);
    }
}

int main()
{
    int a[8];
    int i, b[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
    }
    MergeSort(a, b, 0, 7);
    for (i = 0; i < 8; i++)
        cout << a[i] << " ";

    return 0;
}
