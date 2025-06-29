#include <iostream>
using namespace std;
#define M 100

struct Node
{
    int key;
    Node* next;
};

typedef Node* HahsTable[M];

Node* MakeNode(int);
void AddTail(Node*&, int); 
int HF(int, int);
void CreateEmptyHashTable(HahsTable&, int);
void CreateHashTable(HahsTable&, int);
void PrintTable(const HahsTable&, int);
bool DeleteKey(HahsTable&, int, int);
void DeleteHashTable(HahsTable&, int);


int main()
{
    HahsTable H;
    int n; 
    cout << "Nhap so luong bucket: "; cin >> n;
    CreateEmptyHashTable(H, n);
    CreateHashTable(H, n);
    PrintTable(H, n);
    int tc; cout << endl; cin >> tc;
    while(tc--)
    {
        int x;
        cin >> x;
        DeleteKey(H, n, x);
        PrintTable(H, n);
        cout << endl;
    }

    return 0;
}

Node* MakeNode(int value)
{
    Node* newNode = new Node;
    newNode->key = value;
    newNode->next = NULL;
    return newNode;
} 

void AddTail(Node*& head, int value)
{
    Node* p = MakeNode(value);
    if(head == NULL)
    {
        head = p;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = p;
}

int HF(int key, int numbucket) { return key % numbucket; }

void CreateEmptyHashTable(HahsTable& H, int numbucket)
{
    for(int i = 0; i < numbucket; i++)
        H[i] = NULL;
}

void CreateHashTable(HahsTable& H, int numbucket)
{
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1) return;
        AddTail(H[HF(x, numbucket)], x);
    }
}
void PrintTable(const HahsTable& H, int numbucket)
{
    for(int i = 0; i < numbucket; i++)
    {
        cout << i;
        Node* head = H[i];
        while(head != NULL)
        {
            cout << " --> " << head->key;
            head = head->next;
        }
        cout << endl;
    }
}

bool DeleteKey(HahsTable& H, int numbucket, int x)
{
    int bucket = HF(x, numbucket);
    Node* prev = NULL;
    Node* curr = H[bucket];
    while(curr != NULL)
    {
        if(curr->key == x)
        {
            if(prev == NULL)
            {
                H[bucket] = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            delete curr;
            curr = NULL;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

void DeleteHashTable(HahsTable& H, int numbucket)
{
    for(int i = 0; i < numbucket; i++)
    {
        delete[] H[i];
        H[i] = NULL;
    }
}