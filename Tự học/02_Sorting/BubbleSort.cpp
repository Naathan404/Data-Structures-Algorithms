#include <iostream>
using namespace std;

// Thuat toan sap xep noi bot
// Average case: O(n^2)
// Best case: O(n), Worst case: O(n^2)
// Xet tu cuoi mang, doi cho cac phan tu nam ke nhau de dua phan tu nho hon ve dau mang hien tai
// O lan lap sau se khong xet den phan tu nho nhat da dua ve dau mang truoc do

void BubbleSort(int *arr, int n)
{
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = n-1; j > i; --j)
        {
            if(arr[j] < arr[j-1])
            {
                swap(arr[j], arr[j-1]);
            }
        }
    }
        
}

void Write(int *a, int n)
{
    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
}

int main()
{
    int n; cin >> n;
    int arr[n];
    for(int &x : arr)
        cin >> x;
    BubbleSort(arr, n);
    Write(arr, n);

    return 0;
}