#include <vector>
#include <iostream>
using namespace std;

void Input(vector<vector<int>> G, int v, int e)
{
    int i = 0;
    int x, y;
    while(i < e)
    {
        cin >> x >> y;
        G[x][y] = 1;
        G[y][x] = 1;
        i++;
    }

    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

 
int main()
{
    int v,e; //v là số đỉnh, e là số cạnh
    cin>>e>>v;
    vector<vector<int>> G (v,vector<int>(v,0));
    Input(G,v,e);
    return 0;
}
