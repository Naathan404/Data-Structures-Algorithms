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
    TNODE* newNode = new TNODE;
    newNode->key = x;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}

bool InsertNode(TREE& T, int x)
{
    if(T != NULL)
    {
        if(T->key == x) return false;
        if(T->key > x)
            return InsertNode(T->pLeft, x);  
        return InsertNode(T->pRight, x);
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
        InsertNode(T, x);
    }
}

bool IsCompleteBST(TREE T)
{
    if(T == NULL) return true;
    bool foundNULL = false;

    queue<TNODE*> q;
    q.push(T);
    while(!q.empty())
    {
        TNODE* temp = q.front();
        q.pop();

        if(temp == NULL)
            foundNULL = true;
        else
        {
            if(foundNULL) return false;
            q.push(temp->pLeft);
            q.push(temp->pRight);
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

