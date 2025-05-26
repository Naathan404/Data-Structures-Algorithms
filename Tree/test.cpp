#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TNODE
{
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
}

bool Insert(TREE& T, int x)
{
    if(T)
    {
        if(T->key == x) return false;
        if(T->key > x)
            return Insert(T->pLeft, x);\
        return Insert(T->pRight, x);
    }
    T = MakeNode(x);
    return true;
}

void CreateTree(TREE& T)
{
    int x;
    while(1)
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

int SumAllNode(TREE T)
{
    if(T == NULL) return 0;
    return T->key + SumAllNode(T->pLeft) + SumAllNode(T->pRight);
}

int FindMax(TREE T)
{
    if(T == NULL) return -1;
    if(T->pRight == NULL)   
        return T->key;
    return FindMax(T->pRight);
}

void OneLineOutput(TREE T)
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
        if(p->pRight)
            q.push(p->pRight);
    }
}

void LevelOutput(TREE T)
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
        TNODE* p;
        int n = q.size();
        for(int i = 0; i < n; i++)
        {
            p = q.front();
            q.pop();
            cout << p->key << " ";
            if(p->pLeft != NULL)
                q.push(p->pLeft);
            if(p->pRight)
                q.push(p->pRight);
        }
        cout << endl;
    }
}



int main()
{
    TREE T = NULL;
    CreateTree(T);
    cout << "So node: " << CountNode(T);
    cout << "\nTong cac node: " << SumAllNode(T);
    cout << "\nMax = " << FindMax(T) << endl;
    OneLineOutput(T);
    cout << endl;
    LevelOutput(T);
 
    return 0;
}