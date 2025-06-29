#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
};

typedef Node* Tree;

void CreateEmptyTree(Tree& T)
{
    T = NULL;
}

Node* MakeNode(int x)
{
    Node* newNode = new Node;
    newNode->key = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/// TRAVERSE
// Depth first traversal - Duyet theo chieu sau
void Inorder(Tree T)
{
    if(T == NULL) return;
    Inorder(T->left);
    cout << T->key << " ";
    Inorder(T->right);
}

void Inorder_NonRec(Tree T)
{
    stack<Node*> s;
    Node* curNode = T;
    while(curNode || !s.empty())
    {
        while(curNode)
        {
            s.push(curNode);
            curNode = curNode->left;
        }
        curNode = s.top();
        s.pop();
        cout << curNode->key << " ";

        curNode = curNode->right;
    }
}

void Inorder_UsingStack(Tree T)
{
    stack<Node*> s;
    Node* temp = T;
    while(temp || !s.empty())
    {
        while(temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        Node* n = s.top();
        s.pop();
        cout << n->key << " ";

        temp = temp->right;
    }
}

void Preorder(Tree T)
{
    if(T == NULL) return;
    cout << T->key << " ";
    Preorder(T->left);
    Preorder(T->right);
}
void Postorder(Tree T)
{
    if(T == NULL) return;
    Postorder(T->left);
    Postorder(T->right);
    cout << T->key << " ";
}
// Breadth first traversal - Duyet theo chieu rong
void BFS_OneLine(Tree T)
{
    if(T == NULL) return;
    queue<Node*> q;
    q.push(T);
    while(!q.empty())
    {
        Node* curNode = q.front();
        q.pop();
        cout << curNode->key << " ";
        if(curNode->left != NULL)
            q.push(curNode->left);
        if(curNode->right != NULL)
            q.push(curNode->right);
    }
}
void BFS_LevelOutput(Tree T)
{
    if(T == NULL) return;
    queue<Node*> q;
    q.push(T);
    int size;
    while(!q.empty())
    {
        size = q.size();
        Node* curNode;
        for(int i = 0; i < size; i++)
        {
            curNode = q.front();
            q.pop();
            cout << curNode->key << " ";
            if(curNode->left != NULL)
                q.push(curNode->left);
            if(curNode->right != NULL)
                q.push(curNode->right);
        }
        cout << endl;
    }
}

/// Insert New Node into Tree
int Insert(Tree& T, int x)
{
    if(T != NULL)
    {
        if(T->key == x) return 0;
        if(T->key > x)
            return Insert(T->left, x);
        return Insert(T->right, x);
    }
    T = MakeNode(x);
    return 1;
}

int NonRec_Insert(Tree& T, int x)
{
    if(T == NULL)
    {    
        T = MakeNode(x);
        return 1;
    }
    Node* temp = T;
    while(temp)
    {
        if(temp->key == x) return 0;
        if(temp->key > x)
        {
            if(temp->left == NULL)
                temp->left = MakeNode(x);
            else
                temp = temp->left;
        }
        if(temp->key < x)
        {
            if(temp->right == NULL)
                temp->right = MakeNode(x);
            else
                temp = temp->right;
        }
    }
    return 0;
}
///

void CreateTree(Tree& T)
{
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1) return;
        NonRec_Insert(T, x);
    }
}


/// Search node
bool SearchNode(Tree T, int x)
{
    if(T == NULL) return false;
    if(T->key == x) return true;
    if(T->key > x)
        return SearchNode(T->left, x);
    return SearchNode(T->right, x);
}

/// Get Height of Tree
int HeightOf(Tree T)
{
    if(T == NULL) return -1;
    int a = HeightOf(T->left);
    int b = HeightOf(T->right);
    return 1 + (a > b ? a : b);
}

int NonRec_GetHeightOf(Tree T)
{
    if(T == NULL) return -1;
    queue<Node*> q;
    q.push(T);
    int size = 0, res = -1;
    while(!q.empty())
    {
        size = q.size();
        res++;
        for(int i = 0; i < size; i++)
        {
            Node* currentNode = q.front();
            q.pop();
            if(currentNode->left)
                q.push(currentNode->left);
            if(currentNode->right)
                q.push(currentNode->right);
        }
    }
    return res;
}
///

/// CountNodes
int CountNodes(Tree T)
{
    if(T == NULL) return 0;
    return 1 + CountNodes(T->left) + CountNodes(T->right);
}
int CountNodes2(Tree T)
{
    if(T == NULL) return 0;
    int a = CountNodes2(T->left);
    int b = CountNodes2(T->right);
    return 1 + a + b;
}
int NonRec_CountNodes(Tree T)
{
    if(T == NULL) return 0;
    queue<Node*>  q;
    q.push(T);
    int res = 0;
    while(!q.empty())
    {
        res++;
        Node* curNode = q.front();
        q.pop();
        if(curNode->left != NULL) 
            q.push(curNode->left);
        if(curNode->right != NULL)
            q.push(curNode->right);
    }
    return res;
}

/// Count leaves
int CountLeafNodes(Tree T)
{
    if(T == NULL) return 0;
    if(T->left == NULL && T->right == NULL) return 1;
    return CountLeafNodes(T->left) + CountLeafNodes(T->right);
}
int NonRec_CountLeafNodes(Tree T)
{
    if(T == NULL) return 0;
    queue<Node*> q;
    q.push(T);
    int count = 0;
    while(!q.empty())
    {
        Node* curNode = q.front();
        q.pop();
        if(curNode->left == NULL && curNode->right == NULL)
        {
            count++;
        }
        if(curNode->left != NULL) 
            q.push(curNode->left);
        if(curNode->right != NULL)
            q.push(curNode->right);
    }
    return count;
}
int CountNodeAtLevel(Tree T, int h)
{
    if(T == NULL) return -1;
    if(h < 0 || h > HeightOf(T)) return 0;
    int i = -1, size;
    queue<Node*> q;
    q.push(T);
    while(!q.empty())
    {   
        size = q.size();
        i++;
        if(i == h)
            return q.size();
        for(int i = 0; i < size; i++)
        {
            Node* curNode = q.front();
            q.pop();
            if(curNode->left != NULL)
                q.push(curNode->left);
            if(curNode->right != NULL)
                q.push(curNode->right);
        }

    }
}

int CountInternalNode(Tree T)
{
    if(T == NULL || (T->left == NULL && T->right == NULL))  
        return 0;
    return 1 + CountInternalNode(T->left) + CountInternalNode(T->right);
}

int SumInternalNode(Tree T)
{
    if(T == NULL || (T->left == NULL && T->right == NULL))  
        return 0;
    return T->key + SumInternalNode(T->left) + SumInternalNode(T->right);
}


/// Check Binary Search Tree
bool CheckCompleteBST(Tree T)
{
    if(T == NULL) return true;
    bool foundNull = false;
    queue<Node*> q;
    q.push(T);
    while(!q.empty())
    {
        Node* curNode = q.front();
        q.pop();
        if(curNode == NULL)
            foundNull = true;
        else
        {
            if(foundNull) return false;
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }
    return true;
}

/// Delete key x
void Replace(Tree& p, Tree& T)
{
    if(T->left != NULL)
        Replace(p, T->left);
    else
    {                                                                                       
        p->key = T->key;
        p = T;
        T = T->right;
    }
}
void Delete(Tree& T, int x)
{
    if(T == NULL) return;
    if(T->key > x) Delete(T->left, x);
    else if(T->key < x) Delete(T->right, x);
    else // T->key == x
    {
        Node* temp = T;
        if(T->left == NULL) T = T->right;
        else if(T->right == NULL) T = T->left;
        else Replace(temp, T->right);
        delete temp;
    }
}

/// Check subtree
bool isSameTree(Node* A, Node* B)
{
    if(!A && !B) return true;
    if((!A && B) || (A && !B)) return false;
    if(A->key != B->key) return false;
    return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
}

bool isSubTree(Tree T, Tree S)
{
    if(!S) return true;
    if(!T) return false;
    if(isSameTree(T, S)) return true;
    return isSubTree(T->left, S) || isSubTree(T->right, S);
}

///

int main()
{
    Tree T, S;
    CreateEmptyTree(T);
    CreateEmptyTree(S);

    CreateTree(S);
    CreateTree(T);
    // Inorder(T);
    // cout << endl;
    // Inorder_NonRec(T);
    // cout << endl;
    // Preorder(T);
    // cout << endl;
    // Postorder(T);
    // cout << endl;
    // cout << "height of this BST is: " << HeightOf(T) << endl;
    // cout << "height of this BST is: " << NonRec_GetHeightOf(T) << endl;
    // cout << "number of nodes of this BST is: " << CountNodes(T) << endl;
    // cout << "number of nodes of this BST is: " << CountNodes2(T) << endl;
    // cout << "number of nodes of this BST is: " << NonRec_CountNodes(T) << endl;
    // BFS_OneLine(T);
    // cout << endl;
    // BFS_LevelOutput(T);
    // cout << "Number of leaves: " << CountLeafNodes(T) << endl;
    // cout << "Number of leaves: " << NonRec_CountLeafNodes(T) << endl;
    // int h;
    // cout << "Enter height: ";
    // cin >> h;
    // cout <<"Number of nodes of level " << h << ": " << CountNodeAtLevel(T, h) << endl;
    // cout << "Number of internal nodes: " << CountInternalNode(T) << endl;
    // cout << "Sum of internal nodes: " << SumInternalNode(T) << endl;
    // cout << "Is this tree a complete BST: " << boolalpha << CheckCompleteBST(T) << endl;
    // int x;
    // cout << "Enter key that you want to delete: ";
    // cin >> x;
    // Delete(T, x);
    // BFS_OneLine(T);
    cout << boolalpha << isSubTree(T, S);
    return 0;
}