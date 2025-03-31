
#include <iostream>
using namespace std;

/////////////////////

void Merge(int *a, int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;
    int x[n1], y[n2];
    for(int i = 0; i < n1; i++)
        x[i] = a[i + left];
    for(int i = 0; i < n2; i++)
        y[i] = a[mid + i + 1];

    int i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(x[i] < y[j])
        {
            a[left++] = x[i++];
        }
        else 
        {
            a[left++] = y[j++];
        }
    }
    while(i < n1)
    {
        a[left++] = x[i++];
    }
    while(j < n2)
    {
        a[left++] = y[j++];
    }
}

void MergeSort(int *a, int left, int right)
{
    if(left >= right)
        return;
    int mid = (left+right) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}


void sort(int *a, int n)
{
    int evenCount = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
            evenCount++;
    }
    int evenList[evenCount];
    int index = 0;
    for(int i = 0; i < n; ++i)
        if(a[i] % 2 == 0)
            evenList[index++] = a[i]; 

    MergeSort(evenList, 0, evenCount-1);
    int indexInEvenList = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
        {
            a[i] = evenList[indexInEvenList++];
        }
    }
}
/////////////////////

int main(){
    int *a, n; cin >> n;
    a = new int [n];
    


    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    
    sort(a, n);

    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}
