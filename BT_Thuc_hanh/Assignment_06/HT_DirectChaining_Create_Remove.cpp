
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

void InitHashTable(HASHTABLE &H, int numbucket) {
    for (int i = 0; i<numbucket; i++)
        H[i] = NULL;
}

void TraverseBucket(HASHTABLE H, int i) {
    NODEPTR p = H[i];
    while (p != NULL) {
        cout << " --> " << p->key;
        p = p->pNext;
    }
}
void Traverse(HASHTABLE H, int numbucket) {
    for (int i = 0; i<numbucket; i++) {
        cout << i ;
        TraverseBucket(H, i);
        cout << endl;
    }
}

////
void CreateHashTable(HASHTABLE& H, int& n)
{
    cin >> n;
    InitHashTable(H, n);
    int key, bucket;
    while(true)
    {
        cin >> key;
        if(key == -1) return;
        bucket = HF(n, key);
        AddTail(H[bucket], key);
    }
}

bool Remove(HASHTABLE& H, int n, int x)
{
    int bucket = HF(n, x);
    NODE* curr = H[bucket];
    NODE* prev = NULL;
    while(curr != NULL)
    {
        if(curr->key == x)
        {
            NODE* temp = curr;
            if(prev == NULL)
            {
                H[bucket] = curr->pNext;
            }
            else
            {
                prev->pNext = curr->pNext;
            }
            delete temp;
            return true;
        }
        prev = curr;
        curr = curr->pNext;
    }
    return false;
}


////



int main(){
    HASHTABLE H;
    int numbucket;
    int x;

    CreateHashTable(H, numbucket);

    Traverse(H, numbucket);

    cin >> x;
    if (Remove(H, numbucket, x)) {
        cout << endl << x << ": Delete Successful."  << endl << endl;
        Traverse(H, numbucket);
    }
    else cout << endl << x << ": Delete Failed." << endl << endl;

    return 0;
}
