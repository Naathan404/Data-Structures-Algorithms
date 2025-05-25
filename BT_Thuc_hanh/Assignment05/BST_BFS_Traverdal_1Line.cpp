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
        if(x == -1) return;
        AddNewLeaf(T, x);
    }
}


void PrintTreeBFS(TREE T)
{
    if(T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    queue<TNODE*> Tqueue;
    Tqueue.push(T);
    while(!Tqueue.empty())
    {
        TNODE* curNode = Tqueue.front();
        Tqueue.pop();
        if(curNode != NULL)
            cout << curNode->key << " ";
        else
            cout << endl;
        if(curNode->pLeft != NULL)
            Tqueue.push(curNode->pLeft);
        if(curNode->pRight != NULL)
            Tqueue.push(curNode->pRight);
    }
}

int main() {
    TNODE* T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTreeBFS(T);
    return 0;
}
