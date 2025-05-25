#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void SelectionSort(int *a, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

void BubbleSort(int *a, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

void InsertionSort(int *a, int n)
{
    int pos, x;
    for(int i = 1; i < n; i++)
    {
        x = a[i];
        pos = i - 1;
        while(pos >= 0 && a[pos] > x)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

// QuickSort
int Partition(int *a, int l, int r)
{
    int p = a[(l+r) / 2];
    int i = l, j = r;
    while(i <= j)
    {
        while(a[i] < p)
            i++;
        while(a[j] > p)
            j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    // tu l->i-1 nho hon p
    // tu i->r lon hon p
    return i;
}
void QuickSort(int *a, int l, int r)
{
    if(l >= r)
        return;
    int i = Partition(a, l, r);
    QuickSort(a, l, i-1);
    QuickSort(a, i, r);
}


// MergeSort
void Merge(int *a, int l, int r, int m)
{
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while(i < x.size() && j < y.size())
    {
        if(x[i] < y[j])
            a[l++] = x[i++];
        else
            a[l++] = y[j++];
    }
    while(i < x.size())
        a[l++] = x[i++];
    while(j < y.size())
        a[l++] = y[j++];
}
void MergeVer2(int *a, int l, int r, int m)
{
    int n1 = m - l + 1, n2 = r - m;
    int b[n1], c[n2];
    for(int i = 0; i < n1; i++)
        b[i] = a[l + i];
    for(int i = 0; i < n2; i++)
        c[i] = a[m + i + 1];
    int i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(b[i] < c[j])
            a[l++] = b[i++];
        else    
            a[l++] = c[j++];
    }
    while(i < n1)
        a[l++] = b[i++];
    while(j < n2)
        a[l++] = c[j++];
}
void MergeSort(int *a, int l, int r)
{
    if(l >= r) return;
    int m = (l+r)/2;
    MergeSort(a, l, m);
    MergeSort(a, m+1, r);
    MergeVer2(a, l, r, m);
}


// HeapSort
void Heapify(int *a, int n, int i)
{
    int l = 2 * i + 1, r = 2 * i + 2;
    int max = i;
    if(l < n && a[max] < a[l])
        max = l;
    if(r < n && a[max] < a[r])
        max = r;
    if(max != i)
    {
        swap(a[i], a[max]);
        Heapify(a, n, max);
    }
}
void HeapSort(int *a, int n)
{
    // Build max heap
    for(int i = (n/2) - 1; i >= 0; i--)
        Heapify(a, n, i);
    
    for(int i = n-1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}


// HeapSort Again
void Heapify2(int *a, int n, int i)
{
    int l = i * 2 + 1, r = i * 2 + 2;
    int max = i;
    if(l < n && a[max] < a[l])
        max = l;
    if(r < n && a[max] < a[r])
        max = r;
    if(max != i)
    {
        swap(a[i], a[max]);
        Heapify2(a, n, max);
    }
}

void HeapSort2(int *a, int n)
{
    // Build max heap
    for(int i = (n/2) - 1; i >= 0; i--)
        Heapify2(a, n, i);
    
    for(int i = n-1; i >=1; i--)
    {
        swap(a[0], a[i]);
        Heapify2(a, i, 0);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000 - 500;
    }
    
    ////

    //SelectionSort(a, n);
    //BubbleSort(a, n);
    //InsertionSort(a, n);
    //QuickSort(a, 0, n-1);
    //MergeSort(a, 0, n-1);
    //HeapSort(a, n);
    HeapSort2(a, n);

    ////

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

}