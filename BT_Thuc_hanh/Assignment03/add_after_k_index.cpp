#include <iostream>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

struct LIST
{
    NODE *head;
    NODE *tail;
};

NODE *MakeNode(int val)
{
    NODE *newNode = new NODE;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void CreateEmptyList(LIST &L)
{
    L.head = NULL;
    L.tail = NULL;
}

void PushFront(LIST& L, int val)
{
    NODE* newNode = MakeNode(val);
    newNode->next = L.head;
    L.head = newNode;
}

void PushBack(LIST& L, int val)
{
    NODE *newNode = MakeNode(val);
    if(L.head == NULL)
    {
        L.head = newNode;
        L.tail = L.head;
        return;
    }
    L.tail->next = newNode;
    L.tail = newNode;
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

int LengthOfList(LIST L)
{
    int count = 0;
    while(L.head != NULL)
    {
        count++;
        L.head = L.head->next;
    }
    return count;
}

void add_after_k_th(LIST& L, int Y, int k)
{
    if(k > LengthOfList(L) || k < 1)
        return;
    NODE *newNode = MakeNode(Y);
    NODE *tempHead = L.head;
    if(L.head == NULL)
    {
        return;
    }
    if(k == 1)
    {
        newNode->next = L.head->next;
        L.head->next = newNode;
        return;
    }
    if(k == LengthOfList(L))
    {
        PushBack(L, Y);
        return;
    }
    int curPos = 1;
    while(curPos < k)
    {
        curPos++;
        tempHead = tempHead->next;
    }
    newNode->next = tempHead->next;
    tempHead->next = newNode;
}

void PrintList(LIST L)
{
    if(L.head == NULL)
    {
        cout << "Empty List.";
        return;
    }
    while(L.head != NULL)
    {
        cout << L.head->data << " ";
        L.head = L.head->next;
    }
}

int main() {
    LIST L;
    int k, Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> k >> Y;
    add_after_k_th(L, Y, k);

    PrintList(L);

    return 0;
}
