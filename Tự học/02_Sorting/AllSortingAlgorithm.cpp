#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

/// Selection Sort
void SelectionSort(int *arr, int n)
{
    for(int i = 0; i < n-1; ++i)
    {
        int min = i;
        for(int j = i+1; j < n; ++j)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

/// Interchange Sort
void InterchangeSort(int *arr, int n)
{
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            if(arr[j] < arr[i])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

/// Bubble Sort
void BubbleSort(int *arr, int n)
{
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = n-1; j > i; --j)
        {
            if(arr[j] < arr[j-1])
            {
                swap(arr[j], arr[j-1]);
            }
        }
    }
}

/// Insertion Sort
void InsertionSort(int *arr, int n)
{
    int pos, x;
    for(int i = 1; i < n; ++i)
    {
        x = arr[i];
        pos = i-1;
        while(pos >= 0 && arr[pos] > x)
        {
            arr[pos+1] = arr[pos];
            --pos;
        }
        arr[pos+1] = x;
    }
}

/// Merge Sort
void Merge(int *arr, int left, int mid, int right)
{
    vector<int> x(arr + left, arr + mid + 1), y(arr + mid + 1, arr + right + 1);
    long unsigned int i = 0, j = 0;
    while(i < x.size() && j < y.size())
    {
        if(x[i] < y[j])
        {
            arr[left] = x[i];
            ++i;
        }
        else
        {
            arr[left] = y[j];
            ++j;
        }
        ++left;
    }
    while(i < x.size())
    {
        arr[left] = x[i];
        ++i;
        ++left;
    }
    while(j < y.size())
    {
        arr[left] = y[j];
        ++j;
        ++left;
    }
}

void MergeSort(int *arr, int left, int right)
{
    if(left < right)
    {
        int mid = (left+right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        Merge(arr, left, mid, right);
    }
}


/// Quick Sort
int Partition(int *arr, int left, int right)
{
    int pivot = arr[(left+right)/2];
    int i = left, j = right;
    while(i <= j)
    {
        while(arr[i] < pivot)
            ++i;
        while(arr[j] > pivot)
            --j;
        if(i <= j)
        {
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    return i;
}

void QuickSort(int *arr, int left, int right)
{
    if(left < right)
    {
        int index = Partition(arr, left, right);
        QuickSort(arr, left, index-1);
        QuickSort(arr, index, right);
    }
}

/// In mang ra man hinh
void Write(int *a, int n)
{
    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; ++i)
        arr[i] = rand() % 1000;

    Write(arr, n); cout << endl;
    QuickSort(arr, 0, n-1); 
    Write(arr, n);

    delete[] arr;
    return 0;
}