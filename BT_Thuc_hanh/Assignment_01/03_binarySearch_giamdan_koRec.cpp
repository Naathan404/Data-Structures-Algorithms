
#include <iostream>

using namespace std;

bool binary_search(int *a, int n, int x)
{
    int left = 0, right = n-1, mid;
    if(a[0] == x)
        return true;
    while(left <= right)
    {
        mid = (left+right) / 2;
        if(a[mid] == x)
            return mid;
        else if(a[mid] > x)
            left = mid + 1;
        else    
            right = mid - 1;
    }
    return false;
}

int main() {
    int x; cin >> x;
    int n; cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << std::boolalpha << binary_search(a, n, x);;

    return 0;
}

