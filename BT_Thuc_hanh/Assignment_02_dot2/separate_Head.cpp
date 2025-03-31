
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

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

void PushBack(LIST &L, int x)
{
    NODE *newNode = CreateNode(x);
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
    int size, x;
    cin >> size;
    if(size == 0)
        return;
    while(size)
    {
        cin >> x;
        PushBack(L, x);
        size--;
    }
}

void PrintList(NODE* head)
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

NODE* SeparateHead(LIST &L)
{
    if(L.pHead == NULL)
        return NULL;
    NODE *tempNode = L.pHead;
    L.pHead = L.pHead->pNext;
    tempNode->pNext == NULL;
    if(L.pHead == NULL)
        L.pTail = NULL;
    return tempNode;
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    NODE*p=SeparateHead(L);
    if( p!=NULL) cout << p->info << endl;
    PrintList(L.pHead);

    return 0;
}
