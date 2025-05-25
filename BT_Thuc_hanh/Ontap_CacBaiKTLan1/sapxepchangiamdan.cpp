#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100

int Input()
{
    int n;
    cin >> n;
    return n;
}

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        cin >> A[i];
}

void SapXep(vector<int>& v)
{
    int n = v.size();
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(v[i] < v[j])
                swap(v[i], v[j]);
        }
    }
}

void SapXepSoChanGiamDan(int*a, int n)
{
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
            v.push_back(a[i]);
    }
    SapXep(v);
    int k = 0; 
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
            a[i] = v[k++];
    }
}

void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
}
int main() {
    int a[MAXN], n;
    n=Input();
    NhapMang(a, n);
    SapXepSoChanGiamDan(a, n);
    XuatMang(a, n);
    return 0;
}
