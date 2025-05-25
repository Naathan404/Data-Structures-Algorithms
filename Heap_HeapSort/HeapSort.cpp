#include <iostream>
using namespace std;

void MaxHeapify(int *a, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;
    if(left < n && a[max] < a[left])
        max = left;
    if(right < n && a[max] < a[right])
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

void HeapSort(int *a, int n)
{
    int size = n;
    BuildMaxHeap(a, n);
    for(int i = n - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        size -= 1;
        MaxHeapify(a, size, 0);

        // In ra mang unsorted sau moi lan heap
        for(int i = 0; i < size; i++)
            cout << a[i] << " ";
        cout << endl;
    }
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
    HeapSort(a, n);
    for(int x : a)
        cout << x << " ";
    cout << endl;
}