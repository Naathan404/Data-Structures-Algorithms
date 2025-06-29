#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

void FindPath(const vector<vector<int>>& G, map<char, int> index, map<int, char> rev_index, int n, char start, char end)
{
    if (start == end)
    {
        cout << start << endl;
        return;
    }

    stack<int> open;
    vector<bool> visited (n, false);
    vector<int> parent(n, -1);
    open.push(index[start]);
    
    while(!open.empty())
    {
        int p = open.top();
        open.pop();
        //if(p == index[end]) break;
        if(visited[p]) continue;
        visited[p] = true;
        for(int x : G[p])
        {
            if(!visited[x])
            {
                open.push(x);
                if (parent[x] == -1)
                    parent[x] = p;
            }
        }
    }

    // Neu end chua duoc tham thi khong co duong di den end => return
    if(visited[index[end]] == false)
    {
        cout << "no_path" << endl;
        return;
    }

    // Neu end da duoc tham
    // Truy vet duong di
    vector<char> path;
    for(int i = index[end]; i != -1; i = parent[i])
    {
        path.push_back(rev_index[i]);
    }
    
    // Xuat duong di
    for(int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, e, m;
    cin >> n >> e;
    vector<vector<int>> G(n);
    map<char, int> index;
    map<int, char> rev_index;
    char c1, c2;
    // Nhap cac dinh va set input
    for(int i = 0; i < n; i++)
    {
        cin >> c1;
        index[c1] = i;
        rev_index[i] = c1;
    }
    // Nhap cac canh vao danh sach ke
    for(int i = 0; i < e; i++)
    {
        cin >> c1 >> c2;
        G[index[c1]].push_back(index[c2]);
    }

    cin >> m;
    char start, end;
    while(m--)
    {
        cin >> start >> end;
        FindPath(G, index, rev_index, n, start, end);
    }
    return 0;
}