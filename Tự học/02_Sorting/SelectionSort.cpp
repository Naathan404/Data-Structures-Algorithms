#include <iostream>
using namespace std;

// Average case = Best case = Worst case: O(n^2)
// Chon phan tu nho nhat trong mang roi doi cho voi phan tu dau mang
void SelectionSort(int *a, int n)
{
    for(int i = 0; i < n-1; ++i)
    {
        int min = i;
        for(int j = i+1; j < n; ++j)
        {
            if(a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}

// Sap xep giam dan
/*
void SelectionSort(int *a, int n)
{
    for(int i = 0; i < n-1; ++i)
    {
        int max = i;
        for(int j = i+1; j < n; ++j)
        {
            if(a[j] > a[max])
                max = j;
        }
        swap(a[i], a[max]);
    }
}
*/

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int &x : a)
        cin >> x;
    SelectionSort(a, n);
    for(int x : a)
        cout << x << " ";

    return 0;
}