#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// DEFINE SORTING FUNCTIONS
void SelectionSort(vector<int>& a);
//
void InsertionSort(vector<int>& a);
//
void MergeSort(vector<int>& a, int l, int r);
//
void QuickSort(vector<int>& a, int l, int r);
//
void HeapSort(vector<int>& a);
//
void Input(vector<int>& a)
{
    int x;
    while(true)
    {
        cin >> x;
        if(x == -999) break;
        a.push_back(x);
    }
}

void CreateRandomList(vector<int>& a)
{
    int n; cin >> n;
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        a.push_back(rand() % 200 - 100);
    }
}

void Output(vector<int> a)
{
    for(auto x : a)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> a;
    CreateRandomList(a);
    Output(a);
    HeapSort(a);
    Output(a);

    return 0;
}

void SelectionSort(vector<int>& a)
{
    int n = a.size();
    for(int i = 0; i < n-1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        if(min != i)
            swap(a[i], a[min]);
    }
}

void InsertionSort(vector<int>& a)
{
    int n = a.size();
    int i = 1, pos;
    while(i < n)
    {
        pos = i - 1;
        int temp = a[i];
        // Vi a[i] thay doi moi lan a[pos] thay doi, vi the nen so sanh a[pos] voi temp
        while(a[pos] > temp && pos >= 0)
        {
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = temp;
        i++;
    }
}

void Merge(vector<int>& a, int l , int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    vector<int> b(n1);
    vector<int> c(n2);
    for(int i = 0; i < n1; i++)
    {
        b[i] = a[l + i];
    }
    for(int i = 0; i < n2; i++)
    {
        c[i] = a[m + 1 + i];
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
        a[l++] = b[i++];
    while(j < n2)
        a[l++] = c[j++];

}

void MergeSort(vector<int>& a, int l, int r)
{
    if(l >= r) return;
    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m+1, r);
    Merge(a, l, m, r);
}

int Partition(vector<int>& a, int l, int r)
{
    int p = a[(l+r)/2];
    int i = 0, j = a.size() - 1;
    while(i <= j)
    {
        while(a[i] < p) i++;
        while(a[j] > p) j--;  
        if(i <= j)
            swap(a[i++], a[j--]);
    }
    return i;
}

void QuickSort(vector<int>& a, int l, int r)
{
    if(l >= r) return;
    int index = Partition(a, l, r);
    QuickSort(a, 0, index - 1);
    QuickSort(a, index, r);
}

void Heapitfy(vector<int>& a, int n, int i)
{
    int l = 2 * i + 1, r = 2 * i + 2;
    int max = i;
    if(l < n && a[l] > a[max])
        max = l;
    if(r < n && a[r] > a[max])
        max = r;
    if(i != max)
    {
        swap(a[i], a[max]);
        Heapitfy(a, n, max);
    }
}

void HeapSort(vector<int>& a)
{
    int n = a.size();
    for(int i = n/2 - 1; i >= 0; i--)
    {
        Heapitfy(a, n, i);
    }

    for(int i = n - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        Heapitfy(a, i, 0);
    }
}


