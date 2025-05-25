// Tạo một cây nhị phân tìm kiếm T lưu trữ các số nguyên ( giá trị số nguyên < 1000, cây T có thể rỗng). 
// Sau đó kiểm tra đây có phải cây nhị phân tìm kiếm hoàn hảo không?

// Định nghĩa: 
// Perfect Binary Search Tree: A Binary Search Tree is a
// Perfect BST in which all the internal nodes have two children 
// and all leaf nodes are at the same level.


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

int GetTreeDepth(TREE T)
{
    int d = 0;
    while(T != NULL)
    {
        d++;
        T = T->pLeft;
    }
    return d;
}

bool IsPerfectBinaryTree(TREE T)
{
    if(T == NULL) return true;
    int d = GetTreeDepth(T);
    queue<pair<TNODE*, int>> q;    
    q.push({T, 1});
    while(!q.empty())
    {
        TNODE* temp = q.front().first;
        int lv = q.front().second;
        q.pop();

        // Neu la not la thi kiem tra xem level co bang nhau level thap nhat phia trai khong
        if(temp->pLeft == NULL && temp->pRight == NULL)
        {
            if(lv != d) return false;
        }
        else
        {
            // Kiem tra not co phai internal node voi 2 con hay khong
            if(temp->pLeft == NULL || temp->pRight == NULL) return false;

            // Neu la not internal voi 2 con thi xet tiep cac not tiep theo
            q.push({temp->pLeft, lv + 1});
            q.push({temp->pRight, lv + 1});
        }
    }
    return true;
}



int main() {
    TREE T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    if(T==NULL) cout << "Empty Tree.";
    else cout << boolalpha << IsPerfectBinaryTree(T);

    return 0;
}
