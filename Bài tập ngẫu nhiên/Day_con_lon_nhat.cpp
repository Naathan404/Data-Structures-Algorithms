#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
    // Tao mang gom n so nguyen ngau nhien gioi han -10 đến 10
    int n ; cin >> n;
    clock_t start1 = clock();
    int *a = new int[n];
    srand(time(0)); 
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 19 - 9; 
    }

    // O(n)
    //clock_t start1 = clock();
    int temp1 = 0, ans1 = 0;
    for(int i = 0; i < n; i++)
    {
        temp1 += a[i];
        if(temp1 > ans1)
            ans1 = temp1;
        else if(temp1 < 0)
            temp1 = 0;
    }
    cout << ans1 << endl;
    
    clock_t end1 = clock();
    cout << "Thoi gian thuc thi O(n): " << fixed << setprecision(50) << (end1 - start1) / (double)CLOCKS_PER_SEC << " giay" << endl;

    // O(n^2)
    clock_t start2 = clock();
    int ans2 = 0;
    for(int i = 0; i < n; i++)
    {
        int temp2 = 0;
        for(int j = i; j < n; ++j)
        {
            temp2 += a[j];
            if(temp2 > ans2)
                ans2 = temp2;
        }
    }
    cout << ans2 << endl;
    clock_t end2 = clock();
    cout << "Thoi gian thuc thi O(n^2): " << fixed << setprecision(10) << (end2 - start2) / (double)CLOCKS_PER_SEC << " giay" << endl;

    // O(n^3)
    clock_t start3 = clock();
    int ans3 = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i; j < n; ++j)
        {
            int temp3 = 0;
            for(int k = i; k < j+1; ++k)
            {
                temp3 += a[k];
            }
            if(temp3 > ans3)
                ans3 = temp3;
        }
    }
    cout << ans3 << endl;
    clock_t end3 = clock();
    cout << "Thoi gian thuc thi O(n^3): " << fixed << setprecision(10) << (end3 - start3) / (double)CLOCKS_PER_SEC << " giay" << endl;

    delete[] a;
    return 0;
}