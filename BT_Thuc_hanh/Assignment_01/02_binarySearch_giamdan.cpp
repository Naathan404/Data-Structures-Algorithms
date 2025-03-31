#include <iostream>

using namespace std;

bool binary_search(int*, int, int, int); 

int main() {
    int x; cin >> x;
    int n; cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << std::boolalpha << binary_search(a, 0, n-1, x);

    return 0;
}

bool binary_search(int *a, int left, int right, int x)
{
    if(left > right)
        return false;

    int mid = (left+right) / 2;
    if(a[mid] == x)
        return mid;
    else if(a[mid] < x)
        return binary_search(a, left, mid - 1, x);
    return binary_search(a, mid + 1, right, x);
}

