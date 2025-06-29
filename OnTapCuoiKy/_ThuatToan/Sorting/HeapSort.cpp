#include <iostream>
#include <ctime>
using namespace std;

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
        swap(a[i], a[max]);
        Heapify(a, n, max);
    }
}

void HeapSort(int* a, int n)
{
    //Build Max heap
    for(int i = (n / 2) - 1; i >= 0; i--)
        Heapify(a, n, i);
    
    for(int i = n-1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}

void CreateRandomList(int*& a, int& n)
{
    cin >> n;
    a = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 200 - 100;
    }
}

void Output(int* a, int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    int* a;
    CreateRandomList(a, n);
    HeapSort(a, n);
    Output(a, n);
}