
#include <iostream>

using namespace std;
#define MAXN 150000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

/// Insert Code here!
int BinarySearch(int x, int *a, int n)
{
    if(x >= a[n-1])
        return n;
    else if(x <= a[0])
        return 0;
    int left = 0, right = n-1, mid;
    while(right >= left)
    {
        mid = (left+right) / 2;
        if(a[mid] < x)
            left = mid + 1;
        else    
            right = mid - 1;
    }
    return left;
}

void DichPhai(int *a, int &n, int k)
{
    ++n;
    for(int i = n-1; i > k; --i)
        a[i] = a[i-1];
}
///
void ChenTang_BinarySearch(int x, int *a, int &n){
    int k=BinarySearch(x, a, n); // k là vị trí thích hợp để chèn x để đảm bảo mảng a vẫn tăng dần sau khi chèn
    DichPhai(a, n, k); // Di chuyển các giá trị mảng a sang phải 1 đơn vị bắt đầu từ vị trí k
    a[k]=x;
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
    //cout << BinarySearch(x, a, n);
    ChenTang_BinarySearch(x, a, n);

    XuatMang(a, n);

    return 0;
}

