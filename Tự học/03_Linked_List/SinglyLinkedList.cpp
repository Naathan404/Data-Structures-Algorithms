#include <iostream>
#include <ctime>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Create new node
Node* makeNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Cac thao tac co ban || Xuat - Kich thuoc - Sap xep
void write(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int size(Node *head)
{
    int cnt = 0;
    while(head != NULL)
    {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

bool isEmpty(Node *head)
{
    return (head == NULL) ? true : false;
}

void selSort(Node *head)
{
    for(Node *p = head; p->next != NULL; p = p->next)
    {
        Node *min = p;
        for(Node *q = p->next; q != NULL;  q = q->next)
        {
            if(q->data < min->data)
            {
                min = q;
            }
        }
        swap(p->data, min->data);
    }
}

void merSort(Node *head)
{

}

// Add a new element
void pushFront(Node *&head, int x)
{
    Node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}

void pushBack(Node *&head, int x)
{
    Node *newNode = makeNode(x);
    Node *tmp = head;
    if(tmp == NULL)
    {
        head = newNode;
        return;
    }
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void insert(Node *&head, int x, int k)
{
    Node *newNode = makeNode(x);
    Node *tmp = head;
    if(k == 0)
    {
        pushFront(head, x);
        return;
    }
    for(int i = 0; i < k-1; ++i)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
}

// Remove element
void popFront(Node *&head)
{
    if(head == NULL) 
        return;
    Node *tmp = head;
    head = head->next;
    delete tmp;
}

void popBack(Node *&head)
{
    if(head == NULL)
        return;
    if(size(head) == 1)
    {
        popFront(head);
        return;
    }
    Node *tmp = head;
    while(tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    Node *tmp2 = tmp->next;
    tmp->next = NULL;
    delete tmp2;
}

void remove(Node *&head, int k)
{
    if(k == 0)
    {
        popFront(head);
        return;
    }
    if(k >= size(head))
        return;
    Node *tmp = head;
    for(int i = 0; i < k-1; ++i)
    {
        tmp = tmp->next;
    }
    Node *tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    delete tmp2;
}

int main()
{
    Node *head = NULL;
    srand(time(NULL));
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        pushFront(head, rand() % 19 - 9);
    }
    write(head);
    while(1)
    {
        cout << "--------------------------" << endl;
        cout << "1. In danh sach" << endl;
        cout << "2. So luong phan tu cua danh sach" << endl;
        cout << "3. Them phan tu" << endl;
        cout << "4. Xoa phan tu" << endl;
        cout << "5. Sap xep danh sach" << endl;
        cout << "0. Thoat" << endl;
        int choice;
        cout << "Nhap lua chon: "; cin >> choice;
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            write(head);
            break;
        case 2:
            cout << size(head) << endl;
            break;
        case 3:
            while(1)
            {
                cout << "--------------------------" << endl;
                cout << "1. Them phan tu dau danh sach" << endl;
                cout << "2. Them phan tu cuoi danh sach" << endl;
                cout << "3. Chen phan tu" << endl;
                cout << "0. Thoat" << endl;
                int choice2, x, k; cout << "Nhap lua chon: "; cin >> choice2;
                if(choice2 == 0)
                    break;
                else if(choice2 == 1)
                {
                    cout << "Nhap x: "; cin >> x;
                    pushFront(head, x);
                }
                else if(choice2 == 2)
                {
                    cout << "Nhap x: "; cin >> x;
                    pushBack(head, x);
                }
                else if(choice2 == 3)
                {
                    cout << "Nhap x: "; cin >> x;
                    cout << "Nhap vi tri:"; cin >> k;
                    insert(head, x, k);
                }
            }
            break;
        case 4:
            while(1)
            {
                cout << "--------------------------" << endl;
                cout << "1. Xoa phan tu dau danh sach" << endl;
                cout << "2. Xoa phan tu cuoi danh sach" << endl;
                cout << "3. Xoa phan tu vi tri k" << endl;
                cout << "0. Thoat" << endl;
                int choice2, k; cout << "Nhap lua chon: "; cin >> choice2;
                if(choice2 == 0)
                    break;
                else if(choice2 == 1)
                {
                    popFront(head);
                }
                else if(choice2 == 2)
                {
                    popBack(head);
                }
                else if(choice2 == 3)
                {
                    cout << "Nhap vi tri: "; cin >> k;
                    remove(head, k);
                }
            }
            break;

            
        default:
            break;
        }
    }
    return 0;
}