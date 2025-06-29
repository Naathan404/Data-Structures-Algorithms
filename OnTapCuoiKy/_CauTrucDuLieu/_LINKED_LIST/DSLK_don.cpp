#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* next;
};

struct List
{
    Node* head = NULL;
    Node* tail = NULL;
};

Node* MakeNode(int);
void CreateList(List&);
void RemoveList(List&);
void AddHead(List&, int);
void AddTail(List&, int);
void PrintList(const List&);
void RemoveHead(List&);
void RemoveTail(List&);
void ReverseList(List&);
bool Search(const List&, int);

int main()
{
    List L;
    CreateList(L);
    PrintList(L);
    ReverseList(L);
    PrintList(L);
    //RemoveList(L);
    return 0;
}

Node* MakeNode(int value)
{
    Node* newNode = new Node;
    newNode->key = value;
    newNode->next = NULL;
    return newNode;
}

void CreateList(List& L)
{
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1) return;
        //AddHead(L, x);
        AddTail(L, x);
    }
}

void RemoveList(List& L)
{
    while(true)
    {
        cout << endl;
        int c; cin >> c;
        cout << endl;
        if(c == 0) return;
        if(c == 1)
        {
            RemoveHead(L);
            PrintList(L);
        }
        if(c == -1)
        {
            RemoveTail(L);
            PrintList(L);
        }
    }
}

void PrintList(const List& L)
{
    Node* head = L.head;
    while(head != NULL)
    {
        cout << head->key << " --> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

bool Search(const List& L, int x)
{
    if(L.head == NULL) return false;
    Node* head = L.head;
    while(head != NULL)
    {
        if(head->key == x) return true;
        head = head->next;
    }
    return false;
}

void AddHead(List& L, int value)
{
    Node* newNode = MakeNode(value);
    if(L.head == NULL)
    {
        L.head = L.tail = newNode;
        return;
    }
    newNode->next = L.head;
    L.head = newNode;
}

void AddTail(List& L, int value)
{
    Node* newNode = MakeNode(value);
    if(L.head == NULL)
    {
        L.head = L.tail = newNode;
        return;
    }
    L.tail->next = newNode;
    L.tail = newNode;
}

void RemoveHead(List& L)
{
    if(L.head == NULL) return;
    if(L.head == L.tail)
    {
        delete L.head;
        L.head = L.tail = NULL;
        return;
    }
    Node* temp = L.head;
    L.head = L.head->next;
    delete temp;
    temp = NULL;
}

void RemoveTail(List& L)
{
    if(L.head == NULL) return;
    if(L.head == L.tail)
    {
        delete L.head;
        L.head = L.tail = NULL;
        return;
    }
    Node* temp = L.head;
    while(temp->next->next != NULL)
        temp = temp->next;
    temp->next = NULL;
    delete L.tail;
    L.tail = temp;
}

void ReverseList(List& L)
{
    if(L.head == NULL || (L.head == L.tail)) return;
    Node* prev = NULL;
    Node* curr = L.head;
    while(curr != NULL)
    {
        if(prev == NULL)
        {
            L.head = L.tail;
            L.tail = curr;
        }
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}