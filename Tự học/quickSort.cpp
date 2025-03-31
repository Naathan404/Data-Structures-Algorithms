#include <iostream>
using namespace std;

int partition(int *a, int l, int r)
{
    int pivot = a[(l+r) / 2];
    int i = l, j = r;
    while(i <= j)
    {
        while(a[i] < pivot)
            i++;
        while(a[j] > pivot)
            j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    return i;
}

void quickSort(int *a, int l, int r)
{
    if(l >= r) return;
    int i = partition(a, l, r);
    quickSort(a, l, i-1);
    quickSort(a, i, r);
}

int main()
{
    int n; cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    quickSort(a, 0, n-1);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    delete[] a;
    return 0;
}