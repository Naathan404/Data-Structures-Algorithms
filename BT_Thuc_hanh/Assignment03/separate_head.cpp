
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

//// INSERT CODE HERE
void PushFront(LIST& L, int val)
{
    NODE* newNode = CreateNode(val);
    newNode->pNext = L.pHead;
    L.pHead = newNode;
}

void PushBack(LIST& L, int val)
{
    NODE *newNode = CreateNode(val);
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
    int n;
    cin >> n;
    while(n--)
    {
        int val;
        cin >> val;
        PushBack(L, val);
    }
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

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    NODE*p=SeparateHead(L);
    if( p!=NULL) cout << p->info << endl;
    PrintList(L.pHead);

    return 0;
}
