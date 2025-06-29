
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

void FindParent(TREE T, int x)
{
    if(!T->pLeft && !T->pRight) return;
    if((T->pLeft && T->pLeft->key == x) || (T->pRight && T->pRight->key == x))
    {
        cout << T->key << " is parent of " << x << ".";
        return;
    }
    if(T->pLeft) FindParent(T->pLeft, x);
    if(T->pRight) FindParent(T->pRight, x);
}

void PrintParent(TREE T, int x)
{
    if(T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    if(T->key == x)
    {
        cout << x << " has no parent.";
        return;
    }
    if(!Search(T, x))
    {
        cout << "Not found " << x << ".";
        return;
    }
    FindParent(T, x);
}

int main() {
    TREE T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;

    PrintParent(T, x);

    return 0;
}

///

// bool Search(TREE T, int x)
// {
//     if(T == NULL) return false;
//     if(T->key == x) return true;
//     if(T->key > x) return Search(T->pLeft, x);
//     else return Search(T->pRight, x);
//     return false;
// }

// void Proccess(TREE T, int x)
// {
//     if(!T->pLeft && !T->pRight) return;
//     if((T->pLeft && T->pLeft->key == x) || (T->pRight && T->pRight->key == x))
//     {
//         cout << T->key << " is parent of " << x << ".";
//         return;
//     }
//     if(T->pLeft) Proccess(T->pLeft, x);
//     if(T->pRight) Proccess(T->pRight, x);
// }

// void PrintParent(TREE T, int x)
// {
//     if(T == NULL)
//     {
//         cout << "Empty Tree."; return;
//     }
//     if(T->key == x)
//     {
//         cout << x << " has no parent."; return;
//     }
//     if(!Search(T, x))
//     {
//         cout << "Not found " << x << "."; return;
//     }
//     Proccess(T, x);
// }