#include <iostream>
#include <set>
#include <map>
using namespace std;

void Input( map<int,set<int>>& gr, int n)
{
    int u, i;
    int index = 0;
    while(index < n)
    {
        cin >> u >> i;
        gr[u].insert(i);
        gr[i].insert(u);
        index++;
    }
    cout << gr.size();
}

int main()
{
    map<int,set<int>> graph;
    int n;
    cin >> n ;
    Input(graph, n);
    return 0;
}