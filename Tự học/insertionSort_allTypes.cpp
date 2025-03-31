#include <iostream> 
#include <ctime>
using namespace std;

void Write(int*, int);
void InsertionSort_using_ForLoop(int*, int);
void InsertionSort_using_WhileLoop(int*, int);
void InsertionSort_using_BinarySearch(int*, int);
void BinaryInsertionSort(int*, int);

void SelectionSort(int*, int);
void BubbleSort(int*, int);
int main()
{
    int n; cin >> n;
    int *a = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; ++i)
        a[i] = rand() % 19 - 9;
    /// Import sorting function here! ///
    BubbleSort(a, n);
    /////////////
    Write(a, n);
    delete[] a;
    return 0;
}

void Write(int *a, int n)
{
    for(int i= 0; i < n; ++i)
        cout << a[i] << " ";
}

/// chen truc tiep dung vong lap FOR
void InsertionSort_using_ForLoop(int *a, int n)
{
    int cur_value, pos;
    for(int i = 1; i < n; ++i)
    {
        cur_value = a[i];
        for(pos = i - 1; pos >= 0 && a[pos] > cur_value; --pos)
        {
            a[pos+1] = a[pos];
        }
        a[pos+1] = cur_value;
    }
}

/// chen truc tiep dung vong lap WHILE
void InsertionSort_using_WhileLoop(int *a, int n)
{
    int cur_value, pos;
    for(int i = 1; i < n; ++i)
    {
        cur_value = a[i];
        pos = i - 1;
        while(pos >= 0 && cur_value < a[pos])
        {
            a[pos+1] = a[pos];
            --pos;
        }
        a[pos+1] = cur_value;
    }
}

/// chen dung TIEM KIEM NHI PHAN
int binarySearch(int *a, int n, int val)
{
    int left = 0, right = n-1, mid;
    while(left <= right) 
    {
        mid = (left + right) / 2;
        if(a[mid] == val)
            return mid + 1;
        else if(a[mid] < val)
            left = mid + 1;
        else    
            right = mid - 1;
    }
    return left;
}
void InsertionSort_using_BinarySearch(int *a, int n)
{
    int cur_value, k, pos;
    for(int i = 1; i < n; i++)
    {
        cur_value = a[i];
        k = binarySearch(a, pos + 1, cur_value);
        for(pos = i - 1; pos >= k; --pos)
            a[pos+1] = a[pos];
        a[pos+1] = cur_value;
    }
}

// chen NHI PHAN
void BinaryInsertionSort(int *a, int n)
{
    int curr_value, pos, left, right, mid;
    for(int i = 1; i < n; ++i)  
    {
        curr_value = a[i];
        left = 0; right = i - 1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(a[mid] > curr_value)
                right = mid - 1;
            else
                left = mid + 1;
        }

        for(pos = i - 1; pos >= left; pos--)
        {
            a[pos+1] = a[pos];
        }
        a[pos+1] = curr_value;
    }
}

/// Sap xep chon
void SelectionSort(int *a, int n)
{
    int min;
    for(int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}

/// Sap xep noi bot
void BubbleSort(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = n-1; j > i; --j)
        {
            if(a[j] < a[j-1])
                swap(a[j], a[j-1]);
        }
    }
}