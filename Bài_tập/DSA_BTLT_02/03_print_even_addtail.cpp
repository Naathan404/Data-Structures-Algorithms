

#include <iostream>
#include <cmath>
using namespace std;

// Cấu trúc của một node
struct NODE {
    int info;
    NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
    NODE* pHead;
    NODE* pTail;
};

NODE *MakeNode(int val)
{
    NODE *newNode = new NODE;
    newNode->info = val;
    newNode->pNext = NULL;
    return newNode;
}

void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
}

void PushFront(NODE *&head, int val)
{
    NODE *newNode = MakeNode(val);
    newNode->pNext = head;
    head = newNode;
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
        NODE *newNode = MakeNode(val);
        L.pTail->pNext = newNode;
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

void PrintEvenNumbers(NODE *Head)
{
    if(Head == NULL)
    {
        cout << "Danh sach rong.";
        return;
    }
    bool checkIfEven = false;
    while(Head != NULL)
    {    
        if(Head->info % 2 == 0)
        {
            cout << Head->info << " ";
            checkIfEven = true;
        }
        Head = Head->pNext ;
    }
    if(!checkIfEven)
        cout << "Danh sach khong co so chan.";
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintEvenNumbers(L.pHead);

    return 0;
}
