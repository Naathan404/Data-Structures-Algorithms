#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
    // Tao mang n so nguyen ngau nhien từ -10 đến 10
    int n ; cin >> n;
    int a[n];
    srand(time(0)); 
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 19 - 9; 
    }

// O(n^2)
    clock_t start2 = clock();
    int ans2 = 0;
    for(int i = 0; i < n-1; i++)
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
    return 0;
}