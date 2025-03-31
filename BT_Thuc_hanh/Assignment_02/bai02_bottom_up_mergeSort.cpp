#include <iostream>
#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

void NhapMang(int *a, int &n){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void XuatMang(int A[], const int &N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

void Merge()
{
    
}

int main() {
    int n, a[MAXN];
    NhapMang(a, n);

    MergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
