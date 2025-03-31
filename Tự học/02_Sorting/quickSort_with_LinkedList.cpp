#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct List
{
    Node *head;
    Node *tail;
};

void CreateEmptyList(List&);
Node* MakeNode(int);
void PushFront(List&, int);
void PushBack(List&, int);
void CreateList(List&, int);
int SizeOfList(List);
void PrintList(List);
Node* GetElement(List, int);
int Partition(List&, int, int);
void QuickSort(List&, int, int);

int main()
{
    List L;
    CreateEmptyList(L);
    CreateList(L, 1);
    PrintList(L);
    QuickSort(L, 0, SizeOfList(L));
    cout << endl;
    PrintList(L);

    return 0;
}

void CreateEmptyList(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

Node* MakeNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void PushFront(List &L, int value)
{
    Node *newNode = MakeNode(value);
    newNode->next = L.head;
    L.head = newNode;
    if(L.head->next == NULL)
    {
        L.tail = L.head;
    }
}

void PushBack(List &L, int value)
{
    Node *newNode = MakeNode(value);
    if(L.head == NULL)
    {
        L.head = newNode;
        L.tail = L.head;
        return;
    }
    L.tail->next = newNode;
    L.tail = newNode;
}

void CreateList(List &L, int pushType)
{
    // pushType = 0 ->- pushFront, = 1 -> pushBack
    while(1)
    {
        int val;
        cin >> val;
        if(val != -1)
            if(pushType == 0)
                PushFront(L, val);
            else
                PushBack(L, val);
        else
            break;
    }
}

int SizeOfList(List L)
{
    int count = 0;
    while(L.head->next != NULL)
    {
        count++;
        L.head = L.head->next;
    }
    return count;
}

void PrintList(List L)
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

Node* GetElement(List L, int findIndex)
{
    int index = 0;
    while(index < findIndex)
    {
        index++;
        L.head = L.head->next;
    }
    return L.head;
}

int Partition(List &L, int left, int right)
{
    int middleIndex = (left + right) / 2;
    int pivot = GetElement(L, middleIndex)->data;
    int i = left, j = right;
    while(i <= j) 
    {
        while(GetElement(L, i)->data < pivot)
            i++;
        while(GetElement(L, j)->data > pivot)
            j--;
        if(i <= j)
        {
            int tempData = GetElement(L, i)->data;
            GetElement(L, i)->data = GetElement(L, j)->data;
            GetElement(L, j)->data = tempData;
            ++i;
            --j;
        }
   }
   return i;
}

void QuickSort(List &L, int left, int right)
{
    if(left >= right)
        return;
    int index = Partition(L, left, right);
    QuickSort(L, left, index - 1);
    QuickSort(L, index, right);
}