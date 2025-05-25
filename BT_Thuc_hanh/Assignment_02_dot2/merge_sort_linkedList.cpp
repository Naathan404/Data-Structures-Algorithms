
#include <iostream>
#include <cstdlib>
#include <ctime>
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

NODE* CreateNode(int x) {
    NODE* p;
    p = new NODE;
    //if (p == NULL)
    //		exit(1);

    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else {
        L.pTail->pNext = p;
        L.pTail=p;
    }
}

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}
void CreateList(LIST &L) {
    NODE* p;
    int x, n;
    cin >> n; // Số lượng phần tử của danh sách
    while (n-->0) {
        cin >> x;
        p = CreateNode(x);
        AddTail(L, p);
    }
}

//////////////

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

void MergePartition(LIST &L, LIST &L1, LIST &L2)
{
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    NODE *temp = new NODE;
    while(L.pHead)
    {
        temp = SeparateHead(L);
        AddTail(L1, temp);
        if(L.pHead)
        {
            temp = SeparateHead(L);
            AddTail(L2, temp);
        }
    }
}

void Merge(LIST &L, LIST &L1, LIST &L2)
{
    NODE *temp = new NODE; 
    while(L1.pHead != NULL || L2.pTail != NULL)
    {
        if(L2.pHead == NULL || (L1.pHead != NULL && (L1.pHead->info < L2.pHead->info)))
        {
            temp = SeparateHead(L1);
            AddTail(L, temp);
        }
        else
        {
            temp = SeparateHead(L2);
            AddTail(L, temp);
        }
    }
}

void mergesort_ascending(LIST &L)
{
    if(L.pHead == L.pTail)
        return;
    LIST L1, L2;
    MergePartition(L, L1, L2);
    mergesort_ascending(L1);
    mergesort_ascending(L2);
    Merge(L, L1, L2);
}
//////////////

int length(NODE *p){
    int i=0;
    while (p) {
        i++;
        p = p->pNext;
    }
    return i;
}

void PrintList(NODE* p) {
    if (p == NULL)
        cout << "Empty List.";
    else {
        cout << length(p) << endl;
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
    mergesort_ascending(L);
    PrintList(L.pHead);

    return 0;
}

