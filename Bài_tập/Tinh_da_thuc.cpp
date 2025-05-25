#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* MakeNode(int value)
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
    }

    void Push(int value)
    {
        Node* newNode = MakeNode(value);
        newNode->next = head;
        head = newNode;
    }

    void Pop()
    {
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

int main()
{
    Stack S;
    S.Push(1);
    S.Push(2);
    S.Push(3);
    S.Print();
    S.Pop();
    S.Print();

    return 0;
}