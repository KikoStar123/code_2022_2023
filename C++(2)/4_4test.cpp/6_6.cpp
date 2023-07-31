#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template<typename T>
void merge_sort(T arr[], int len) {
    T* a = arr;
    T* b = new T[len];
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        T* temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}


template <typename T>
T *MerSORT(T *l1, T *l2, int size1, int size2, int &size3)
{
    T temp;
    T l3[size1 + size2];
    int i, j, k;
    k = 0;
    for (int u = 0; u < size1; u++)
        l3[u] = l1[u];
    for (i = 0; i < size1; i++)
    {
        T MIN;
        for (j = 0; j < size2; j++)
            MIN = min(l1[i], l2[j]);
        l3[k] = MIN;
        k++;
    }
    return l3;
}

int main()
{
    int b[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int c_size;
    int *c = MerSORT(a, b, 10, 10, c_size);
    for (int i = 0; i < c_size; i++)
        cout << c[i] << " ";
    return 0;
}