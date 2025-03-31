
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
    L.pTail = NULL;
}

void PushFront(LIST& L, int val)
{
    NODE* newNode = MakeNode(val);
    newNode->pNext = L.pHead;
    L.pHead = newNode;
}

void PushBack(LIST& L, int val)
{
    NODE *newNode = MakeNode(val);
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
        if(val != -1)
            PushBack(L, val);
        else
            break;
    }
}

int LengthOfList(NODE *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->pNext;
    }
    return count;
}

int searchXget_nth_node_from_tail(NODE* head, int k)
{
    if(k > LengthOfList(head) || k <= 0)
        return - 1;
    int searchPosition = LengthOfList(head) - k;
    int curPos = 0;
    while (curPos < searchPosition)
    {
        curPos++;
        head = head->pNext;
    }
    return head->info;
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
