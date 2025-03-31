
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


///INSERT CODE HERE
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

void PushFront(LIST& L, int val)
{
    NODE* newNode = CreateNode(val);
    newNode->pNext = L.pHead;
    L.pHead = newNode;
}

void PushBack(LIST& L, NODE* newNode)
{
    if(L.pHead == NULL)
    {
        L.pHead = newNode;
        L.pTail = L.pHead;
        return;
    }
    L.pTail->pNext = newNode;
    L.pTail = newNode;
}

void CreateList(LIST &L)
{
    while(1)
    {
        int val;
        cin >> val;
        NODE* newNode = CreateNode(val);
        if(val != -1)
            PushBack(L, newNode);
        else
            break;
    }
}


void PrintList(LIST L)
{
    if(L.pHead == NULL)
    {
        cout << "Empty List.";
        cout << endl;
        return;
    }
    while(L.pHead != NULL)
    {
        cout << L.pHead->info << " ";
        L.pHead = L.pHead->pNext;
    }
    cout << endl;
}

NODE* SeparateHead(LIST &L)
{
    NODE* tempNode = L.pHead;
    if(tempNode == NULL)
        return NULL;
    L.pHead = L.pHead->pNext;
    tempNode->pNext = NULL;
    if(L.pHead == NULL)
        L.pTail == NULL;
    return tempNode;
}

void Join(LIST& L, LIST L1, NODE* pivot, LIST& L2)
{
    NODE *tempNode = NULL;
    while(L1.pHead != NULL)
    {
        tempNode = SeparateHead(L1);
        PushBack(L, tempNode);
    }
    PushBack(L, pivot);
    while(L2.pHead != NULL)
    {
        tempNode = SeparateHead(L2);
        PushBack(L, tempNode);
    }
}

///

int main() {
    LIST L, L1, L2;

    int x;
    NODE *pivot;

    CreateEmptyList(L);
    CreateEmptyList(L1);
    CreateEmptyList(L2);

    CreateList(L1);
    cin >> x;
    pivot=CreateNode(x);
    CreateList(L2);


    Join(L, L1, pivot, L2);
    PrintList(L);

    return 0;
}
