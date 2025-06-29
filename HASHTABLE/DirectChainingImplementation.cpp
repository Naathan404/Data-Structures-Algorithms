#include <iostream>
using namespace std;

#define HASHTABLE_SIZE 100

struct Node
{
    int key;
    Node* next;
};

typedef Node* HASHTABLE[HASHTABLE_SIZE];

Node* MakeNode(int);
void AddTail(Node*&, int);
int HashFunction(int, int);
void CreateEmptyHashTable(HASHTABLE&, int);
void CreateHashTable(HASHTABLE&, int&);
void PrintTable(const HASHTABLE&, int);
void RemoveKey(HASHTABLE&, int, int);

int main()
{
    HASHTABLE H;
    int numbucket;
    cout << "Nhap so luong bucket: ";
    CreateHashTable(H, numbucket);
    PrintTable(H, numbucket);
    int tc; cout << endl; cin >> tc;
    while(tc--)
    {
        int x;
        cin >> x;
        RemoveKey(H, numbucket, x);
        PrintTable(H, numbucket);
        cout << endl;
    }

    return 0;
}

Node* MakeNode(int x)
{
    Node* newNode = new Node;
    newNode->key = x;
    newNode->next = NULL;
    return newNode;
}

void AddTail(Node*& head, int x)
{
    if(head == NULL)
    {
        head = MakeNode(x);
        return;
    }
    Node* temp = head;
    Node* newNode = MakeNode(x);
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int HashFunction(int key, int numbucket)
{
    return key % numbucket;
}

void CreateEmptyHashTable(HASHTABLE& H, int numbucket)
{
    for(int i = 0; i < numbucket; i++)
    {
        H[i] = NULL;
    }
}

void CreateHashTable(HASHTABLE& H, int& numbucket)
{
    // Init new Hash Table
    cin >> numbucket;
    CreateEmptyHashTable(H, numbucket);
    
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1) return;
        int bucket = HashFunction(x, numbucket);
        AddTail(H[bucket], x);
    }
}

void PrintTable(const HASHTABLE& H, int numbucket)
{
    for(int i =- 0; i < numbucket; i++)
    {
        cout << i;
        Node* head = H[i];
        while(head != NULL)
        {
            cout << " --> " << head->key;
            head = head->next;
        }
        cout << endl;
    }
}

void RemoveKey(HASHTABLE& H, int numbucket, int key)
{
    int bucket = HashFunction(key, numbucket);
    Node* previousNode = NULL;
    Node* currentNode = H[bucket];
    while(currentNode != NULL)
    {
        if(currentNode->key == key)
        {
            Node* tempNode = currentNode;
            if(previousNode == NULL)
            {
                H[bucket] = currentNode->next;
            }
            else
            {
                previousNode->next = currentNode->next;
            }
            delete tempNode;
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
}