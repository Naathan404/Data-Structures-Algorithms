
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

int calculateHIndex(int *citation, int n);

//###INSERT CODE HERE -
int partition(int *a, int l, int r)
{
    int pivot = a[(l+r)/2];
    int i = l, j = r;
    while(i <= j)
    {
        while(a[i] > pivot)
            ++i;
        while(a[j] < pivot)
            --j;
        if(i <= j)
        {
            swap(a[i], a[j]);
            ++i; --j;
        }
    }
    return i;
}

void quickSort(int *a, int l, int r)
{
    if(l >= r) return;
    int i = partition(a, l, r);
    quickSort(a, l, i-1);
    quickSort(a, i, r);
}

// 0 1 3 5 6
int calculateHIndex(int *a, int n)
{
    quickSort(a, 0, n-1);
    int h = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= (i+1))
        {
            h = i+1;
        }
        else    
            break;
    }
    return h;
}

int main()
{
	int* citation;
	int n;
	int i;
	cin >> n;
	
	citation = new int[n];

	for (i = 0; i < n; i++)
		cin >> citation[i];

	cout << calculateHIndex(citation, n);
	return 0;


}
