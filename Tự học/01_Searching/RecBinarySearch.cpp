#include <iostream>
using namespace std;


// Tim kiem phan tu trong mang duoc sap xep TANG DAN
int RecBinarySearch(int *arr, int size, int value, int left, int right)
{
    if(right < left)
        return -1;
    int mid = (right + left) / 2;
    if(arr[mid] == value)
        return mid;
    if(arr[mid] > value)
        return RecBinarySearch(arr, size, value, left, mid - 1);
    return RecBinarySearch(arr, size, value, mid + 1, right);
}

// Tim kiem phan tu trong mang duoc sap xep GIAM DAN
/*
int RecBinarySearch(int *arr, int size, int value, int left, int right)
{
    if(right < left)
        return -1;
    int mid = (right + left) / 2;
    if(arr[mid] == value)
        return mid;
    if(arr[mid] > value)
        return RecBinarySearch(arr, size, value, mid+1, right);
    return RecBinarySearch(arr, size, value, left, mid-1);
}
*/

int main()
{
    int sizeOfArr, value;
    cin >> sizeOfArr;
    int Arr[sizeOfArr];
    for(int &x : Arr)
        cin >> x;
    cin >> value;
    cout << RecBinarySearch(Arr, sizeOfArr, value, 0, sizeOfArr-1);

    return 0;
}