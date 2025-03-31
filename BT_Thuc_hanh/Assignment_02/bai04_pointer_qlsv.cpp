#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <limits>
#include <string>
#include <string.h>
using namespace std;
#define MAXN 100

struct Ngay {
    int d, m, y;
};
struct SinhVien{
    char MASV[10];
    char HoTen[MAXN];
    Ngay NamSinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void NhapSV(SinhVien &A)
{
    cin.getline(A.MASV, 10);
    cin.getline(A.HoTen, MAXN);
    cin >> A.NamSinh.d >> A.NamSinh.m >> A.NamSinh.y;
    cin >> A.GioiTinh;
    cin >> A.DiemToan >> A.DiemLy >> A.DiemHoa;
    A.DTB = (A.DiemToan + A.DiemLy + A.DiemHoa) / 3;
}

void Nhap(SinhVien *&A, int &n)
{
    cin >> n;
    A = new SinhVien[n];
    for(int i = 0; i < n; i++)
    {
        cin >> ws;
        NhapSV(A[i]);
        cin.ignore();
    }
}

void Merge(SinhVien *A, int left, int mid, int right)
{
    int nb = mid - left + 1;
    int nc = right - mid;
    SinhVien *b = new SinhVien[nb];
    SinhVien *c = new SinhVien[nc];
    for(int i = 0; i < nb; ++i)
        b[i] = A[left + i];
    for(int i = 0; i < nc; ++i)
        c[i] = A[mid + i + 1];

    int i = 0, j = 0, k = left;
    while(i < nb && j < nc)
    {
        if(strcmp(b[i].MASV, c[j].MASV) > 0)
            A[k++] = b[i++];
        else 
            A[k++] = c[j++];
    }
    while(i < nb)
        A[k++] = b[i++];
    while(j < nc)
        A[k++] = c[j++];

    delete[] b;
    delete[] c;
}

void MergeSort(SinhVien *A, int left, int right)
{
    if(left >= right)
        return;
    int mid = (left + right) / 2;
    MergeSort(A, left, mid);
    MergeSort(A, mid+1, right);
    Merge(A, left, mid, right);
}

void SapXepGiamTheoMASV(SinhVien *A, int n)
{
    int left = 0, right = n - 1;
    MergeSort(A, left, right);
}

void XuatSV(SinhVien A)
{
    cout << A.MASV << "\t";
    cout << A.HoTen << "\t";
    cout << A.NamSinh.d << "/" << A.NamSinh.m << "/" << A.NamSinh.y << "\t";
    cout << A.GioiTinh << "\t";
    cout << A.DiemToan << "\t" << A.DiemLy << "\t" << A.DiemHoa << "\t";
    cout << setprecision(3) << A.DTB;
    cout << endl;
}

void Xuat(SinhVien *A, int n)
{
    if(n == 0)
    {
        cout << "Empty List.";
        return;
    }
    for(int i = 0; i < n; i++)
    {
        XuatSV(A[i]);
    }
}

int main() {
    SinhVien *A;
    int n;
    Nhap(A, n);
    SapXepGiamTheoMASV(A, n);
    Xuat(A, n);
    return 0;
}
