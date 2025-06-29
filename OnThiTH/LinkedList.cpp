#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* next;
};

struct List
{
    Node* head;
    Node* tail;
};

void CreateEmptyist(List& L)
{
    L.head = L.tail = NULL;
}

Node* makeNode(int x)
{
    Node* p = new Node;
    p->key = x;
    p->next = NULL;
    return p;
}

void AddHead(List& L, int x)
{
    Node* p = makeNode(x);
    if(L.head == NULL)
    {
        L.head  = L.tail = p;
        return;
    }
    p->next = L.head;
    L.head = p;
}

void AddTail(List& L, int x)
{
    Node* p = makeNode(x);
    if(L.head == NULL)
    {
        L.head = L.tail = p;
        return;
    }
    L.tail->next = p;
    L.tail = p;
}

void CreateList(List& L)
{
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1)
            return;
        AddTail(L, x);
    }
}

void  PrintList(const List& L)
{
    Node* temp = L.head;
    while(temp != NULL)
    {
        cout << temp->key << " --> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void ReverseList(List& L)
{
    if(L.head == NULL || L.head == L.tail)
        return;
    Node* curr = L.head;
    Node* prev = NULL;
    while(curr != NULL)
    {
        if(prev == NULL)
        {
            Node* temp = L.head;
            L.head = L.tail;
            L.tail = temp;
        }
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}

void RemoveHead(List& L)
{
    if(L.head == NULL)
    {
        return;
    }
    if(L.head == L.tail)
    {
        delete L.head;
        L.head = L.tail = NULL;
    }
    Node* temp = L.head;
    L.head = L.head->next;
    delete temp;
}

void RemoveNode(List& L, int i)
{
    if(L.head == NULL)
        return;
    if(i == 0)
    {
        Node* temp = L.head;
        L.head = L.head->next;
        delete temp;
        return;
    }
    Node* curr = L.head;
    Node* prev = NULL;
    int k = 0;
    while(curr != NULL)
    {
        if(k == i)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
        k++;
    }
}

Node* SeparateHead(List& L)
{
    Node* p = L.head;
    if(p == NULL)
        return NULL;
    L.head = L.head->next;
    p->next = NULL;
    if(L.head == NULL)
        L.tail = L.head;
    return p;
}

void MergeSplit(List& L , List& L1, List& L2)
{
    CreateEmptyist(L1);
    CreateEmptyist(L2);
    while(L.head != NULL)
    {
        Node* p = SeparateHead(L);
        AddTail(L1, p->key);
        if(L.head != NULL)
        {
            p = SeparateHead(L);
            AddTail(L2, p->key);
        }
    }
}   

void Merge(List& L, List& L1, List& L2)
{
    while(L1.head != NULL || L2.tail != NULL)
    {
        Node* p;
        if(L2.head == NULL || (L1.head != NULL && (L1.head->key < L2.head->key)))
        {
            p = SeparateHead(L1);
        }
        else
        {
            p = SeparateHead(L2);
        }
        AddTail(L, p->key);
    }
}

void MergeSort(List& L)
{
    if(L.head == L.tail)
        return;
    List L1, L2;
    MergeSplit(L, L1, L2);
    MergeSort(L1);
    MergeSort(L2);
    Merge(L, L1, L2);
}

// QUICKSORT
void Partition(List& L, List& L1, List& L2, Node* pivot)
{
    while(L.head)
    {
        Node* p = SeparateHead(L);
        if(p->key < pivot->key)
            AddTail(L1, p->key);
        else
            AddTail(L2, p->key);
    }
}

void Join(List& L, List& L1, List& L2, Node* pivot)
{
    while(L1.head)
    {
        AddTail(L, SeparateHead(L1)->key);
    }
    AddTail(L, pivot->key);
    while(L2.head)
    {
        AddTail(L, SeparateHead(L2)->key);
    }
}

void QuickSort(List& L)
{
    if(L.head == L.tail) return;
    List L1, L2;
    CreateEmptyist(L1);
    CreateEmptyist(L2);
    Node* pivot = SeparateHead(L);
    Partition(L, L1, L2, pivot);
    QuickSort(L1);
    QuickSort(L2);
    Join(L, L1, L2, pivot);
}

int Size(const List& L)
{
    Node* p = L.head;
    int count = 0;
    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}


int main()
{
    List L;
    CreateEmptyist(L);
    CreateList(L);
    PrintList(L);
    // cout << "--> Merge Sort: \n";
    // MergeSort(L);
    // PrintList(L);
    cout << "--> Quick Sort: \n";
    QuickSort(L);
    PrintList(L);

    return 0;
}