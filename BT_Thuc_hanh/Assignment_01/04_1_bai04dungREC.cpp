
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

// Bai 04 nhung dung de quy
int binarySearch_greaterLesser(int *a, int left, int right, int x)
{
    if(x <= a[0])
        return -1;
    if(left > right)
        return left - 1;
    int mid = (left + right) / 2;
    if(a[mid] < x)
        return binarySearch_greaterLesser(a, mid+1, right, x);
    return binarySearch_greaterLesser(a, left, mid-1, x);
}

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binarySearch_greaterLesser(a, 0, n-1, x);

    return 0;
}


