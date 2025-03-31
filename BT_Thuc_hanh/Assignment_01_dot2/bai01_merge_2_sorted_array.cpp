/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#include <climits>
#include <bits/stdc++.h>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
//###INSERT CODE HERE -
void merge_2_Sorted_subArray(int *a, int l, int middle, int r)
{
    int nb = middle - l + 1, nc = r - middle;
    int b[nb], c[nc];
    for(int i = 0; i < nb;++i)
        b[i] = a[l+i];
    for(int i = 0; i < nc; i++)
        c[i] = a[middle + i + 1];
    int i = 0, j = 0, k = l;
    while(i < nb && j < nc)
    {
        if(b[i] < c[j])
        {
            a[k++] = b[i++];
        }
        else
        {
            a[k++] = c[j++];
        }
    }
    while(i < nb)
    {
        a[k++] = b[i++];
    }
    while(j <= r)
    {
        a[k++] = c[j++];
    }
}

void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

	int l=0, r=n-1, middle =(l+r)/2;
    merge_2_Sorted_subArray(a, l, middle, r);

    XuatMang(a, n);

    return 0;
}
