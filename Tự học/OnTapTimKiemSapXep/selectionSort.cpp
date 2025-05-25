#include <iostream>
using namespace std;

// void InsertionSort(int *a, int n)
// {
//     for(int i = 1; i < n; i++)
//     {
//         int pos = i - 1, x = a[i];
//         while(pos >= 0 && a[pos] > x)
//         {
//             a[pos + 1] = a[pos];
//             pos--;
//         }
//         a[pos + 1] = x;
//     }
// }

void selectionSort(int *a, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[min] < a[j]);
                min = j;
        }
        swap(a[i], a[min]);
    }
}


void Read(int *&a, int &n)
{
    if(n == 0)
    {
        cout << 0;
        return;
    }
    cin >> n;
    a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

void Write(int *a, int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int *a;
    int n;
    Read(a, n);
    selectionSort(a, n);
    Write(a, n);

    return 0;
}