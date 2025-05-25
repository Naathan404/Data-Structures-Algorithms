
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


////
void Insert(HASHTABLE& H, int key)
{
    if((float)H.n / H.M > LOAD - 0.1) return;
    int pos = HF(H, key);
    int i = 0;
    while(i < H.M)
    {
        if (H.table[pos].flag == OCCUPIED && H.table[pos].key == key)
            return;
        if(H.table[pos].flag == EMPTY || H.table[pos].flag == DELETED)
        {
            H.table[pos].key = key;
            H.table[pos].flag = OCCUPIED;
            H.n++;
            return;
        }
        i++;
        pos = HF_LinearProbing(H, key, i);
    }
}

void Delete(HASHTABLE& H, int x)
{
    int pos = HF(H, x);
    int i = 0;
    while(i < H.M)
    {
        if(H.table[pos].flag == EMPTY) return;
        if(H.table[pos].flag == OCCUPIED && H.table[pos].key == x)
        {
            H.table[pos].flag = DELETED;
            H.n--;
            return;
        }
        i++;
        pos = HF_LinearProbing(H, x, i);
    }
}

void CreateHashTable(HASHTABLE& H)
{
    int numAction, action, key;
    cin >> H.M;
    cin >> numAction;

    H.table = new NODE[H.M];
    for(int i = 0; i < H.M; i++)
        H.table[i].flag = EMPTY;
    H.n = 0;
    while(numAction--)
    {
        cin >> action >> key;
        if(action == 1)
            Insert(H, key);
        else    
            Delete(H, key);
    }

}

void Traverse(HASHTABLE H)
{
    for(int i = 0; i < H.M; i++)
    {
        cout << i << " --> ";
        if(H.table[i].flag == DELETED)
            cout << "DELETED";
        else if(H.table[i].flag == EMPTY)
            cout << "EMPTY";
        else
            cout << H.table[i].key;
        cout << endl;
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
