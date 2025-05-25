#include <iostream>
#include <ctime>    
using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct List
{
    Node* head;
    Node* tail;
};

Node* MakeNode(int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void CreateEmptyList(List& L)
{
    L.head = L.tail = NULL;
}

void AddHead(List& L, int x)
{
    Node* newNode = MakeNode(x);
    if(L.head == NULL)
    {
        L.head = L.tail = newNode;
        return;
    }
    newNode->next = L.head;
    L.head = newNode;
}

void AddTail(List& L, int x)
{
    Node* newNode = MakeNode(x);
    if(L.head == NULL)
    {
        L.head = L.tail = newNode;
        return;
    }
    L.tail->next = newNode;
    L.tail = newNode;
}

void Remove(List& L, int x)
{
    if(L.head == NULL) return;
    Node* head = L.head;
    if(L.head->data == x)
    {
        L.head = L.head->next;
        delete(head);
        return;
    }
    
    while(head->next != NULL)
    {
        if(head->next->data == x)
        {
            Node* temp = head->next;
            head->next = head->next->next;
            delete(temp);
            return;
        }
        head = head->next;
    }
}

int Search(List L, int x)
{
    int i = 0;
    while(L.head != NULL)
    {
        if(L.head->data == x)
            return i;
        i++;
        L.head = L.head->next;
    }
    return -1;
}

void Reverse(List& L)
{
    if(L.head == NULL || L.head->next == NULL) return;

    Node* preNode = NULL;
    Node* curNode = L.head;
    Node* nextNode = NULL;

    Node* temp = L.head;
    L.head = L.tail;
    L.tail = temp;

    while(curNode != NULL)
    {
        nextNode = curNode->next;
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }
}

void CreateRandomList(List& L, int n)
{
    if(n <= 0) return;
    srand(time(NULL));
    while(n--)
    {
        int x = rand() % 100 - 50;
        AddTail(L, x);
    }
}

void CreateList(List& L)
{
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1) return;
        AddTail(L, x);
    }
}

void PrintList(List L)
{
    if(L.head == NULL)
    {
        cout << "Empty List." << endl;
        return;
    }
    while(L.head != NULL)
    {
        cout << L.head->data << " ";
        L.head = L.head->next;
    }
    cout << endl;
}

Node* SeparateHead(List& L)
{
    Node* temp = L.head;
    if(temp == NULL) 
        return NULL;
    L.head = L.head->next;
    temp->next = NULL;
    if(L.head == NULL)
        L.tail = L.head;
    return temp;
}

/// QUICKSORT
void Partition(List& L, List& L1, Node*& pivot, List& L2)
{
    while(L.head != NULL)
    {
        Node* temp = SeparateHead(L);
        if(temp->data <= pivot->data)
            AddTail(L1, temp->data);
        else
            AddTail(L2, temp->data);
    }
}

void Join(List& L, List& L1, Node* pivot, List& L2)
{
    while(L1.head != NULL)
    {
        Node* temp = SeparateHead(L1);
        AddTail(L, temp->data);
    }
    AddTail(L, pivot->data);
    while(L2.head != NULL)
    {
        Node* temp = SeparateHead(L2);
        AddTail(L, temp->data);
    }
}

void QuickSort(List& L)
{
    if(L.head == L.tail) return;
    List L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    Node* pivot = SeparateHead(L);
    Partition(L, L1, pivot, L2);
    QuickSort(L1);
    QuickSort(L2);
    Join(L, L1, pivot, L2);
}

/// MERGE SORT
void MergeList(List& L, List& L1, List& L2)
{
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    Node* temp;

    while(L.head != NULL)
    {
        temp = SeparateHead(L);
        AddTail(L1, temp->data);
        if(L.head != NULL)
        {
            temp = SeparateHead(L);
            AddTail(L2, temp->data);
        }
    }
}

void Merge(List& L, List& L1, List& L2)
{
    Node* temp;
    while(L1.head != NULL || L2.tail != NULL)
    {
        if(L2.head == NULL || (L1.head != NULL && (L1.head->data < L2.head->data)))
        {
            temp = SeparateHead(L1);
            AddTail(L, temp->data);
        }
        else
        {
            temp = SeparateHead(L2);
            AddTail(L, temp->data);
        }
    }
}

void MergeSort(List& L)
{
    if(L.head == L.tail) return;
    List L1, L2;
    MergeList(L, L1, L2);
    MergeSort(L1);
    MergeSort(L2);
    Merge(L, L1, L2);
}

int main()
{
    List L1;
    CreateEmptyList(L1);
    CreateList(L1);
    PrintList(L1);

    QuickSort(L1);
    PrintList(L1);

    return 0;
}