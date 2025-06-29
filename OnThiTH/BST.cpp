#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
};

Node* makeNode(int x)
{
    Node* p = new Node;
    p->key = x;
    p->left = p->right = NULL;
}

typedef Node* Tree;

bool Insert(Tree& T, int x)
{
    if(T != NULL)
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

// DFS using recursion
void Inorder(const Tree& T)
{
    if(T == NULL) return;
    Inorder(T->left);
    cout << T->key << " ";
    Inorder(T->right);
}

void Preorder(const Tree& T)
{
    if(T == NULL) return;
    cout << T->key << " ";
    Preorder(T->left);
    Preorder(T->right);
}

void Postorder(const Tree& T)
{
    if(T == NULL) return;
    Postorder(T->left);
    Postorder(T->right);
    cout << T->key << " ";
}

// DFS non recursive
void Inorder1(const Tree& T) // LNR
{
    if(T == NULL) return;
    stack<Node*> st;
    Node* curr = T;
    while(curr != NULL || !st.empty())
    {
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
    cout << endl;
}

void Preorder1(const Tree& T) // NLR
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
    cout << endl;
}

void Postorder1(const Tree& T) // LRN
{
    if(T == NULL) return;
    stack<Node*> s1, s2;
    s1.push(T);
    while(!s1.empty())
    {
        Node* p = s1.top();
        s1.pop();
        s2.push(p);
        if(p->left) s1.push(p->left);
        if(p->right) s1.push(p->right);
    }

    while(!s2.empty())
    {
        Node* p = s2.top();
        s2.pop();
        cout << p->key << " ";
    }
    cout << endl;
}


// BFS
void BFS_1Line(const Tree& T)
{
    if(T == NULL) return;
    queue<Node*> q;
    q.push(T);
    while(q.empty() == false)
    {
        Node* p = q.front();
        q.pop();
        cout << p->key << " ";
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    cout << endl;
}

void BFS_Level(const Tree& T)
{
    if(T == NULL) return;
    queue<Node*> q;
    q.push(T);
    while(q.empty() == false)
    {
        int n = q.size();
        for(int i = 0; i < n; i++)
        {
            Node* p = q.front();
            q.pop();
            cout << p->key << " ";
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        cout << endl;
    }
}

int CountNode(const Tree& T) // recursion
{
    if(T == NULL) return 0;
    return 1 + CountNode(T->left) + CountNode(T->right);
}

int CountLeaf(const Tree& T)
{
    if(T == NULL) return 0;
    if(!T->left && !T->right) return 1;
    return CountLeaf(T->left) + CountLeaf(T->right);
}

int CountInternalNode(const Tree& T)
{
    if(T == NULL) return 0;
    if(T->left == NULL && T->right == NULL)
        return 0;
    return 1 + CountInternalNode(T->left) + CountInternalNode(T->right);
}

Node* FindMax(const Tree& T)
{
    if(T->right == NULL) return T;
    return FindMax(T->right);
}

Node* FindMin(const Tree& T)
{
    if(T->left == NULL) return T;
    return FindMin(T->left);
}

int Height(const Tree& T)
{
    if(T == NULL) return -1;
    int a = Height(T->left);
    int b = Height(T->right);
    return 1 + (a > b ? a : b);
}

int FindMaxSumFam(const Tree& T)
{
    if(T == NULL) return 0;
    int t = T->key;
    if(T->left) t += T->left->key;
    if(T->right) t += T->right->key;
    int a = t > FindMaxSumFam(T->left) ? t : FindMaxSumFam(T->left);
    int b = t > FindMaxSumFam(T->right) ? t : FindMaxSumFam(T->right);
    return a > b ? a : b;
}

bool IsCompleteTree(const Tree& T)
{
    if(T == NULL) return true;
    queue<Node*> q;
    q.push(T);
    bool foundNull = false;
    while(!q.empty())
    {
        Node* p = q.front();
        q.pop();
        if(p == NULL) foundNull = true;
        else
        {
            if(p && foundNull == true) return false;
            q.push(p->left);
            q.push(p->right);
        }
    }
    return true;
}

bool Search(const Tree& T, int x)
{
    if(T == NULL) return false;
    if(T->key == x) return true;
    if(T->key > x) return Search(T->left, x);
    return Search(T->right, x);
}

void Replace(Node*& q, Node*& T)
{
    if(T->left != NULL) Replace(q, T->left);
    else
    {
        q->key = T->key;
        q = T;
        T = T->right;
    }
}

void Delete(Tree& T, int x)
{
    if(T == NULL) return;
    if(T->key > x) Delete(T->left, x);
    else if(T->key < x) Delete(T->right, x);
    else
    {
        Node* q = T;
        if(T->left == NULL) T = T->right; // chi co 1 con phai
        else if(T->right == NULL) T = T->left; // chi co 1 con trai
        else Replace(q, T->right); // co 2 con, tim node trai cung cua cay con phai
        delete q;
    }   
}

bool IsSameTree(const Tree& T1, const Tree& T2)
{
    if(T1 == NULL && T2 == NULL) return true;
    if(T1 == NULL || T2 == NULL) return false;
    if(T1->key != T2->key) return false;
    return IsSameTree(T1->left, T2->left) && IsSameTree(T1->right, T2->right);
}

bool IsSubTree(const Tree& T, const Tree& t)
{ 
    if(T == NULL) return false;
    if(t == NULL) return true;
    if(IsSameTree(T, t)) return true;
    return IsSubTree(T->left, t) || IsSubTree(T->right, t);
}

Tree CreateTreeee(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE)
{
    int i;
    Tree root;
    if(inE < inB) return NULL;
    root = new Node;
    if(root != NULL)
    {
        root->key = pre[preB];
        for(int i = inB; i< inE; i++)
        {
            if(in[i] == pre[preB]) break;
        }
        root->left = CreateTreeee(pre, in, preB + 1, preE, inB, i -1);
        root->right = CreateTreeee(pre, in, preB + i - inB + 1, preE, i+1, inE);
    }
    return root;
}

int main()
{
    Tree T;
    CreateTree(T);
    BFS_1Line(T);
    BFS_Level(T);
    cout << "Number of node: " << CountNode(T) << endl;
    cout << "Number of leaf: " <<  CountLeaf(T) << endl;
    cout << "Number of internal node: " << CountInternalNode(T) << endl;
    cout << "Max: " << FindMax(T)->key << endl;
    cout << "Min: " << FindMin(T)->key << endl;
    cout << "Height: " << Height(T) << endl;
    cout << "Max sum of 3 nodes: " << FindMaxSumFam(T) << endl;
    if(IsCompleteTree(T))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

// 5 3 6 7 2 4 10 8 11 -1