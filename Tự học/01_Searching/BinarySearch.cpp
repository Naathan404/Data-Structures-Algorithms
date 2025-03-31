#include <iostream>
using namespace std;


// Tim kiem phan tu trong mang duoc sap xep TANG DAN
int BinarySearch(int *arr, int size, int value)
{
    int left = 0, right = size-1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] == value)
            return mid;
        else if(arr[mid] > value)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

/*
// Tim kiem phan tu trong mang duoc sap xep GIAM DAN
int BinarySearch(int *arr, int size, int value)
{
    int left = 0, right = size-1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] == value)
            return mid;
        else if(arr[mid] > value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
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
    cout << BinarySearch(Arr, sizeOfArr, value);

    return 0;
}