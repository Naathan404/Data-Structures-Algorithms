#include <iostream>
using namespace std;

/*
    Stack co cac thao tac co ban sau:
        push
        pop
        top
        size
        isEmpty
*/

class Stack
{
    private:
        struct Node
        {
            int data;
            Node *next;
        };
        Node *head = NULL;
        Node *makeNode(int value)
        {
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = nullptr;
            return newNode;
        }

    public:
        void push(int value);

        int top();

        void pop();

        int size();

        bool isEmpty();
};

int main()
{
    Stack st;
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        st.push(x);
    }
    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    st.pop();
    cout << st.top();

    return 0;
}

void Stack::push(int value)
{
    Node *newNode = makeNode(value);
    newNode->next = head;
    head = newNode;
}

int Stack::top()
{
    if(head != NULL)
        return head->data;
}

void Stack::pop()
{
    if(head == NULL)
        return;
    Node *tmp = head;
    head = head->next;
    delete tmp;
}

int Stack::size()
{
    if(head == NULL)
        return 0;
    Node *tmp = head;
    int count = 0;
    while(tmp != NULL)
    {
        ++count;
        tmp = tmp->next;
    }
    return count;
}

bool Stack::isEmpty()
{
    if(head == NULL)
        return true;
    return false;
}