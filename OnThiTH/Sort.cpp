#include <iostream>
#include <ctime>
using namespace std;

// SELECTION SORT
void SelectionSort(int* a, int n){
    for(int i = 0; i < n-1; i++)
    {
        int min = i;
        for(int j = i+1; j < n; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            swap(a[i], a[min]);
        }
    }
}
/// INSERTION SORT
void InsertionSort(int* a, int n)
{
    int i = 1, pos, temp;
    while(i < n)
    {
        pos = i - 1;
        temp = a[i];
        while(pos >= 0 && a[pos] > temp)
        {
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = temp;
        i++;
    }
}

/// HEAP SORT
void Heapify(int* a, int n, int i)
{
    int max = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if(l < n && a[l] > a[max])
        max = l;
    if(r < n && a[r] > a[max])
        max = r;
    if(max != i)
    {
        swap(a[max], a[i]);
        Heapify(a, n, max);
    }
}

void HeapSort(int*a, int n)
{
    // build max heap
    for(int i = (n/2) - 1; i >= 0; i--)
    {
        Heapify(a, n, i);
    }

    for(int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}

// MERGESORT
void Merge(int* a, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int b[n1], c[n2];
    for(int i = 0; i < n1; i++)
    {
        b[i] = a[l + i];
    }
    for(int i = 0; i < n2; i++)
    {
        c[i] = a[m + i + 1];
    }

    int i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(b[i] < c[j])
            a[l++] = b[i++];
        else
            a[l++] = c[j++];
    }
    while(i < n1)
    {
        a[l++] = b[i++];
    }
    while(j < n2)
    {
        a[l++] = c[j++];
    }
}   

void MergeSort(int* a, int l, int r)
{
    if(l >= r) return;
    int m = (l+r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m+1, r);
    Merge(a, l, m, r);
}

// QUICKSORT
int Parition(int* a, int l, int r)
{
    int p = a[(l+r)/2];
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
    return i;
}

void QuickSort(int* a, int l, int r)
{
    if(l>= r) return;
    int i = Parition(a, l, r);
    QuickSort(a, l, i-1);
    QuickSort(a, i, r);
}

void CreateRandomArray(int*& a, int& n)
{
    cin >> n;
    a = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 - 50;
    }
}

void PrintArray(int* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int *a, n;
    CreateRandomArray(a, n);
    ////

    //SelectionSort(a, n);
    //InsertionSort(a, n);
    //HeapSort(a, n);
    MergeSort(a, 0, n-1);
    //QuickSort(a, 0, n-1);

    ///
    PrintArray(a, n);

    return 0;
}