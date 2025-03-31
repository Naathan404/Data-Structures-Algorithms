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

void PushFront(Node *&pHead, int val)
{
    Node *newNode = MakeNode(val);
    newNode->next = pHead;
    pHead = newNode;
}

void PushBack(LIST &L, int val)
{
    Node *newNode = MakeNode(val);
    if(L.pHead == NULL)
    {
        L.pHead = newNode;
    }
    else
    {
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

void PrintList_Odd(Node *head)
{
    if(head == NULL)
    {
        cout << "Empty List.";
        return;
    }
    bool hasOdd = false;
    while(head != NULL)
    {
        if(head->data % 2 != 0)
        {
            cout << head->data << " ";
            hasOdd = true;
        }
        head = head->next;
    }
    if(!hasOdd)
    {
        cout << "Không có số lẻ trong mảng.";
    }
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList_Odd(L.pHead);

    return 0;
}
