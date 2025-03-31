#include <iostream>
#include <string.h>

using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};

NODE *MakeNODE(int val)
{
    NODE *newNODE = new NODE;
    newNODE->info = val;
    newNODE->pNext = NULL;
    return newNODE;
}

void CreateEmptyList(NODE *&pHead)
{
    pHead = NULL;
}

void PushBack(NODE *&pHead, int val)
{
    NODE *newNode = MakeNODE(val);
    NODE *tempNode = pHead;
    if(pHead == NULL)
    {
        pHead = newNode;
        return;
    }
    while(tempNode->pNext != NULL)
    {
        tempNode = tempNode->pNext;
    }
    tempNode->pNext = newNode;
}

void CreateList(NODE *&pHead)
{
    while(1)
    {
        int val;
        cin >> val;
        if(val != -1)
            PushBack(pHead, val);
        else
            break;
    }
}

void PrintList(NODE* pHead)
{
    if(pHead == NULL)
    {
        cout << "Empty List.";
        return;
    }
    while(pHead)
    {
        cout << pHead->info << " ";
        pHead = pHead->pNext;
    }
}

void RemoveX(NODE *&pHead, int x)
{
    if(pHead == NULL)
        return;
    if(pHead->info == x)
    {
        NODE* temp = pHead;
        pHead = pHead->pNext;
        delete temp;
    }
    NODE* tempHead = pHead;
    NODE* removeNode = NULL;
    while(tempHead != NULL && tempHead->info != x)
    {
        removeNode = tempHead;
        tempHead = tempHead->pNext;
    }
    if(tempHead == NULL)
        return;
    removeNode->pNext = tempHead->pNext;
    delete tempHead;
}

int main() {
    NODE* pHead;
    int X;
    CreateEmptyList(pHead);

    CreateList(pHead);
    std::cin >> X;
    RemoveX(pHead, X);
    PrintList(pHead);

    return 0;
}
