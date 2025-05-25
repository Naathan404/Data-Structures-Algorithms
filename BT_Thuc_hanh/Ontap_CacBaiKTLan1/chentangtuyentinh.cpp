
#include <iostream>

using namespace std;
#define MAXN 150000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int FindInsertPosition(int *a, int n, int x)
{
    if(x > a[n-1])
        return n;
    // if(x < a[0])
    //     return 0;
    int pos = 0;
    for(int i = 0; i < n; i++)
    {
        if(x >= a[i])
        {
            pos = i + 1;
        }
    }
    return pos;
}

void ChenTang(int x, int *a, int& n)
{
    int k = FindInsertPosition(a, n, x);
    n++;
    for(int i = n-1; i > k; i--)
    {
        a[i] = a[i-1]; 
    }
    a[k] = x;
}

void XuatMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN];
    int x; cin >> x;
    int n; cin >> n;

    NhapMang(a, n);

    ChenTang(x, a, n);

    XuatMang(a, n);

    return 0;
}

