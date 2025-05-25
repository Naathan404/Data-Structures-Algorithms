#include <iostream>
using namespace std;

int FindPosGreatestLesser(int *a, int n, int x)
{
    int l = 0, r = n - 1;
    if(x <= a[0])
        return -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(x > a[m])
            l = m + 1;
        else
            r = m - 1;
    }
    return l - 1;
}

void Insert(int *&a, int &n, int x)
{
    int k = FindPosGreatestLesser(a, n, x);
    n++;
    for(int i = n-1; i > k + 1; i--)
    {
        a[i] = a[i-1];
    }
    a[k + 1] = x;
}

int main()
{   
    int x, n;
    cin >> x >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++)  
        cin >> a[i];

    Insert(a, n, x);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    delete[] a;

    return 0;
}