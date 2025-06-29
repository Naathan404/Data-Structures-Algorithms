#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

void Input(vector<vector<pair<int, int>>>& G, map<string, int>& index, map<int, string>& revindex, int nv, int ne)
{
    string v, e1, e2;
    int lenpath;
    for(int i = 0; i < nv; i++)
    {
        cin >> v;
        index[v] = i;
        revindex[i] = v;
    }

    for(int i = 0; i < ne; i++)
    {
        cin >> e1 >> e2 >> lenpath;
        G[index[e1]].push_back({index[e2], lenpath});
    }
}

void PrintMinimumPath(vector<vector<pair<int, int>>>& G, map<string, int>& index, map<int, string>& revindex, int nv, string start, string end)
{
    if(start == end)
    {
        cout << start << " 0\n";
        return;
    }

    vector<int> dist(nv, INT32_MAX);
    vector<int> parent(nv, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int s = index[start], e = index[end];
    dist[s] = 0;
    pq.push({0, s}); // dinh, chi phi

    while(!pq.empty())
    {   
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second, du = p.first;
        if(du > dist[u]) continue;

        for(pair<int, int> x : G[u])
        {
            int w = x.first, dw = x.second;
            if(dist[w] > dist[u] + dw)
            {
                dist[w] = dist[u] + dw;
                parent[w] = u;
                pq.push({dist[w], w});
            }
        }
    }

    if(dist[e] == INT32_MAX)
    {
        cout << "no_path\n";
        return;
    }

    vector<string> path;
    for(int i = e; i != -1; i = parent[i])
    {
        path.push_back(revindex[i]);
    }

    for(int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << dist[e] << endl;
}


int main()
{
    int nv, ne; 
    cin >> nv >> ne;
    vector<vector<pair<int, int>>> G(nv); // int dau la dinh, int sau la trong so
    map<string, int> index;
    map<int, string> revindex;
    
    // Get input
    Input(G, index, revindex, nv, ne);

    // Get test case
    int tc;
    cin >> tc;
    while(tc--)
    {
        string start, end;
        cin >> start >> end;
        PrintMinimumPath(G, index, revindex, nv, start, end);
    }

    return 0;
}