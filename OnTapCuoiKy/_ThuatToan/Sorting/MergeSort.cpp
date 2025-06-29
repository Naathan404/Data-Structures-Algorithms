#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// n1 = m - l + 1, n2 = r - m
// b[i] = a[i + l]
// c[i] = a[m + i + 1]

void Merge(int* a, int l, int m, int r)
{
    vector<int> b(a + l, a + m + 1);
    vector<int> c(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while(i < b.size() && j < c.size())
    {
        if(b[i] < c[j])
            a[l++] = b[i++];
        else
            a[l++] = c[j++];
    }
    while(i < b.size())
        a[l++] = b[i++];
    while(j < c.size())
        a[l++] = c[j++];
}

void MergeSort(int* a, int l, int r)
{
    if(l >= r) return;
    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m , r); 
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
    MergeSort(a, 0, n-1);
    Output(a, n);
}