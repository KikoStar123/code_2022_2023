#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void merge(vector<T> &arr, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    vector<T> temp(right - left + 1);
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int p = 0; p < k; p++)
        arr[left + p] = temp[p];
}

template <typename T>
void merge_sort(vector<T> &arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    vector<int> arr(arr1.size() + arr2.size());

    int i = 0, j = 0, k = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }
    while (i < arr1.size())
        arr[k++] = arr1[i++];
    while (j < arr2.size())
        arr[k++] = arr2[j++];

    merge_sort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}