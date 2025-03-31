/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 100000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void hoanvi(int &x, int &y){
    int temp=x;
    x=y;
    y=temp;
}

//###INSERT CODE HERE -
void insertion_sort_decending(int *a, int n)
{
    int cur_value, pos, left, right, mid;
    for(int i = 1; i < n; ++i)
    {
        cur_value = a[i];
        left = 0, right = i - 1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(a[mid] < cur_value)
                right = mid - 1;
            else    
                left = mid + 1;
        }
        for(pos = i - 1; pos >= left; --pos)
        {
            a[pos+1] = a[pos];
        }
        a[pos+1] = cur_value;
    }
}

void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    insertion_sort_decending(a, n);

    XuatMang(a, n);

    return 0;
}
