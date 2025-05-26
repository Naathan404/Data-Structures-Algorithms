

#include <iostream>
#include <string>

using namespace std;

#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct NODE {
    int flag; // Lưu trạng thái của NODE: -1:DELETE, 0:EMPTY, Giá trị khác: Node đang tồn tại giá trị
    int key;
};

struct HASHTABLE {
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    NODE *table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

int HF_LinearProbing(HASHTABLE ht, int key, int i) {
    int h=HF(ht, key);
    return (h + i) % ht.M;
}

bool Insert(HASHTABLE& H, int key)
{
    if(((float)H.n + 1) / H.M > LOAD) return false;
    int pos = HF(H, key), i = 0;
    while(i < H.M)
    {
        if(H.table[pos].flag == OCCUPIED && H.table[pos].key == key)
            return false;
        if(H.table[pos].flag == EMPTY || H.table[pos].flag == DELETED)
        {
            H.table[pos].key = key;
            H.table[pos].flag = OCCUPIED;
            H.n++;
            return true;
        }
        i++;
        pos = HF_LinearProbing(H, key, i);
    }
    return false;
}

void CreateHashTable(HASHTABLE& H)
{
    std::cin >> H.M;
    H.table = new NODE[H.M];
    for(int i = 0; i < H.M; i++)
        H.table[i].flag = EMPTY;
    H.n = 0;
    int x;
    while(true)
    {
        std::cin >> x;
        if(x == -1) return;
        Insert(H, x);
    }
}

void Traverse(HASHTABLE H)
{
    for(int i = 0; i < H.M; i++)
    {
        std::cout << i << " --> ";
        if(H.table[i].flag == OCCUPIED)
            std::cout << H.table[i].key;
        else if(H.table[i].flag == EMPTY)
            std::cout << "EMPTY";
        else
            std::cout << "DELETED";
        std::cout << std::endl;
    }
}


//// 


void DeleteHashtable(HASHTABLE &ht) {
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int main(){
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}
