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

void CreateEmptyList(LIST& L)
{
    L.pHead = L.pTail = NULL;
}

NODE* MakeNode(int x)
{
    NODE* p = new NODE;
    p->info = x;
    p->pNext  = NULL;
    return p;
}
void AddTail(LIST& L, int x)
{
    NODE* p = MakeNode(x);
    if(L.pHead == NULL)
    {
        L.pHead = L.pTail = p;
        return;
    }
    L.pTail->pNext = p;
    L.pTail =p;
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

int Size(NODE* head)
{
    int n = 0;
    NODE* temp = head;
    while(temp)
    {
        n++;
        temp = temp->pNext;
    }
    return n;
}

int searchXget_nth_node_from_tail(NODE* head, int k)
{
    if(head == NULL)  return -1;
    int i = Size(head);
    while(head)
    {
        if(i == k)
            return head->info;
        head = head->pNext;
        i--;
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
