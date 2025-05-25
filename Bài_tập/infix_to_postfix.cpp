#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

Node* MakeNode(char value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Stack
{
    Node* head = NULL;

    int Size()
    {
        Node *tempNode = head;
        int size = 0;
        while(tempNode != NULL)
        {
            size++;
            tempNode = tempNode->next;
        }
        return size;
    }

    bool isEmpty()
    {
        return (head == NULL) ? true : false;
    }
    char Top()
    {
        if(!isEmpty())
            return head->data;
    }

    void Push(char value)
    {
        Node* newNode = MakeNode(value);
        newNode->next = head;
        head = newNode;
    }

    void Pop()
    {
        if(head == NULL)
            return;
        Node* tempNode = head;
        head = head->next;
        delete tempNode;
    }

    void Print()
    {
        Node* tempNode = head;
        while(tempNode != NULL)
        {
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
        }
    }
};

int DoUuTien(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/' || c == '%')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else 
        return -1;
}

string CovertInfixToPostfix(string infix)
{
    Stack S;
    string postfix;
    for(int i = 0; i < infix.length(); i++)
    {
        if(infix[i] == ' ')
            continue;
        if(infix[i] >= '0' && infix[i] <= '9')
        {
            postfix += infix[i];
        }
        else if(infix[i] == '(')
        {
            S.Push('(');
        }
        else if(infix[i] == ')')
        {
            while(S.Top() != '(')
            {
                postfix += S.Top();
                S.Pop();
            }
            S.Pop();
        }
        else
        {
            while(DoUuTien(infix[i]) <= DoUuTien(S.Top()) && !S.isEmpty())
            {
                postfix += S.Top();
                S.Pop();
            }
            S.Push(infix[i]);
        }
    }

    while(!S.isEmpty())
    {
        postfix += S.Top();
        S.Pop();
    }
    return postfix;
}

int main()
{
    string infix;
    getline(cin, infix);
    string result = CovertInfixToPostfix(infix);
    cout << result;

    return 0;
}