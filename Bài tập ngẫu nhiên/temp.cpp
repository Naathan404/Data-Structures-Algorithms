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
    return 0;
}