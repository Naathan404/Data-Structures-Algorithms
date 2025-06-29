#include <iostream>
#include <set>
#include <map>
using namespace std;

void Input(map<int,set<int>>& gr, int n)
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
}

void PrintAllVertices(map<int,set<int>> gr)
{
    for(auto x : gr)
    {
        cout << x.first << " ";
    }
}

int main()
{
    map<int,set<int>> graph;
    int n;
    cin >> n ;
    Input(graph, n);
    PrintAllVertices(graph);
    return 0;
}