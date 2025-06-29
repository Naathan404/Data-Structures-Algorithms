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

bool Insert(HASHTABLE& H, int x)
{
    if(((float)H.n + 1) / H.M > LOAD) return false;
    int i = 0;
    int pos = HF(H, x);
    while(i < H.M)
    {
        if(H.table[pos].flag == OCCUPIED && H.table[pos].key == x) return false;
        if(H.table[pos].flag == EMPTY || H.table[pos].flag == DELETED)
        {
            H.table[pos].key = x;
            H.table[pos].flag = OCCUPIED;
            H.n++;
            return true;
        }
        i++;
        pos = HF_LinearProbing(H, x, i);
    }
    return false;
}

bool Delete(HASHTABLE& H, int x)
{
    int i = 0;
    int pos = HF(H, x);
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
        pos = HF_LinearProbing(H, x, i);
    }
    //return false;
}

void CreateHashTable(HASHTABLE& H)
{
    int M, num;
    cin >> M;
    H.M = M;
    H.n = 0;
    H.table = new NODE[H.M];
    for(int i = 0; i < H.M; i++)
        H.table[i].flag = EMPTY;

    cin >> num;
    int t1, t2;
    for(int i = 0; i < num; i++)
    {
        cin >> t1 >> t2;
        if(t1 == 1) Insert(H, t2);
        else if(t1 == 0) Delete(H, t2);
    }
}

void Traverse(const HASHTABLE& H)
{
    for(int i = 0; i < H.M; i++)
    {
        cout << i << " --> ";
        if(H.table[i].flag == OCCUPIED)
            cout << H.table[i].key;
        else if(H.table[i].flag == DELETED)
            cout << "DELETED";
        else
            cout << "EMPTY";
        cout << endl;
    }
}

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
