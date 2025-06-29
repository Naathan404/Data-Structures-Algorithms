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

////
#include <stack>
void PrintTree(const TREE& T)
{
    if(T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    stack<TNODE*> st;
    TNODE* curr = T;
    while(curr != NULL || !st.empty())
    {
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->pLeft;
        }
        curr = st.top();
        st.pop();
        cout << curr->key << " ";
        curr = curr->pRight;
    }
}

////


int main() {
    TNODE* T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTree(T);
    return 0;
}
