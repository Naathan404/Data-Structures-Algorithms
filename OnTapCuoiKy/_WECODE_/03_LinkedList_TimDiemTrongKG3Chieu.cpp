#include <iostream>
#include <cmath>

using namespace std;

/////
struct Coordinate
{
    float x, y, z;
};

struct Node
{
    Coordinate data;
    Node* next;
};

Node* MakeNode(float x, float y, float z)
{
    Node* p = new Node;
    p->data.x = x;
    p->data.y = y;
    p->data.z = z;
    p->next = NULL;
    return p;
}

struct List
{
    Node* head = NULL;
    Node* tail = NULL;
};

void AddTail(List& L, float x, float y, float z)
{
    Node* p = MakeNode(x, y, z);
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
    float x, y, z;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> x >> y >> z;
        AddTail(L, x, y, z);
    }
}

bool CompareNode(Node* a, Node* b)
{
    return ((a->data.x == b->data.x)
    && (a->data.y == b->data.y)
    && (a->data.z == b->data.z));
}

void Search(const List& L, Node* b)
{
    if(L.head == NULL)
    {
        cout << "KHONG" << endl; 
        return;
    }
    // return ((a->data.x == b->data.x)
    // && (a->data.y == b->data.y)
    // && (a->data.z == b->data.z));
    int i = 0;
    Node* head = L.head;
    while(head != NULL)
    {
        if(CompareNode(head, b))
        {
            cout << i << endl;
            return;
        }
        i++;
        head = head->next;
    }
    cout << "KHONG" << endl;
}

void run()
{
    List L;
    CreateList(L);
    int m;
    float _x, _y, _z;
    cin >> m;
    while(m--)
    {
        cin >> _x >> _y >> _z;
        Node* temp = MakeNode(_x, _y, _z);
        Search(L, temp);
    }
}


////

int main() {

    int * a = new int[256];
    int * b = new int[256];
    delete [] a;
    run();
    delete [] b;
}