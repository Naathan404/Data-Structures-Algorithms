#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/// KHOI TAO MOT BST
struct Node
{
    int key;
    Node* left;
    Node* right;
};
typedef Node* Tree;

Node* makeNode(int x)
{
    Node* temp = new Node;
    temp->key = x;
    temp->left = temp->right = NULL;
    return temp;
}

bool Insert(Tree& T, int x)
{
    if(T)
    {
        if(T->key == x) return false;
        if(T->key > x) return Insert(T->left, x);
        return Insert(T->right, x);
    }
    T = makeNode(x);
    return true;
}

void CreateTree(Tree& T)
{
    T = NULL;
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1) return;
        Insert(T, x);
    }
}

///
/// MOT SO HAM CHUC NANG KHAC
int FindMax(Tree T)
{
    if(!T) return INT32_MIN;
    if(!T->right) return T->key;
    return FindMax(T->right);
}

int FindMin(Tree T)
{
    if(T == NULL) return INT32_MAX;
    if(!T->left) return T->key;
    return FindMin(T->left);
}

int CountNode(Tree T)
{
    if(T == NULL) return 0;
    return 1 + CountNode(T->left) + CountNode(T->right);
}

int CountInternalNode(Tree T)
{
    if(T == NULL) return 0;
    if(!T->left && !T->right) return 0;
    return 1 + CountInternalNode(T->left) + CountInternalNode(T->right);
}

int CountLeaf(Tree T)
{
    if(T == NULL) return 0;
    if(!T->left && !T->right) return 1;
    return CountLeaf(T->left) + CountLeaf(T->right);
}

int SumAllNode(Tree T)
{
    if(T == NULL) return 0;
    return T->key + SumAllNode(T->left) + SumAllNode(T->right);
}

int FindMaxSumFamily(Tree T)
{
    if(T == NULL) return 0;
    int max = T->key;
    if(T->left) max += T->left->key;
    if(T->right) max += T->right->key;
    int maxLeftSum = FindMaxSumFamily(T->left) > max ? FindMaxSumFamily(T->left) : max;
    int maxRightSum = FindMaxSumFamily(T->right) > max ? FindMaxSumFamily(T->right) : max;
    return maxLeftSum > maxRightSum ? maxLeftSum : maxRightSum;
}

/// DUYET BFS
/// BFS OneLine
void OneLineBFS(Tree T)
{
    if(T == NULL)
    {
        cout << "Cay rong!.";
        return;
    }
    queue<Node*> q;
    q.push(T);
    while(!q.empty())
    {
        Node* p = q.front();
        q.pop();
        cout << p->key << " ";
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
}

/// BFS Level
void LevelBFS(Tree T)
{
    if(T == NULL)
    {
        cout << "Cay rong!.";
        return;
    }
    queue<Node*> q;
    q.push(T);
    while(q.empty() == false)
    {
        int n = q.size();
        Node* p;
        for(int i = 0; i < n; i++)
        {
            p = q.front();
            q.pop();
            cout << p->key << " ";
            if(p->left) q.push(p->left); // Push left vao truoc de xuat tu trai sang phai vi Queue co tinh FIFO
            if(p->right) q.push(p->right);
        }
        cout << endl;
    }
}

/// DUYET DFS
// Doi thu tu 2 thang if ta se dao thu thu cua L va R, stack co tinh LIFO
// Neu push left vao truoc thi se la RL
// Neu push right vao truoc thi se la LR

/// NLR cung giong nhu BFS, chi doi queue thanh stack
void DFS_NLR(Tree T) // NLR
{
    if(T == NULL) return;
    stack<Node*> st;
    st.push(T);
    while(!st.empty())
    {
        Node* p = st.top();
        st.pop();
        cout << p->key << " ";
        if(p->right) st.push(p->right); 
        if(p->left) st.push(p->left);
    }
}

// Duyet het nhanh trai xong pop ra roi chuyen sang nhanh phai
void DFS_LNR(Tree T) // LNR
{
    if(T == NULL) return;
    stack<Node*> st;
    Node* current = T;
    while(current != NULL || !st.empty())
    {
        while(current != NULL)
        {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->key << " ";
        current = current->right;
    }
}

// Dung 2 stack, 1 stack de duyet NRL nhu o tren, 1 de dao nguoc stack kia lai thanh LRN
void DFS_LRN(Tree T)
{
    if(T == NULL) return;
    stack<Node*> st1, st2;
    st1.push(T);
    while(st1.empty() == false)
    {
        Node* p = st1.top();
        st1.pop();
        st2.push(p);
        if(p->left) st1.push(p->left); // push left vao truoc thi moi duoc thu tu NRL => st2 se dao nguoc thanh LRN
        if(p->right) st1.push(p->right);
    }

    while(st2.empty() == false)
    {
        cout << st2.top()->key << " ";
        st2.pop();
    }
}

/// Cac DFS dung de quy
void Preorder(Tree T)
{
    if(T == NULL) return;
    cout << T->key << " ";
    Preorder(T->left);
    Preorder(T->right);
}

void Inorder(Tree T)
{
    if(T == NULL) return;
    Inorder(T->left);
    cout << T->key << " ";
    Inorder(T->right);
}

void Postorder(Tree T)
{
    if(T == NULL) return;
    Postorder(T->left);
    Postorder(T->right);
    cout << T->key << " ";
}

int HeightOf(Tree T)
{
    if(T == NULL) return -1;
    int a = HeightOf(T->left);
    int b = HeightOf(T->right);
    return (a > b ? a : b) + 1;
}

int NonRec_HeightOf(Tree T)
{
    if(T == NULL) return -1;
    int height = -1;
    queue<Node*> q;
    q.push(T);
    while(!q.empty())
    {
        height++;
        Node* p;
        int n = q.size();
        for(int i = 0; i < n; i++)
        {
            p = q.front();
            q.pop();
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
    }
    return height;
}

/// XOA NODE

int main()
{
    Tree T;
    CreateTree(T);
    cout << "Phan tu max: " << FindMax(T) << endl;
    cout << "Phan tu min: " << FindMin(T) << endl;
    cout << "So luong node: " << CountNode(T) << endl;
    cout << "So luong internal node: " << CountInternalNode(T) << endl;
    cout << "So luong node la: " << CountLeaf(T) << endl;
    cout << "Tong cac node: " << SumAllNode(T) << endl;
    cout << "In cay BFS tren 1 dong: ";
    OneLineBFS(T);
    cout << endl << "In cay BFS theo muc: \n";
    LevelBFS(T);
    cout << "\nIn cay DFS tren 1 dong(NLR): ";
    DFS_NLR(T);
    cout << "\nCach de quy: ";
    Preorder(T);
    cout << "\nIn cay DFS tren 1 dong(LNR): ";
    DFS_LNR(T);
    cout << "\nCach de quy: ";
    Inorder(T);
    cout << "\nIn cay DFS tren 1 dong(LRN): ";
    DFS_LRN(T);
    cout << "\nCach de quy: ";
    Postorder(T);
    cout << endl;
    cout << "\nTong 3 node lon nhat: " << FindMaxSumFamily(T) << endl;
    cout << "Chieu cao cua cay la: " << HeightOf(T) << endl;
    cout << "Chieu cao cua cay (khong de quy): " << NonRec_HeightOf(T);

    return 0;
}