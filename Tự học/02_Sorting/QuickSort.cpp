#include <iostream> 
using namespace std;

// Phan hoach Hoare
int Partition(int *arr, int left, int right)
{
    // Chon gia tri cho pivot la gia tri o vi tri middle cua mang arr
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while(i <= j)
    {
        while(arr[i] < pivot)
            ++i;                // Danh dau i la phan tu >= pivot
        while(arr[j] > pivot)
            --j;                // Danh dau j la phan tu <= pivot
        // Neu van thoa dieu kien i <= j, thuc hien doi cho arr[i] va arr[j]
        if(i <= j)
        {
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    // Danh dau i voi y nghia:
    //      +) Doan tu arr[0]->arr[i-1] nho hon pivot
    //      +) Doan tu arr[i]->arr[arr.length()-1] lon hon pivot
    return i;
}

void QuickSort(int *arr, int left, int right)
{
    if(left >= right) return;
    int index = Partition(arr, left, right);
    QuickSort(arr, left, index - 1);  
    QuickSort(arr, index, right);
}

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
    for(int index = 0; index < n; ++index)
        cin >> arr[index];
    QuickSort(arr, 0, n-1);
    Write(arr, n);
    
    delete[] arr;
    return 0;
}

/*
1 2 3 4 5 6 7 8 0

1 2 3 4 0          6 7 8 5
1 2 0   4 3        6 5    8 7
1 0  2   3 4       5 6    7 8
0 1 2 3 4 5 6 7 8

*/