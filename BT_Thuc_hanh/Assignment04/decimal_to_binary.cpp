#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* makeNode(int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

struct stack
{
    Node* head = NULL;
};

void push(stack &s, int x)
{
    Node* newNode = makeNode(x);
    newNode->next = s.head;
    s.head = newNode;
}

void pop(stack& s)
{
    if(s.head == NULL)
        return;
    Node* tempNode = s.head;
    s.head = s.head->next;
    delete tempNode;
}

int top(stack s)
{
    return s.head->data;
}

bool empty(stack s)
{
    return (s.head == NULL ? true : false);
}

void decimal_to_binary(int n)
{
    if(n == 0)
    {
        cout << 0;
        return;
    }
    stack s;
    while(n != 0)
    {
        push(s, n % 2);
        n /= 2;
    }
    while(!empty(s))
    {
        cout << top(s);
        pop(s);
    }
}

int main() {
    int n;
    cin >> n;
    decimal_to_binary(n);
    return 0;
}
