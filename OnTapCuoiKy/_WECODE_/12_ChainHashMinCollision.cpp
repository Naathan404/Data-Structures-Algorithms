#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key;
    Node* next;
};

typedef vector<Node*> HashTable;

Node* makeNode(int x)
{
    Node* p = new Node;
    p->key = x;
    p->next = NULL;
    return p;
}

void AddTail(Node*& H_head, int x)
{
    Node* head = H_head;
    if(H_head == NULL)
    {
        H_head = makeNode(x);
        return;
    }
    while(head->next != NULL)
        head = head->next;
    Node* p = makeNode(x);
    head->next = p;
}

int HF(int key, int M)
{
    return key % M;
}

int SizeOf(Node* head)
{
    int i = 0;
    while(head != NULL)
    {
        i++;
        head = head->next;
    }
    return i;
}

void CreateHashTable(HashTable& H, int& n, int& M)
{
    cin >> n >> M;

    H.resize(M);
    for(int i = 0; i < M; i++)
        H[i] = NULL;
    
    int val;
    while(n--)
    {
        cin >> val;
        int bucket = HF(val, M);
        AddTail(H[bucket], val);
    }
}

void FindAddressesHaveMinCollision(const HashTable& H, int M)
{
    vector<int> kq;
    int min = INT32_MAX;
    for(int i = 0; i < M; i++)
    {
        if(SizeOf(H[i]) > 1 && SizeOf(H[i]) < min)
        {
            min = SizeOf(H[i]);
            kq.clear();
            kq.push_back(i);
        }
        else if(SizeOf(H[i]) > 1 && SizeOf(H[i]) == min)
            kq.push_back(i);
    }

    for(int x : kq)
        cout << x << " ";
}

int main()
{
    HashTable H;
    int n, M;
    CreateHashTable(H, n, M);
    FindAddressesHaveMinCollision(H, M);

    return 0;
}