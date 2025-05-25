#include <iostream>
using namespace std;

// int linearSearch(int *a, int n, int x)
// {
//     for(int i = 0; i < n; i++)
//         if(a[i] == x)
//             return i;
//     return -1;
// }

int binarySearch(int *a, int n, int x)
{
    int left = 0, right = n - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(x == a[mid])
            return mid;
        if(x < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int binarySearchGreatestLesser(int *a, int n, int x)
{
    int left = 0, right = n - 1;
    if(x <= a[0])
        return -1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(x > a[mid])
            left = mid + 1;
        else    
            right = mid - 1;
    }
    return left - 1;
}

int main()
{
    int x, n;
    cin >> x >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << binarySearchGreatestLesser(a, n, x);
    delete[] a;
    return 0;
}