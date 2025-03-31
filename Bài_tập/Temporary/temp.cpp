#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head = NULL;

    Node *MakeNode(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
    }

public:
    void PrintList()
    {
        Node *tempNode = head;
        while(tempNode != NULL)
        {
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
        }
    }

    int Length()
    {
        Node *tempNode = head;
        int count = 0;
        while(tempNode != NULL)
        {
            count++;
            tempNode = tempNode->next;
        }
        return count;
    }

    void PushFront(int value)
    {
        Node *newNode = MakeNode(value);
        newNode->next = head;
        head = newNode;
    }

    void PopFront()
    {
        if(head == NULL)
            return;
        Node *tempNode = head;
        head = head->next;
        delete tempNode;
    }

    void PushBack(int value)
    {
        Node *newNode = MakeNode(value);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        Node *tempNode = head;
        while(tempNode->next != NULL)
        {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }

    void InsertNode(int value, int insertPosition)
    {
        Node *tempNode = head;
        Node *newNode = MakeNode(value);
        int currentPosition = 0;
        if(insertPosition == 0)
        {
            PushFront(value);
            return;
        }
        while(currentPosition < insertPosition - 1)
        {
            tempNode = tempNode->next;
            currentPosition++;
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }

    void ReverseList()
    {
        Node *currentNode = head;
        while(currentNode->next != NULL)
        {
            Node *prevNode = currentNode;
            currentNode = currentNode->next;
            currentNode->next = prevNode;
        }
    }

};



int main()
{
    LinkedList A, B;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        A.PushBack(x);
    }
    
    A.PrintList();
    cout << endl;

    A.ReverseList();
    A.PrintList();
    return 0;
}