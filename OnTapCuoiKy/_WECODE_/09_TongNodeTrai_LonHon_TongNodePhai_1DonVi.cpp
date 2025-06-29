#include <iostream>
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

int CountNode(TREE T)
{
    if(T == NULL) return 0;
    return 1 + CountNode(T->pLeft) + CountNode(T->pRight);
}

void Traversal(TREE T)
{
    if(T == NULL) return;
    Traversal(T->pLeft);
    int a = CountNode(T->pLeft);
    int b = CountNode(T->pRight);
    if(a - b == 1) cout << T->key << " ";
    Traversal(T->pRight);
}

void TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(TREE T)
{
    if(T == NULL)
        return;
    Traversal(T);
}


int main() {
    TREE T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)

    CreateTree(T);

    if(T==NULL) cout << "Empty Tree.";
    else TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T);

    return 0;
}
