
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

////////////////////////////////////
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
    NODE *tempNode = L.pHead;
    if(tempNode == NULL)
        return NULL;
    L.pHead = L.pHead->pNext;
    tempNode->pNext = NULL;
    if(L.pHead == NULL)
        L.pTail = NULL;
    return tempNode;
}

// void Merge_Partition(LIST &L, LIST &L1, LIST &L2)
// {
//     NODE* tempNode = new NODE;
//     while(L.pHead != NULL)
//     {
//         tempNode = SeparateHead(L);
//         PushBack(L1, tempNode);
//         if(L.pHead == NULL)
//             return;
//         tempNode = SeparateHead(L);
//         PushBack(L2, tempNode);
//     }
// }

void Merge(LIST &L, LIST &L1, LIST &L2)
{
    NODE* p = new NODE;
    CreateEmptyList(L);
    while(L1.pHead != NULL || L2.pTail != NULL)
    {
        if(L2.pHead == NULL || (L1.pHead != NULL && L1.pHead->info < L2.pHead->info))
        {
            p = SeparateHead(L1);
            PushBack(L, p);
        }
        else
        {
            p = SeparateHead(L2);
            PushBack(L, p);
        }
    }
}

void Merge_2_Sorted_LL(LIST &L, LIST &L1, LIST &L2)
{
    if(L.pHead == L.pTail)
        return;
    Merge(L, L1, L2);
}

////////////////////////////////////

void PrintList(LIST L) {
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
    cout << endl;
}int main() {
    LIST L, L1, L2;

    CreateEmptyList(L1);
    CreateEmptyList(L2);

    CreateList(L1);
    CreateList(L2);


    Merge_2_Sorted_LL(L, L1, L2);

    PrintList(L);
    PrintList(L1);
    PrintList(L2);

    return 0;
}
