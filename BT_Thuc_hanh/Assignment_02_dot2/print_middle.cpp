#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LIST
{
    Node *pHead;
    Node *pTail;
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
    L.pHead = NULL;
    L.pTail = NULL;
}

int SizeOfList(LIST L)
{
    int count = 0;
    while(L.pHead->next != NULL)
    {
        count++;
        L.pHead = L.pHead->next;
    }
    return count;
}

void PushFront(Node *&pHead, int val)
{
    Node *newNode = MakeNode(val);
    newNode->next = pHead;
    pHead = newNode;
}

void PushBack(LIST &L, int val)
{
    if(L.pHead == NULL)
    {
        PushFront(L.pHead, val);
        L.pTail = L.pHead;
    }
    else
    {
        Node *newNode = MakeNode(val);
        L.pTail->next = newNode;
        L.pTail = newNode;
    }
}

void CreateList(LIST &L)
{
    while(1)
    {
        int val;
        cin >> val;
        if(val != -1)
            PushBack(L, val);
        else
            break;
    }
}

void Print_Middle(LIST L)
{
    if(L.pHead == NULL)
    {
        cout << "Empty List.";
        return;
    }

    int middleIndex = SizeOfList(L) / 2;    

    int index = 0;
    while(index < middleIndex)
    {
        L.pHead = L.pHead->next;
        index++;
    }

    cout << L.pHead->data;
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    Print_Middle(L);

    return 0;
}
