#include <iostream>
using namespace std;

template <typename T>
T *del(T arr1[], int &end)
{
    T *arr = new T[end];
    int k = 1;
    arr[0] = arr1[0];
    for (int i = 1; i < end; i++)
    {
        if (arr1[i] != arr[k - 1])
        {
            arr[k++] = arr1[i];
        }
    }
    T *arr2 = new T[k];
    for (int i = 0; i < k; i++)
        arr2[i] = arr[i];
    delete[] arr;
    end = k;
    return arr2;
}

template <typename T>
void sort(T arr[], int &end)
{
    for (int i = 0; i < end; i++)
    {
        for (int j = end - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

template <typename T>
void print(T arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
int main()
{
    int N;
    int *arr;
    cin >> N;
    arr = new int[N];
    for (int p = 0; p < N; p++)
        cin >> arr[p];
    sort(arr, N);
    // print(arr, N);
    int *arr2;
    arr2 = del(arr, N);
    cout << N << endl;
    print(arr2, N);
    return 0;
}