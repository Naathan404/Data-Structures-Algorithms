
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
        // cout << boolalpha << is_ascending(p) << endl;
        cout << length(p) << endl;
        while (p) {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
}

/// INSERT CODE HERE
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

void Partition(LIST& L, LIST& L1, NODE*& pivot, LIST& L2)
{
    if(L.pHead == NULL)
        return;

    NODE* tempNode = NULL;
    pivot = SeparateHead(L);
    while(L.pHead != NULL)
    {
        tempNode = SeparateHead(L);
        if(tempNode->info <= pivot->info)
            AddTail(L1, tempNode);
        else    
            AddTail(L2, tempNode);
    }
}

void Join(LIST& L, LIST& L1, NODE* pivot, LIST& L2)
{
    NODE* tempNode = NULL;
    while(L1.pHead != NULL)
    {
        tempNode = SeparateHead(L1);
        AddTail(L, tempNode);
    }
    AddTail(L, pivot);
    while(L2.pHead != NULL)
    {
        tempNode = SeparateHead(L2);
        AddTail(L, tempNode);
    }
}

void quicksort_ascending(LIST& L)
{
    if((L.pHead == L.pTail))
        return;
    LIST L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    NODE *pivot = NULL;
    Partition(L, L1, pivot, L2);
    quicksort_ascending(L1);
    quicksort_ascending(L2);
    Join(L, L1, pivot, L2);
}

///

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    quicksort_ascending(L);
    PrintList(L.pHead);

    return 0;
}
