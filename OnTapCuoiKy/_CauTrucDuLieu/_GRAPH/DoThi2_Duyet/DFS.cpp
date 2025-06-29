#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;

void Input(vector<vector<int>>& matrix, map<string, int>& v_index, int v, int e)
{
    string t;
    // Nhap cac dinh
    for(int i = 0; i < v; i++)
    {
        cin >> t;
        v_index[t] = i;
    }

    // Nhap cac canh
    string e1, e2;
    for(int i = 0; i < e; i++)
    {
        cin >> e1 >> e2;
        matrix[v_index[e1]][v_index[e2]] = 1;
    }
}

void DFS(vector<vector<int>> matrix, map<string, int> v_index, string start)
{
    stack<int> open;
    set<int> close;
    open.push(v_index[start]);
    while(!open.empty())
    {
        int p = open.top();
        open.pop();

        // neu p da thuoc close thi bo qua
        if(close.count(p)) continue;

        // them p vao close
        close.insert(p);

        // in dinh p
        for(auto it : v_index)
        {
            if(p == it.second)
            {
                cout << it.first << " ";
            }
        }

        // Kiem tra neu q ke p va q khong thuoc close thi dua q vao open
        for(int q = 0; q < matrix[0].size(); q++)
        {
            if(matrix[p][q] && close.count(q) == 0)
            {
                open.push(q);
            }
        }
    }
}

int main()
{
    // v: number of vertices, e: number of edges
    int v, e;
    cin >> e >> v;
    vector<vector<int>> matrix (v, vector<int>(v, 0));
    map<string, int> v_index;
    Input(matrix, v_index, v, e);
    string start;
    cin >> start;
    DFS(matrix, v_index, start);

    return 0;
}


/// === CODE WECODE CU ===
// void Input(int v,  map<string, int>& v_index, int e, vector<vector<int>>& G)
// {
//     string t;
//     int index = 0;
//     for(int i = 0; i < v; ++i)
//     {
//         cin >> t;
//         v_index[t] = i;
//     }
//     string e1, e2;
//     for (int i = 0; i < e; i++)
//     {
//         cin >> e1 >> e2; // Nhap 2 dinh ke nhau cua 1 canh
//         G[v_index[e1]][v_index[e2]] = 1;
//     }
// }

// void DFS(vector<vector<int>> G, map<string, int> v_index, int v)
// {
//     string t; cin >> t;
//     stack<int> open;
//     set<int> close;
//     open.push(v_index[t]);
//     while(!open.empty())
//     {
//         int m = open.top();
//         open.pop();
//         if(close.count(m)) continue;
//         close.insert(m);
//         for(auto it : v_index)
//             if(it.second == m)
//             {
//                 cout << it.first << " ";
//                 break;
//             }
//         for(int i = 0; i < v; i++)
//         {
//             if(G[m][i] && close.count(i) == 0)
//             {
//                 open.push(i);
//             }
//         }
//     }
// }
// ///

 
// int main()
// { 
//     int v,e; //v là số đỉnh, e là số cạnh
//     cin>>e>>v;
//     vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
//     map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
//     Input(v,v_index,e,G);
//     DFS(G,v_index,v);
//     return 0;
// }