
#include <iostream>
using namespace std;

//�Ƚ���������
void Merge(int arr[], int temp[], int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;
    //����Сֵ������������
    while (i != mid + 1 && j != end + 1)
    {
        if (arr[i] > arr[j])
            temp[k++] = arr[j++];
        else
            temp[k++] = arr[i++];
    }

    //����������ŵ�����ĩβ
    while (i != mid + 1)
        temp[k++] = arr[i++];

    while (j != end + 1)
        temp[k++] = arr[j++];

    //��������
    for (i = start; i <= end; i++)
        arr[i] = temp[i];
}

void MergeSort(int arr[], int temp[], int start, int end)
{
    int mid;
    if (start < end)
    {
        //�����ջ���
        mid = start + (end - start) / 2;
        //�ݹ����
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
