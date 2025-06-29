#include <iostream>
using namespace std;


/// Best: O(1), Worst: O(n)
bool LinearSearch(int *a, int n, int x)
{
    for(int i = 0; i < n; i++)
        if(a[i] == x) return true;
    return false;
}

bool SentinelLinearSearch(int* a, int n, int x)
{
    int last = a[n-1];
    a[n-1] = x;
    int i = 0;
    while(a[i] != x) i++;
    a[n-1] = last;
    if(i < n-1 || a[n-1] == x) return true;
    return false;
}

/// Best: O(1), khi phan tu can tim nam ngay giua mang
/// Worst: O(logn), khi phan tu can tim nam o hai ria
/// Average: O(logn)
bool BinarySearch(int* a, int n, int x)
{
    int l = 0, r = n-1;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(a[m] == x) return true;
        if(a[m] > x) r = m - 1;
        else l = m + 1;
    }
    return false;
}

void Input(int*& a, int &n)
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

void Output(int* a, int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int *a, n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int x; cin >> x;
    cout << boolalpha << BinarySearch(a, n, x);

    return 0;
}