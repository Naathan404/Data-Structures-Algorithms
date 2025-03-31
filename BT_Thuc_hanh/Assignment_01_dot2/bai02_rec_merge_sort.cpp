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

void Merge(int *a, int left, int mid, int right)
{
    int nb = mid - left + 1;
    int nc = right - mid;
    int b[nb], c[nc];
    for(int i = 0; i < nb; ++i)
        b[i] = a[left + i];
    for(int i = 0; i < nc; ++i)
        c[i] = a[mid + i + 1];
    int i = 0, j = 0;
    while(i < nb && j < nc)
    {
        if(b[i] < c[j])
            a[left++] = b[i++];
        else 
            a[left++] = c[j++];
    }
    while(i < nb)
        a[left++] = b[i++];
    while(j < nc)
        a[left++] = c[j++];
}

void Sort(int *a, int left, int right)
{
    if(left >= right)
        return;
    int mid = (left + right) / 2;
    Sort(a, left, mid);
    Sort(a, mid+1, right);
    Merge(a, left, mid, right);
}

void MergeSort(int *a, int n)
{
    int left = 0, right = n-1;
    Sort(a, left, right);
}


int main() {
    int n, a[MAXN];
    NhapMang(a, n);

    MergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
