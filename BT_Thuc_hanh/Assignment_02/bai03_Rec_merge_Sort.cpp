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

void Merge(int *a, int l, int m, int r)
{
    int nb = m - l + 1;
    int nc = r - m;
    int b[nb], c[nc];
    for(int i = 0; i < nb; i++)
        b[i] = a[i];
    for(int i = 0; i < nc; i++)
        c[i] = a[i+m+1];

    int i = 0, j = 0;
    while(i < nb && j < nc)
    {
        if(b[i] < c[j])
            a[l++] = b[i++];
        else 
            a[l++] = c[j++];
    }

    while(i < nb)
        a[l++] = b[i++];
    while(j < nc)
        a[l++] = c[j++];
}

void ProcessingMergeSort(int *a, int l, int r)
{
    if(l >= r)
        return;
    int m = (l + r) / 2;
    ProcessingMergeSort(a, l, m);
    ProcessingMergeSort(a, m+1, r);
    Merge(a, l, m, r);
}

void MergeSort(int *a, int n)
{
    int l = 0, r = n - 1;
    ProcessingMergeSort(a, l, r);
}

int main() {
    int n, a[MAXN];
    NhapMang(a, n);

    MergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
