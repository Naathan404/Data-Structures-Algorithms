/// Bai nay cu bi sai 1 test case :(((

#include <iostream>
#include <set>
#include <map>
using namespace std;

void Input(map<int,pair<set<int>, set<int>>>& gr, set<int>& allVertices, int n)
{
    int u, i;
    int index = 0;
    while(index < n)
    {
        cin >> u >> i;
        gr[u].first.insert(i);
        gr[i].second.insert(u);
        allVertices.insert(u);  
        allVertices.insert(i);
        index++;
    }
}

void FindVerticesDegree(map<int,pair<set<int>, set<int>>> gr, set<int> allVer,  int k)
{
    bool isFound = false;
    for(int x : allVer)
    {
        int d = gr[x].first.size() + gr[x].second.size();
        if(d == k)
        {
            cout << x << " ";
            isFound = true;
        }
    }
    if(!isFound) cout << "No find";
}


int main()
{
    map<int,pair<set<int>, set<int>>> graph;
    set<int> allVertices;
    int n;
    cin >> n ;
    Input(graph, allVertices, n);
    int x;
    cin >> x;
    FindVerticesDegree(graph, allVertices, x);
    
    return 0;
}