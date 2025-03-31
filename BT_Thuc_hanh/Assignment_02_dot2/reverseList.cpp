#include <iostream>
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

///////////////////////////////////////
NODE* CreateNode(int x) {
    NODE* p;
    p = new NODE;
    //if (p == NULL)
    //		exit(1);

    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

void PushBack(LIST &L, NODE* addedNODE)
{
    if(L.pHead == NULL)
    {
        L.pHead = addedNODE;
        L.pTail = L.pHead;
        return;
    }
    L.pTail->pNext = addedNODE;
    L.pTail = addedNODE;
}

void CreateList(LIST &L)
{
    int x;
    while(1)
    {
        cin >> x;
        if(x == -1)
            return;
        PushBack(L, CreateNode(x));
    }
}

NODE* SeparateHead(LIST &L)
{
    if(L.pHead == NULL)
        return NULL;
    NODE *tempNode = L.pHead;
    L.pHead = L.pHead->pNext;
    tempNode->pNext = NULL;
    if(L.pHead == NULL)
        L.pTail = NULL;
    return tempNode;
}

void Reverse_LinkedList(LIST &L)
{
    if(L.pHead == NULL || L.pHead == L.pTail)
        return;
    
    NODE* prevNode = NULL;
    NODE* currentNode = L.pHead;
    NODE* nextNode = NULL;

    NODE *temp = L.pTail;
    L.pTail = L.pHead;
    L.pHead = temp;

    while(currentNode)
    {
        nextNode = currentNode->pNext;
        currentNode->pNext = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
}

///////////////////////////////////////

void PrintList(const LIST &L)  {
    NODE* p;

    if (L.pHead == NULL)
        cout << "Empty List.";
    else {
        p = L.pHead;
        while (p) {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
}

int main() {
    LIST L;

    CreateEmptyList(L);
    CreateList(L);

    Reverse_LinkedList(L);

    PrintList(L);

    return 0;
}


