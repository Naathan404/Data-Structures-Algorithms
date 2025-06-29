#include <iostream>
#include <ctime>
using namespace std;

int Partition(int* a, int l, int r)
{
    int pivot = a[(l+r)/2];
    int i = l, j = r;
    while(i <= j)
    {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    return i; // l -> i - 1 be hon pivot, i -> r lon hon pivot
}

void QuickSort(int* a, int l, int r)
{
    if(l >= r) return;
    int index = Partition(a, l, r);
    QuickSort(a, l, index - 1);
    QuickSort(a, index, r);
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
    QuickSort(a, 0, n-1);
    Output(a, n);
}