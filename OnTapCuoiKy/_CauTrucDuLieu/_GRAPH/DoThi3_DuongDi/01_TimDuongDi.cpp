#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void Input(vector<vector<int>>& G, int m, int n)
{
    int u, v;
    for(int i = 0; i < n; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

// BAI NAY TACH RIENG HAM RA THI BI TIME LIMIT EXCEEDED
// vector<bool> IsHavingPathFromZero(const vector<vector<int>>& G, int m)
// {
//     queue<int> open;
//     vector<bool> close(m, false);
//     open.push(0);
//     close[0] = true;
//     while(!open.empty())
//     {
//         int p = open.front();
//         open.pop();
//         for(int x : G[p])
//         {
//             if(!close[x])
//             {
//                 close[x] = true;
//                 open.push(x);
//             }
//         }
//     }
//     return close;
// }

int main()
{
    // m: so dinh, n: so canh
    int m, n;
    cin >> m >> n;
    vector<vector<int>> G (m, vector<int>(m, 0));
    Input(G, m, n);
    queue<int> open;
    vector<bool> close(m, false);
    open.push(0);
    close[0] = true;
    while(!open.empty())
    {
        int p = open.front();
        open.pop();
        for(int x : G[p])
        {
            if(!close[x])
            {
                close[x] = true;
                open.push(x);
            }
        }
    }
    for(int i = 1; i < m; i++)
    {
        if(close[i])
            cout << "CO\n";
        else
            cout << "KHONG\n";
    }
}