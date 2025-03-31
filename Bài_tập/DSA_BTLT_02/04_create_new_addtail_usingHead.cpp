#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};

NODE *MakeNode(int val)
{
    NODE *newNode = new NODE;
    newNode->info = val;
    newNode->pNext = NULL;
    return newNode;
}

void CreateEmptyList(NODE *&head)
{
    head = NULL;
}

void PushFront(NODE *&head, int val)
{
    NODE *newNode = MakeNode(val);
    newNode->pNext = head;
    head = newNode;
}

void PushBack(NODE *&head, int val)
{
    NODE *newNode = MakeNode(val);
    NODE *tmp = head;
    if(tmp == NULL)
    {
        head = newNode;
        return;
    }
    while(tmp->pNext != NULL)
    {
        tmp = tmp->pNext;
    }
    tmp->pNext = newNode;
}

void CreateList(NODE *&head)
{
    while(1)
    {
        int val;
        cin >> val;
        if(val != -1)
            PushBack(head, val);
        else
            break;
    }
}

void PrintList(NODE *head)
{
    if(head == NULL)
    {
        cout << "Empty List.";
        return;
    }
    while(head != NULL)
    {    
        cout << head->info << " ";
        head = head->pNext;
    }
}

int main() {
    NODE* pHead;
    CreateEmptyList(pHead);

    CreateList(pHead);
    PrintList(pHead);

    return 0;
}
