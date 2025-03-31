#include <iostream>
#include <vector>
using namespace std;


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

int FindMEX(int *a, int n)
{
    MergeSort(a, 0, n-1);
    if(a[0] != 0)
        return 0;
    for(int i = 0; i < n-1; i++)
    {
        if(a[i+1] - a[i] > 1)
            return a[i] + 1;
    }
    return a[n-1] + 1;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    cout << FindMEX(a, n);

    delete[] a;
    return 0;
}