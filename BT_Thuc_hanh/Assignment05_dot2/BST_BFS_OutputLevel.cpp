
#include <iostream>
#include <queue>
using namespace std;

struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;

TNODE* MakeNode(int x)
{
    TNODE* p = new TNODE;
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

bool Insert(TREE& T, int x)
{
    if(T != NULL)
    {
        if(T->key == x) return false;
        if(T->key > x) return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = MakeNode(x);
    return true;
}

void CreateTree(TREE& T)
{
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1) return;
        Insert(T, x);
    }
}

void PrintTreeBFS(TREE T)
{
    if(T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    int size = 0;
    queue<TNODE*> q;
    q.push(T);
    while(!q.empty())
    {
        size = q.size();
        TNODE* p;
        for(int i = 0; i < size; i++)
        {
            p = q.front();
            q.pop();
            cout << p->key << " ";
            if(p->pLeft) q.push(p->pLeft);
            if(p->pRight) q.push(p->pRight);
        }
        cout << endl;
    }
}

int main() {
    TNODE* T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTreeBFS(T);
    return 0;
}
