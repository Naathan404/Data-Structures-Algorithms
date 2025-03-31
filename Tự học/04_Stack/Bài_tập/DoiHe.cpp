#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

Node *makeNode(string x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

string Top(Node *head)
{
    if(head != NULL)
        return head->data;
}

void Pop(Node *&head)
{
    if(head == NULL)
        return;
    head = head->next;
}

void Push(string x, Node *&head)
{
    Node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}

bool isEmpty(Node *head)
{
    return (head == NULL) ? true : false;
}

void ChuyenDoiSo(int num)
{
    Node *head = NULL;
    if(num == 0)
    {
        cout << 0;
        return;
    }
    int tmp;
    while(num != 0)
    {
        tmp = num % 16;
        num /= 16;
        if(tmp < 10)
            Push(to_string(tmp), head);
        else if(tmp == 10)
            Push("A", head);
        else if(tmp == 11)
            Push("B", head);
        else if(tmp == 12)
            Push("C", head);
        else if(tmp == 13)
            Push("D", head);
        else if(tmp == 14)
            Push("E", head);
        else if(tmp == 15)
            Push("F", head);
    }
    while(!isEmpty(head))
    {
        cout << Top(head);
        Pop(head);
    }
}

main()
{
    int n; cin >> n;
    ChuyenDoiSo(n);

    return 0;
}