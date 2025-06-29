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


///
NODE* MakeNode(int x)
{
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST& L, int x)
{
    if(L.pHead == NULL)
    {
        L.pHead = L.pTail = MakeNode(x);
        return;
    }
    NODE* p = MakeNode(x);
    L.pTail->pNext = p;
    L.pTail = p;
}

void CreateEmptyList(LIST& L)
{
    L.pHead = L.pTail = NULL;
}

void CreateList(LIST& L)
{
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1) return;
        AddTail(L, x);
    }
}

int SizeOf(NODE* pHead)
{
    int i = 0;
    while(pHead != NULL)
    {
        i++;
        pHead = pHead->pNext;
    }
    return i;
}

int searchXget_nth_node_from_tail(NODE* head, int k)
{
    if(head == NULL) return -1;
    int i = SizeOf(head); 
    bool isFound = false;
    while(head != NULL)
    {
        if(i == k)
        {
            return head->info;
        }
        i--;
        head = head->pNext;
    }
    return -1;
}

int main() {
    LIST L;
    int k;
    CreateEmptyList(L);
    CreateList(L);

    std::cin >> k;
    cout << searchXget_nth_node_from_tail(L.pHead, k);

    return 0;
}
