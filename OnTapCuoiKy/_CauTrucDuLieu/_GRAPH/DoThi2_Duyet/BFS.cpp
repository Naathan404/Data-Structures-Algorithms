#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

void Input(int v,  map<string, int>& v_index, int e, vector<vector<int>>& G)
{
    string t;
    int index = 0;
    for(int i = 0; i < v; ++i)
    {
        cin >> t;
        v_index[t] = i;
    }
    string e1, e2;
    for (int i = 0; i < e; i++)
    {
        cin >> e1 >> e2; // Nhap 2 dinh ke nhau cua 1 canh
        G[v_index[e1]][v_index[e2]] = 1;
    }
}

void BFS(vector<vector<int>> G, map<string, int> v_index, int v)
{
    string t; cin >> t;
    queue<int> open; // Giong nhu DFS, nhung open thay stack bang queue
    set<int> close;
    open.push(v_index[t]);
    while(!open.empty())
    {
        int m = open.front();
        open.pop();
        if(close.count(m)) continue;
        close.insert(m);
        for(auto it : v_index)
            if(it.second == m)
            {
                cout << it.first << " ";
                break;
            }
        for(int i = 0; i < v; i++)
        {
            if(G[m][i] && close.count(i) == 0)
            {
                open.push(i);
            }
        }
    }
}



int main()
{
    int v, e; //v là số đỉnh, e là số cạnh
    cin>>e>>v;
    vector<vector<int>> G (v, vector<int>(v, 0)); // ma trận kề
    map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
    Input(v, v_index, e, G);
    BFS(G, v_index, v);
    return 0;
}