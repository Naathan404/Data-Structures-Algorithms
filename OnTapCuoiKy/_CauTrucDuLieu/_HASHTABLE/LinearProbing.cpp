#include <iostream>
using namespace std;

#define LOAD_FACTOR 0.7
#define DELETE -1
#define EMPTY 0
#define OCCURPIED 1

struct Node
{
    int key;
    int flag; // DELETE - EMPTY - OCCURPIED
};

struct HashTable
{
    int M, n;
    Node *table;
};

void CreateEmptyHashTable(HashTable&, int);
void CreateHashTable(HashTable&);
int HF(const HashTable&, int);
int HF_LinearProbing(const HashTable&, int, int);
bool Insert(HashTable&, int);
bool Delete(HashTable&, int);
bool Search(const HashTable&, int);
void PrintTable(const HashTable&);

int main()
{
    HashTable H;
    int size; cin >> size;
    CreateEmptyHashTable(H, size);
    CreateHashTable(H);
    PrintTable(H);

    return 0;
}

void CreateEmptyHashTable(HashTable& H, int size)
{
    H.M = size;
    H.n = 0;
    H.table = new Node[H.M];
    for(int i = 0; i < H.M; i++)
    {
        H.table[i].flag = EMPTY;
    }
}

void CreateHashTable(HashTable& H)
{
    int x;
    while(true)
    {
        cin >> x;
        if(x == -1) return;
        Insert(H, x);
    }
}

int HF(const HashTable& H, int key)
{
    return key % H.M;
}

int HF_LinearProbing(const HashTable& H, int key, int index)
{
    return (HF(H, key) + index) % H.M;
}

bool Insert(HashTable& H, int x)
{
    if(((float)(H.n + 1) / H.M) > LOAD_FACTOR) return false;
    int pos = HF(H, x);
    int i = 0;
    while(i < H.M)
    {
        if(H.table[pos].flag == OCCURPIED && H.table[pos].key == x)
            return false;
        if(H.table[pos].flag == EMPTY || H.table[pos].flag == DELETE)
        {
            H.table[pos].key = x;
            H.table[pos].flag = OCCURPIED;
            H.n++;
            return true;
        }
        i++;
        pos = HF_LinearProbing(H, x, i);
    }
    return false;
}

bool Delete(HashTable& H, int x)
{
    int pos = HF(H, x);
    int i = 0;
    while(i < H.M)
    {
        if(H.table[pos].flag == EMPTY) return false;
        if(H.table[pos].flag == OCCURPIED && H.table[pos].key == x)
        {
            H.table[pos].flag = DELETE;
            H.n--;
            return true;
        }
        i++;
        pos = HF_LinearProbing(H, x, i);
    }
    return false;
}

bool Search(const HashTable& H, int x)
{
    int pos = HF(H, x);
    int i = 0;
    while(i < H.M)
    {
        if(H.table[pos].flag == EMPTY) 
            return false;
        if(H.table[pos].flag == OCCURPIED && H.table[pos].key == x)
            return true;
        i++;
        pos = HF_LinearProbing(H, x, i);
    }
    return false;
}

void PrintTable(const HashTable& H)
{
    for(int i = 0; i < H.M; i++)
    {
        cout << i << " --> ";
        if(H.table[i].flag == OCCURPIED)
            cout << H.table[i].key << endl;
        else
            cout << "EMPTY" << endl;
    }
}