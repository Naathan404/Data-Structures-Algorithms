
#include <iostream>
#define MAXN 60000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

// Function to sort an array a[] of size 'n'
void binary_insertion_sort(int a[], int n) {
    int i, j, k, selected;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];

        //-- insert code here
        k = 0;
        while(k <= j)
        {
            int mid = (k + j)/2;
            if(a[mid] < selected)
                j = mid - 1;
            else
                k = mid + 1;
        }
        for(j = i - 1; j >= k; --j)
            a[j+1] = a[j];
        a[j+1] = selected;
    }
}
bool is_decending(int A[], int N) {
    for (int i = 0; i < N-1; i++)
        if(A[i]<A[i+1]) return false;
    return true;
}
void XuatMang(int A[], const int &N) {
    // std::cout << is_decending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << "\n";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    binary_insertion_sort(a, n);

    XuatMang(a, n);

    return 0;
}
