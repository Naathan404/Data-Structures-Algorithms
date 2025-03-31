#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LIST
{
    Node *head;
};

Node *MakeNode(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void CreateEmptyList(LIST &L)
{
    L.head = NULL;
}

void PushFront(Node *&head, int val)
{
    Node *newNode = MakeNode(val);
    newNode->next = head;
    head = newNode;
}

void CreateList(LIST &L)
{
    while(1)
    {
        int val;
        cin >> val;
        if(val != -1)
            PushFront(L.head, val);
        else
            break;
    }
}

void PrintList(LIST L)
{
    if(L.head == NULL)
    {
        cout << "Empty List.";
        return;
    }
    while(L.head != NULL)
    {    
        cout << L.head->data << " ";
        L.head = L.head->next;
    }
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList(L);

    return 0;
}
