
#include <iostream>
using namespace std;

struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;

TNODE* CreateNode(int x)
{
    TNODE* p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

int Insert(TREE& T, int x)
{
    TNODE* p = new TNODE;
    if(T != NULL)
    {
        if(T->key == x) return 0;
        if(T->key > x) return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = CreateNode(x);
    return 1;
}

void CreateTree(TREE &T)
{
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1) return;
        Insert(T, x);
    }
}

void CountLeaf(TREE T, int &count)
{
    if(T == NULL) return;
    if(T->pLeft == NULL && T->pRight == NULL)
    {
        count++;
        return;
    }
    CountLeaf(T->pLeft, count);
    CountLeaf(T->pRight, count);
}

int main() {
    TREE T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int count =0;
    CountLeaf(T, count);
    cout << count;
    return 0;
}
