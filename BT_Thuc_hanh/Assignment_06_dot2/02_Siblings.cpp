#include <iostream>
using namespace std;
struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;

void CreateEmptyTree(TREE &T) {
    T = NULL;
}
TNODE* CreateTNode(int x) {
    TNODE *p=new TNODE; //cấp phát vùng nhớ động
    p->key = x; //gán trường dữ liệu của node = x
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int Insert(TREE &T, TNODE *p) {
    if (T) {
        if (T->key == p->key) return 0;
        if (T->key > p->key)
            return Insert(T->pLeft, p);
        return Insert(T->pRight, p);
    }
    T = p;
    return 1;
}
void CreateTree(TREE &T){
    int x;
    do {
        cin >> x;
        if(x==-1) break;
        Insert(T, CreateTNode(x));
    }while(true);
}

bool Search(TREE T, int x)
{
    if(T == NULL) return false;
    if(T->key == x) return true;
    if(T->key > x)
        return Search(T->pLeft, x);
    return Search(T->pRight, x);
}

void Find(TREE T, int x)
{
    if(!T->pLeft && !T->pRight) return;
    if((!T->pLeft && T->pRight && T->pRight->key == x) || (!T->pRight && T->pLeft && T->pLeft->key == x))
    {
        cout << x << " has no siblings.";
        return;
    }
    if((T->pLeft && T->pLeft->key == x) || (T->pRight && T->pRight->key == x))
    {
        cout << T->pLeft->key << " and " << T->pRight->key << " are siblings.";
    }
    if(T->pLeft) Find(T->pLeft, x);
    if(T->pRight) Find(T->pRight, x);
}

void FindSiblings(TREE T, int x)
{
    if(T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    if(T->key == x)
    {
        cout << x << " is Root.";
        return;
    }
    if(!Search(T, x))
    {
        cout << "Not found " << x << ".";
        return;
    }
    Find(T, x);
}


int main() {
    TREE T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;

    FindSiblings(T, x);

    return 0;
}

