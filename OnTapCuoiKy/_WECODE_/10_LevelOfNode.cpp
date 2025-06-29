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
    if(T)
    {
        if(T->key == x)
            return false;
        if(T->key > x)
            return Insert(T->pLeft, x);
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

void PrintLevel(TREE T, int x, int& level)
{
    if(T == NULL) return;
    queue<TNODE*> q;
    q.push(T);
    while(!q.empty())
    {
        int n = q.size();
        level++;
        for(int i = 0; i < n; i++)
        {
            TNODE* p = q.front();
            q.pop();
            if(p->key == x) return;
            if(p->pLeft) q.push(p->pLeft);
            if(p->pRight) q.push(p->pRight);
        }
    }
    level = -1;
}


int main() {
    TNODE* T;
    int x, level=-1;

    cin >> x;

    T = NULL;
    CreateTree(T);

    if(T==NULL) cout << "Empty Tree.";
    else {
        PrintLevel(T, x, level);
        cout << level;
    }
    return 0;
}

