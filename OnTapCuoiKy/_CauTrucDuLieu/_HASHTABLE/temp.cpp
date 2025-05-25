#include <iostream>
using namespace std;
#define M 100

struct NODE {
    int key;
    NODE *pNext;
};
// Khai báo kiểu con trỏ chỉ node
typedef NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];

NODE* CreateNode(int x) {
    NODE* p;
    p = new NODE;
    p->key = x;
    p->pNext = NULL;
    return p;
}
void AddTail(NODE* &head, int x) {
    NODE *p=CreateNode(x);
    if (head == NULL) head = p;
    else {
        NODE* i=head;
        while(i->pNext!=NULL){
            i=i->pNext;
        }
        i->pNext=p;
    }
}

int HF(int numbucket, int key) { return key % numbucket; }

///

///

int main(){
    HASHTABLE H;
    int numbucket;
    int x;

    CreateHashTable(H, numbucket);
    Traverse(H, numbucket);

    cin >> x;
    int i=Search(H, numbucket, x);
    cout << endl;
    if(i==-1)
        cout << x << " not found.";
    else
        cout << x << " found in bucket " << i << ".";
    return 0;
}
