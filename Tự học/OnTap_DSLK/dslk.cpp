#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

Node* CreateNode(int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void CreateEmptyList(List& L)
{
    L.head = NULL;
    L.tail = NULL;
}

void AddHead(List& L, int x)
{
    Node *newNode = CreateNode(x);
    newNode->next = L.head;
    L.head = newNode;
    if(L.head->next == NULL)
        L.tail = L.head;
}

void AddTail(List& L, int x)
{
    Node* newNode = CreateNode(x);
    if(L.head == NULL)
    {
        L.head = newNode;
        L.tail = L.head;
        return;
    }
    L.tail->next = newNode;
    L.tail = newNode;
}

void CreateListUsingAddHead(List &L)
{
    while(true)
    {
        int x;
        cin >> x;
        if(x == -1)
            return;
        AddHead(L, x);
    }
}

void CreateListUsingAddTail(List &L)
{
    while(true)
    {
        int x;
        cin >> x;
        if(x == -1)
            return;
        AddTail(L, x);
    }
}

void PrintList(List L)
{
    while(L.head != NULL)
    {
        cout << L.head->data << " ";
        L.head = L.head->next;
    }
}

int main()
{
    List L;
    CreateEmptyList(L);
    CreateListUsingAddHead(L);
    PrintList(L);
    cout << endl;
    CreateListUsingAddTail(L);
    PrintList(L);

    return 0;
}