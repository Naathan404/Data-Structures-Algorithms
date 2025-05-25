#include <iostream>
using namespace std;

int checkHeap(int *a, int n)
{
    int heapIndex = 0;
    for(int i = 0; i < (n/2) - 1; i++)
    {
        if(a[2*i + 1] >= a[i] && a[2*i + 2] >= a[i] && heapIndex >= 0)
            heapIndex = 1;
        if(a[2*i + 1] <= a[i] && a[2*i + 2] <= a[i] && heapIndex <= 0)
            heapIndex = -1;
    }
}

void MaxHeapify(int *a, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;
    if(a[max] < a[left] && left < n)
        max = left;
    if(a[max] < a[right] && right < n)
        max = right;
    if(max == i)
        return;
    else
    {
        swap(a[i], a[max]);
        MaxHeapify(a, n, max);
    }
}

void BuildMaxHeap(int *a, int n)
{
    for(int i = (n/2) - 1; i >= 0; i--)
        MaxHeapify(a, n, i);
}

void MinHeapify(int *a, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min = i;
    if(a[min] > a[left] && left < n)
        min = left;
    if(a[min] > a[right] && right < n)
        min = right;
    if(min == i)
        return;
    else
    {
        swap(a[i], a[min]);
        MinHeapify(a, n, min);
    }
}

void BuildMinHeap(int *a, int n)
{
    for(int i = (n/2) - 1; i >= 0; i--)
        MinHeapify(a, n, i);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int &x : a)
        cin >> x;
    BuildMaxHeap(a, n);
    for(int x : a)
        cout << x << " ";
    cout << endl;
    BuildMinHeap(a, n);
    for(int x : a)
        cout << x << " ";
}