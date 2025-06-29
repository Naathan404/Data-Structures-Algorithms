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

int Partition(int* a, int l, int r)
{
    int p = a[(l+r)/2];
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
    QuickSort(a, l, i-1);
    QuickSort(a, i, r);
}

void findMinDiffPairs(int* a, int n)
{
    QuickSort(a, 0, n-1);

    int min = a[1] - a[0];
    pair<int, int>* res = new pair<int, int>[200000];
    int dem = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(a[i+1] - a[i] < min)
        {
            min = a[i+1] - a[i];
            dem = 0;
            res[dem++] = {a[i], a[i+1]};
        }
        else if(a[i+1] - a[i] == min)
        {
            res[dem++] = {a[i], a[i+1]};
        }
    }

    for(int i = 0; i < dem; i++)
    {
        cout << res[i].first << " " << res[i].second << endl;
    }
    delete[] res;
}


int main() {
    int arr[MAXN], n;
    Nhap(arr, n);

    findMinDiffPairs(arr, n);

    return 0;
}
