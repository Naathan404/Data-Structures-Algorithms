#include <iostream>
using namespace std;

int partition(int *a, int l, int r)
{
    int pivot = a[(l+r)/2];
    int i = l, j = r;
    while(i <= j)
    {
        while(a[i] < pivot)
            ++i;
        while(a[j] > pivot)
            --j;
        if(i <= j)
        {
            swap(a[i], a[j]);
            ++i; --j;
        }
    }
    return i;
}

void quickSort(int *a, int l, int r)
{
    if(l >= r) return;
    int i = partition(a, l, r);
    quickSort(a, l, i-1);
    quickSort(a, i, r);
}

int CashWillBePaid(int priceOfGifts[], int n, int budget)
{
    int left = 0, right = n-1, ans = 0, sum;
    while(left < right)
    {
        sum = priceOfGifts[left] + priceOfGifts[right];
        if(sum <= budget)
        {
            if(sum > ans)
                ans = sum;
            ++left;
        }
        else 
            --right;
    }
    return ans;
}

int main()
{
    int n, budget;
    cin >> n >> budget;
    int *priceOfGifts = new int[n];
    for(int i = 0; i < n; i++)
        cin >> priceOfGifts[i];

    quickSort(priceOfGifts, 0, n-1);
    cout << CashWillBePaid(priceOfGifts, n, budget);

    delete[] priceOfGifts;
    return 0;
}
