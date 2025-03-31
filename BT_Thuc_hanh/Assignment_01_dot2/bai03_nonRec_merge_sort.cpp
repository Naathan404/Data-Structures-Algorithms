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

void Merge(int *a, int *b, int left, int mid, int right)
{
    int i = left, j = mid;
    for(int k = left; k <= right; ++k)
    {
        if(i < mid && (j > right || a[i] <= a[j]))
            b[k] = a[i++];
        else    
            b[k] = a[j++];
    }
}

void MergeSort(int a[], int n)
{
    int left, middle, right;
    int *b = new int[n];
    for(int i = 1; i < n; i = 2 * i)
    {
        for(int j = 0; j < n; j = j + 2 * i)
        {
            left = j;
            middle = min(i+j, n);
            right = min(j+2*i, n) - 1;
            Merge(a, b, left, middle, right);
        }
        for(int k = 0; k < n; ++k)
        {
            a[k] = b[k];
        }
    }
}


int main() {
    int n, a[MAXN];
    NhapMang(a, n);

    MergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
