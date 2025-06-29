#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
#define MAXN 200000

void Nhap(int *arr, int &n){
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
}

//////
#include <vector> 

int Partition(int *a, int l, int r)
{
    int p = a[(l + r) / 2];
    int i = l, j = r;
    while(i <= j)
    {
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if(i <= j) 
        {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    return i;
}

void QuickSort(int* a, int l, int r)
{
    if(l >= r) return;
    int i = Partition(a, l, r);
    QuickSort(a, l, i - 1);
    QuickSort(a, i, r);
}

void findMinDiffPairs(int* a, int n)
{
    if(n < 2) return;
    QuickSort(a, 0, n-1);
    vector<pair<int, int>> res;
    int min = a[1] - a[0];
    for(int i = 0; i < n - 1; i++)
    {
        if(a[i+1] - a[i] < min)
        {
            min = a[i+1] - a[i];
            res.clear();
            res.push_back({a[i], a[i+1]});
        }
        else if(a[i+1] - a[i] == min)
        {
            res.push_back({a[i], a[i+1]});
        }
    }
    for(auto x : res)
    {
        cout << x.first << " " << x.second << endl;
    }
}
////

int main() {
    int arr[MAXN], n;
    Nhap(arr, n);

    findMinDiffPairs(arr, n);

    return 0;
}
