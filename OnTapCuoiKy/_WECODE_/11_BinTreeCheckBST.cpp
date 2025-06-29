#include <iostream>
#include <vector>

using namespace std;

struct TNode {
    int key;
    TNode * left, * right;
};

typedef TNode * TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
    int i;
    TREE root;
    if (inE < inB) return NULL;
    root = new TNode;
    if (root != NULL) {
        root->key = pre[preB];
        for (i = inB; i <= inE; i++)
            if (in[i] == pre[preB]) break;
        root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
        root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
    } return root;
}


int MaxGroup(TREE);

int main() {
    vector<int> nlr, lnr;
    int n, key;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++) {
        cin >> key;
        lnr.push_back(key);
    }

    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);
    cout << MaxGroup(r);
    return 0;
}

struct Node
{
    TNode* x;
    Node* next;
};

struct Queue
{
    Node* head = NULL;
    Node* tail = NULL;
};

Node* MakeNode(TNode* x)
{
    Node* p = new Node;
    p->x = x;
    p->next = NULL;
    return p;
}

void Push(Queue& Q, TNode* x)
{
    if(Q.head == NULL)
    {
        Q.head = Q.tail = MakeNode(x);
        return;
    }
    Node* p = MakeNode(x);
    Q.tail->next = p;
    Q.tail = p; 
}

// void DeleteTail(Queue& Q)
// {
//     if(Q.head == NULL) return;
//     if(Q.head == Q.tail)    
//     {
//         delete Q.head;
//         Q.head = Q.tail = NULL;
//         return;
//     }
//     Node* p = Q.head;
//     while(p->next->next != NULL)
//         p = p->next;
//     p->next = NULL;
//     delete Q.tail;
//     Q.tail = p;
// }

void Pop(Queue& Q)
{
    if(Q.head == NULL) return;
    if(Q.head == Q.tail)    
    {
        delete Q.head;
        Q.head = Q.tail = NULL;
        return;
    }
    Node* temp = Q.head;
    Q.head = Q.head->next;
    delete temp;
}

bool IsEmpty(const Queue& Q)
{
    return Q.head == NULL;
}

TNode* Front(const Queue& Q)
{
    if(Q.head == NULL) return NULL;
    return Q.head->x;
}

int MaxGroup(TREE T)
{
    if(T == NULL) return 0;
    int max = 0;
    Queue q;
    Push(q, T);
    while(!IsEmpty(q))
    {
        TNode* p = Front(q);
        Pop(q);
        int temp = p->key;
        if(p->left)
        {
            Push(q, p->left);
            temp += p->left->key;
        }
        if(p->right)
        {
            Push(q, p->right);
            temp += p->right->key;
        }
        if(temp > max)
            max = temp;
    }
    return max;
}