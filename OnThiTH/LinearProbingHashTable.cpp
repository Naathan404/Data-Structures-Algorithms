#include <iostream>
using namespace std;

#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1
#define LOAD 0.7f

struct Node
{
    int key, flag;
};

struct HashTable
{
    int n; // so phan tu hien tai
    int M; // so phan tu toi da
    Node* table;
};

typedef HashTable ht;

void CreateEmptyHashTable(ht& H)
{
    cin >> H.M;
    H.table = new Node[H.M];
    H.n = 0;
    for(int i = 0; i < H.M; i++)
    {
        H.table[i].flag = EMPTY;
    }
}


int HF(int key, const ht& H)
{
    return key % H.M;
}

int LP_HF(int key, const ht& H, int i)
{
    return ((key % H.M) + i) % H.M;
}

bool Insert(ht& H, int x)
{
    if(((float)H.n + 1) / H.M > LOAD) return false;
    int i = 0, pos = HF(x, H);
    while(i < H.M)
    {
        if(H.table[pos].flag == OCCUPIED && H.table[pos].key == x)
            return false;
        if(H.table[pos].flag == EMPTY || H.table[pos].flag == DELETED)
        {
            H.table[pos].flag = OCCUPIED;
            H.table[pos].key = x;
            H.n++;
            return true;
        }
        i++;
        pos = LP_HF(x, H, i);
    }
    return false;
}

bool Delete(ht& H, int x)
{
    int i = 0, pos = HF(x, H);
    while(i < H.M)
    {
        if(H.table[pos].flag == EMPTY) return false;
        if(H.table[pos].flag == OCCUPIED && H.table[pos].key == x)
        {
            H.table[pos].flag = DELETED;
            H.n--;
            return true;
        }
        i++;
        pos = LP_HF(x, H, i);
    }
    return false;
}

void CreateHashTable(ht& H)
{
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1) return;
        Insert(H, x);
    }
}

void PrintHT(const ht& H)
{
    for(int i = 0; i< H.M; i++)
    {
        cout << i << " --> ";
        if(H.table[i].flag == EMPTY)    
            cout << "EMPTY";
        else if(H.table[i].flag == DELETED) 
            cout << "DELETED";
        else
            cout << H.table[i].key;
        cout << endl;
    }
}

int main()
{
    HashTable H;
    CreateEmptyHashTable(H);
    int k; cin >> k;
    while(k--)
    {
        int c, x; cin >> c >> x;
        if(c == 1)
            Insert(H, x);
        else
            Delete(H, x);
    }
    PrintHT(H);

    return 0;
}