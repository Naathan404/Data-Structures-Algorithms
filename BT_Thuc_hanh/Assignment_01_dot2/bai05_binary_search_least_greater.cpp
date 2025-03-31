
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

// bool check(int *a, int x, int n)
// {
//     for(int i = 0; i < n; ++i)
//         if(a[i] == x)
//             return true;
//     return false;
// }

int binary_search_leastGreater_firstOccurrence(int *a, int n, int x)
{
    int left = 0, right = n-1;
    if(x == a[n-1])
        return -1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(a[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return right + 1;
}

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_leastGreater_firstOccurrence(a, n, x);

    return 0;
}