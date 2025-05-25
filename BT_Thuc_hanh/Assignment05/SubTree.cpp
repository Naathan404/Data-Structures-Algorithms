#include <iostream>
#include <queue>
using namespace std;

struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;

/////
TNODE* makeNode(int x)
{
    TNODE* newNode = new TNODE;
    newNode->key = x;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}

bool Insert(TREE& T, int x)
{
    if(T != NULL)
    {
        if(x == T->key) return false;
        if(T->key > x)
            return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = makeNode(x);
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

bool isSameTree(TNODE* A, TNODE* B)
{
    if(!A && !B) return true;
    if(!A || !B) return false;
    if(A->key != B->key) return false;
    return isSameTree(A->pRight, B->pRight) && isSameTree(A->pLeft, B->pLeft);
}

bool isSubtree(TREE S, TREE T)
{
    if(S == NULL) return true;
    if(T == NULL) return false;
    if(isSameTree(S, T)) return true;
    return isSubtree(S, T->pLeft) || isSubtree(S, T->pRight);
}

/////


int main() {
    TNODE* S, *T;
    S=NULL; T=NULL;

    CreateTree(S);
    CreateTree(T);

    cout <<  boolalpha << isSubtree(S, T);

    return 0;
}
