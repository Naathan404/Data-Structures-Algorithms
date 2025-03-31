#include <iostream>
#include <vector>
using namespace std;

// Tron hia mang da duoc sap xep thanh mot mang da duoc sap xep
void Merge(int *arr, int left, int mid, int right)
{
    vector<int> x(arr + left, arr + mid + 1);
    vector<int> y(arr + mid + 1, arr + right + 1);
    int i = 0, j = 0;
    while(i < x.size() && j < y.size())
    {
        if(x[i] <= y[j])
        {
            arr[left] = x[i];
            ++i;
        }
        else
        {
            arr[left] = y[j];
            ++j;
        }
        ++left;
    }
    while (i < x.size())
    {
        arr[left] = x[i];
        ++left;
        ++i;
    }
    while (j < y.size())
    {
        arr[left] = y[j];
        ++left;
        ++j;
    }
}

void MergeSort(int *arr, int left, int right)
{
    if(left >= right) return;
    int mid = (left+right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);
    Merge(arr, left, mid, right);
}

void Write(int *a, int n)
{
    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    MergeSort(arr, 0, n-1);
    Write(arr, n);

    delete[] arr;
    return 0;
}