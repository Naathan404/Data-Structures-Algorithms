

#include <iostream>
#include <string.h>

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



NODE *MakeNODE(int val)
{
    NODE *newNODE = new NODE;
    newNODE->info = val;
    newNODE->pNext = NULL;
    return newNODE;
}

void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

void PushBack(LIST &L, int val)
{
    NODE *newNODE = MakeNODE(val); 
    if(L.pHead == NULL)
    {
        L.pHead = newNODE;
        L.pTail = L.pHead;
    }
    else
    {
        L.pTail->pNext = newNODE;
        L.pTail = newNODE;
    }
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

int SizeOfList(NODE *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->pNext;
    }
    return count;
}

int get_nth_node_from_head(NODE *head, int k)
{
    if(k > SizeOfList(head) || k < 1)
    {
        return -1;
    }
    int i = 1;
    while(i < k)
    {
        i++;
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
    cout << get_nth_node_from_head(L.pHead, k);

    return 0;
}
