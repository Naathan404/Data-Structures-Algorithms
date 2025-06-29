#include <iostream>
#include <ctime>
using namespace std;

void Insertion(int* a, int n)
{
    int i = 1, pos;
    while(i < n)
    {
        int tem = a[i];
        pos = i - 1;
        while(pos >= 0 && a[pos] > tem)
        {
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = tem;
        i++;
    }
}


void CreateRandomList(int*& a, int& n)
{
    cin >> n;
    a = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 200 - 100;
    }
}

void Output(int* a, int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    int* a;
    CreateRandomList(a, n);
    Insertion(a, n);
    Output(a, n);
}