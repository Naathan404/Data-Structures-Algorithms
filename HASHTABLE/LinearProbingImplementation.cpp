#include <iostream>
using namespace std;

#define LOAD_FACTOR 0.7
#define OCCURPIED 1
#define DELETE -1
#define EMPTY 0

struct Node
{
    int key;
    int flag;
};

struct HashTable
{   
    int M, n;
    Node* table;
};

int HashFunction(int, const HashTable&);
int LinearProbing_HF(int, const HashTable& , int);
void CreateEmptyHashTable(HashTable&, int);
void CreateHashTable(HashTable&);
bool Insert(HashTable&, int);
bool Delete(HashTable&, int);
bool Search(const HashTable&, int);
void PrintTable(const HashTable&);

int main()
{
    HashTable H;
    int size, numberOfElements;
    cout << "Nhap kich thuoc bang bam: "; 
    cin >> size;
    CreateEmptyHashTable(H, size);
    CreateHashTable(H);
    PrintTable(H);
    
    return 0;
}

int HashFunction(int key, const HashTable& H)
{
    return key % H.M;
}

int LinearProbing_HF(int key, const HashTable& H, int i)
{
    return (HashFunction(key, H) + i) % H.M;
}

void CreateEmptyHashTable(HashTable& H, int size)
{
    H.M = size;
    H.n = 0;
    H.table = new Node[H.M];
    for(int i = 0; i < H.M; i++)
    {
        H.table[i].flag = EMPTY;
        H.table[i].key = -1;
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

bool Insert(HashTable& H, int x)
{
    if((float)(H.n + 1) / H.M > LOAD_FACTOR)
        return false;
    int insertPos = HashFunction(x, H);
    int i = 0;
    while(i < H.M)
    {
        
        if(H.table[insertPos].flag == OCCURPIED && H.table[insertPos].key == x)
            return false;
        if(H.table[insertPos].flag == EMPTY || H.table[insertPos].flag == DELETE)
        {
            H.table[insertPos].key = x;
            H.table[insertPos].flag = OCCURPIED;
            H.n++;
            return true;
        }
        i++;
        insertPos = LinearProbing_HF(x, H, i);
    }
    return false;
}

bool Delete(HashTable& H, int x)
{
    int pos = HashFunction(x, H);
    int i = 0;
    while(i < H.M)
    {
        if(H.table[pos].flag == EMPTY)
            return false;
        if(H.table[pos].flag == OCCURPIED && H.table[pos].key == x)
        {
            H.table[pos].flag = DELETE;
            H.n--;
            return true;
        }
        i++;
        pos = LinearProbing_HF(x, H, i);
    }
    return false;
}

bool Search(const HashTable& H, int x)
{
    int pos = HashFunction(x, H);
    int i = 0;
    while(i < H.M)
    {
        if(H.table[pos].flag == EMPTY)
            return false;
        if(H.table[pos].flag == OCCURPIED && H.table[pos].key == x)
            return true;
        i++;
        pos = LinearProbing_HF(x, H, i);
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