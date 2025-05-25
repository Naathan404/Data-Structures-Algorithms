
#include <iostream>
using namespace std;

struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;

// INSERT CODE HERETNODE* 
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

bool searchNode(TREE T, int x)
{
    if(T == NULL)
        return false;
    if(T->key == x)
        return true;
    if(T->key > x)
        return searchNode(T->pLeft, x);
    return searchNode(T->pRight, x);
}
//

int main() {
    TREE T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;
    if(searchNode(T, x)) cout << "true";
    else cout << "false";
    return 0;
}
