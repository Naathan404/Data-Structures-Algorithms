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

void Testing_Push_Pop_Top_Stack(stack s)
{
    int x;
    cout << "output: ";
    while(1)
    {
        cin >> x;
        if(x == -1)
            break;
        if(x == 0)
        {
            if(!empty(s))
            {
                cout << top(s) << " ";
                pop(s);
            }
        }
        else 
        {
            push(s, x);
        }
    }
    cout << "\ntop: ";
    if(!empty(s))
        cout << top(s) << " ";
}

int main() {
    stack s;
    Testing_Push_Pop_Top_Stack(s);
    return 0;
}
