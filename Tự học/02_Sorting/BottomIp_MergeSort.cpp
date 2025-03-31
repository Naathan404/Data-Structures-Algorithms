#include <iostream>
using namespace std;

void Copy(int *a, int *b, int start, int end)
{
    for(int i = start; i <= end; ++i)
    {
        a[i] = b[i];
    }
}

void Merge(int *a, int l, int m, int r, int *b)
{
    int i = l, j = m;
    for(int k = l; k <= r; k++)
    {
        if(i < m && (j > r || a[i] <= a[j]))
        {
            b[k] = a[i];
            i++;
        }
        else 
        {
            b[k] = a[j];
            j++;
        }
    }
}

void MergeSort(int *a, int n)
{
    int l, m, r;
    int *b = new int[n];
    for(int width = 1; width <n; width *= 2)
    {
        for(int i = 0; i < n; i = i + 2 * width)
        {
            l = i;
            m = min(i + width, n);
            r = min(i + 2 * width, n) - 1;
            Merge(a, l, m, r, b);
        }
        Copy(a, b, 0, n-1);
    }
}

int main()
{
    


    return 0;
}