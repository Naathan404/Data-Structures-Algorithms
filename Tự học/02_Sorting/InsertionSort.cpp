#include <iostream>
using namespace std;


// Thuat toan sap xep chen
void InsertionSort(int *a, int n)
{
    int pos, x;
    for(int i = 1; i < n; i++)
    {
        x = a[i];
        for(pos = i - 1; pos >= 0 && a[pos] > x; --pos)
            a[pos+1] = a[pos];
        a[pos+1] = x;
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
    InsertionSort(a, n);
    Write(a, n);

    delete []a;
    return 0;
}