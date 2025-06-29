#include <bits/stdc++.h>
using namespace std;

struct NODE {
    int key;
    NODE* left;
    NODE* right;
};
typedef NODE* TREE;

NODE* makenode(int x) {
    NODE* p = new NODE;
    p->key = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

bool Insert(TREE& T, int x)
{
    if(T)
    {
        if(T->key == x) return false;
        if(T->key > x) return Insert(T->left, x);
        return Insert(T->right, x);
    }
    T = makenode(x);
    return true;
}

void CreateTree(TREE& T)
{
    T = NULL;
    while(true)
    {
        int x;
        cin >> x;
        if(x == -1) return;
        Insert(T, x);
    }
}

NODE* MaxLeft(TREE T)
{
    return T->right ? MaxLeft(T->right) : T;
}

NODE* MinRight(TREE T)
{
    return T->left ? MinRight(T->left) : T;
}

int Proccess(TREE T)
{
    if(T == NULL) return 0;
    int maxLeft = T->left ? MaxLeft(T->left)->key : INT32_MIN;
    int minRight = T->right ? MinRight(T->right)->key : INT32_MAX;
    if(maxLeft < minRight) return 0;
    return 1 + Proccess(T->left) + Proccess(T->right);
}

void Function(TREE T)
{
    cout << Proccess(T);
}

// INSERT CODE HERE

int main() {
    TREE t;
    CreateTree(t);
    Function(t);
    return 0;
}
