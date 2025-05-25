#include <iostream>
#include <queue>
using namespace std;

struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;

TNODE* CreateNode(int x)
{
    TNODE* newNode = new TNODE;
    newNode->key = x;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;
    return newNode;
}
bool Insert(TREE& T, int x)
{
    if(T != NULL)
    {
        if(T->key == x) return false;
        if(T->key > x) return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = CreateNode(x);
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
    queue<TNODE*> q;
    q.push(T);
    while(!q.empty())
    {
        TNODE* p = q.front();
        q.pop();
        cout << p->key << " ";
        if(p->pLeft != NULL)
            q.push(p->pLeft);
        if(p->pRight != NULL)
            q.push(p->pRight);
    }
}

int main() {
    TNODE* T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTreeBFS(T);
    return 0;
}
