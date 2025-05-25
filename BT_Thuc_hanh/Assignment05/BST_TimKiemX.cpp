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
    TNODE* newNode = new TNODE;
    newNode->key = x;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;
    return newNode;
}

int AddNewLeaf(TREE &T, int x)
{
    if(T != NULL)
    {
        if(T->key == x)
            return 0;
        if(T->key > x)
        {
            return AddNewLeaf(T->pLeft, x);
        }
        return AddNewLeaf(T->pRight, x);
    }
    T = CreateNode(x);
    return 1;
}

void CreateTree(TREE &T)
{
    while(true)
    {
        int x;
        cin >> x;
        if(x == -1)
            return;
        AddNewLeaf(T, x);
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

int SumInternalNode(TREE T)
{
    if(T == NULL || (!T->pLeft && !T->pRight))
        return 0;
    else
        return  SumInternalNode(T->pLeft) + SumInternalNode(T->pRight);
}


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
