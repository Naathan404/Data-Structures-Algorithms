#include <iostream>
#include <map>
#include <set>
using namespace std;

void Input(map<int, pair<set<int>, set<int>>>& G, int& n)
{
    cin >> n;
    int i = 0, x, y; 
    while(i < n)
    {
        cin >> x >> y;
        G[x].first.insert(y);
        G[y].second.insert(x);
        i++;
    }
}

int DegreeOfVertex(map<int, pair<set<int>, set<int>>> G, int k)
{
    return G[k].first.size() + G[k].second.size();
}

int main()
{
    // Set.first luu cac canh noi tu canh dang xet den canh do
    // Set.second luu cac canh duoc canh dang xet noi den
    // pair.first.size() = bac ra, pair.second.size() = bac vao
    map<int, pair<set<int>, set<int>>> G;
    int n;
    Input(G, n);
    int K;
    cin >> K;
    cout << DegreeOfVertex(G, K) << endl;

    return 0;
}