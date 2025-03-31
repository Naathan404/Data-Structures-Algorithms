#include <iostream>
using namespace std;

// Thuat toan doi cho truc tiep
// O(n^2)
// O moi phan tu dang xet, xet cac cap nghich the voi no, doi cho hai phan tu trong cap nghich the
void InterchangeSort(int *arr, int n)
{
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
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
    int n;
    cin >> n;
    int arr[n];
    for(int &x : arr)
        cin >> x;
    InterchangeSort(arr, n);
    Write(arr, n);

    return 0;
}