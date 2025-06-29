#include <iostream>
using namespace std;

#define M 100

struct Node
{
    int key;
    Node* next;
};

typedef Node* HashTable[M];

Node* MakeNode(int x)
{
    Node* p = new Node;
    p->key = x;
    p->next = NULL;
    return p;
}

void AddTail(Node*& head, int x)
{
    Node* temp = head;
    Node* p = MakeNode(x);
    if(head == NULL)
    {
        head = p;
        return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
    temp = p;
}

int HF(int key, int m)
{
    return key % m;
}

void CreateHT(HashTable& H, int& m)
{
    int x;
    cin >> m;
    for(int i = 0; i < m; i++)
        H[i] = NULL;
    while(true)
    {
        cin >> x;
        if(x == -1) return;
        int bucket = HF(x, m);
        AddTail(H[bucket], x);
    }
}

void PrintHT(const HashTable& H, int m)
{
    for(int i = 0; i < m; i++)
    {
        cout << i << " ||";
        Node* head = H[i];
        while(head != NULL)
        {
            cout << " --> " << head->key;
            head = head->next;
        }
        cout << endl;
    }
}

void DeleteKey(HashTable& H,int m, int x)
{
    int pos = HF(x, m);
    Node* prev = NULL;
    Node* curr = H[pos];
    while(curr != NULL)
    {
        if(curr->key == x)
        {
            if(prev == NULL)
            {
                H[pos] = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            delete curr;
            curr = NULL;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main()
{
    HashTable H;
    int m;
    CreateHT(H, m);
    PrintHT(H, m);
}