#include <iostream>
using namespace std;

// int LinearSearch(int *a, int n, int x)
// {
//     int index = 0;
//     while(index < n && a[index] != x)
//         ++index;
//     if(index < n) 
//         return index;
//     else    
//         return -1;
// }

/*
for(int i = 0; i < n; ++i)
{
    if(a[i] == x)
        return i;
}
return -1;
*/

int LinearSearch(int *a, int n, int x)
{
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == x)
        return i;
    }
    return -1;
}


int main()
{
    int sizeOfArray, searchValue;
    cin >> sizeOfArray;
    int Array[sizeOfArray];
    for(int &x : Array)
        cin >> x;
    cin >> searchValue;

    cout << LinearSearch(Array, sizeOfArray, searchValue);

    return 0;
}