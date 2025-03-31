#include <iostream>
using namespace std;

// Average case: O(n^2)
// Best case: O(n), Worst case: O(n^2)
// Trong moi lan lap (While) se thuc hien 2 thao tac:
//      1) Dua phan tu lon nhat ve cuoi mang, thu hep dau right
//      2) Dua phan tu nho nhat ve dau mang, thu hep dau left

void ShakerSort(int *a, int n)
{
    int left = 0, right = n-1, mark = n-1;
    while(left < right)
    {
        for(int i = left; i < right ; ++i)
        {
            if(a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                mark = i;
            }
        }
        right = mark;
        for(int i = right; i > left; --i)
        {
            if(a[i] < a[i-1])
            {
                swap(a[i], a[i-1]);
                mark = i;
            }
        }
        left = mark;
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
    int *a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> *(a + i);
    ShakerSort(a, n);
    Write(a, n);
    delete[] a;

    return 0;
}