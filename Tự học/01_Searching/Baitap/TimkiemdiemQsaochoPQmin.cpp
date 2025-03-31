#include <iostream>
#include <math.h>
using namespace std;

struct Point
{
    float x, y;
};
void Nhap(Point *A, int n);
int FindPointQ(Point *A, int n, Point P);

int main()
{
    int n;
    cin >> n;
    Point *A = new Point[n], P;
    Nhap(A, n);
    cin >> P.x >> P.y;
    cout << FindPointQ(A, n, P);

    return 0;
}

void Nhap(Point *A, int n)
{
    for(int i = 0; i < n; ++i)
        cin >> A[i].x >> A[i].y;
}

int FindPointQ(Point *A, int n, Point P)
{
    int ans = 0;
    float minDistance = sqrt(pow(A[0].x - P.x, 2) + pow(A[0].y - P.y, 2));
    for(int index = 1; index < n; ++index)
    {
        float currDistance = sqrt(pow(A[index].x - P.x, 2) + pow(A[index].y - P.y, 2));
        if(currDistance < minDistance)
        {
            minDistance = currDistance;
            ans = index;
        }
    }
    return ans;
}