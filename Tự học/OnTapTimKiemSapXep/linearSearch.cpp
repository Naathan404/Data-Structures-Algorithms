#include <iostream>
using namespace std;

int linearSearch(int *a, int n, int x)
{
    for(int i = 0; i < n; i++)
        if(a[i] == x)
            return i;
    return -1;
}   

int main()
{
    int x, n;
    cin >> x >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << linearSearch(a, n, x);
    delete[] a;
    return 0;
}