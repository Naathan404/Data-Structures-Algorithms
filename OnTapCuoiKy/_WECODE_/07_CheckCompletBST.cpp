#include <iostream>
#include <queue>
#include <cmath>
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

bool IsCompleteBST(const TREE& T)
{
    if(T == NULL) return true;
    queue<TNODE*> q;
    bool foundNULL = false;
    q.push(T);
    while(!q.empty())
    {
        TNODE* p = q.front();
        q.pop();
        if(p == NULL) foundNULL = true;
        else
        {
            if(foundNULL) return false;
            q.push(p->pLeft);
            q.push(p->pRight);
        }
    }
    return true;
}


int main() {
    TREE T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    if(T==NULL) cout << "Empty Tree.";
    else cout << boolalpha << IsCompleteBST(T);

    return 0;
}
