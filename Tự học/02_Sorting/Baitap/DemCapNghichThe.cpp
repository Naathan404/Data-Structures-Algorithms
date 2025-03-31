#include <iostream>
#include <vector>
using namespace std;

int Merge(int *arr, int left, int mid, int right)
{
    vector<int> x(arr + left, arr + mid + 1);
    vector<int> y(arr + mid + 1, arr + right + 1);
    long unsigned int i = 0, j = 0;             // Vi kieu du lieu cua vector.size() la long unsigned int
    int ans = 0;
    while(i < x.size() && j < y.size())
    {
        if(x[i] <= y[j])
        {
            arr[left] = x[i];
            ++i;
            ++left;
        }
        else 
        {
            ans += x.size() - i;
            arr[left] = y[j];
            ++j;
            ++left;
        }
    }
    while(i < x.size())
    {
        arr[left] = x[i];
        ++i;
        ++left;
    }
    while(j < y.size())
    {
        arr[left] = y[j];
        ++j;
        ++left;
    }
    return ans;
}

int MergeSort(int *arr, int left, int right)
{
    int cnt = 0;
    int mid = (left+right)/2;
    if(left < right)
    {
        cnt += MergeSort(arr, left, mid);
        cnt += MergeSort(arr, mid+1, right);
        cnt += Merge(arr, left, mid, right);
    }
    return cnt;
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
        cin >> *(arr + i);
    cout << MergeSort(arr, 0, n-1);

    delete[] arr;
    return 0;
}