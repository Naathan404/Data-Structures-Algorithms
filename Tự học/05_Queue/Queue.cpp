#include <iostream>
// #include <queue>
using namespace std;

// Queue hoat dong theo quy tac FIFO
// Cac thao tac co ban tren cau truc du lieu Queue
// enQueue
// deQueue
// peak
// size
// isEmpty

class Queue
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *makeNode(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
    }
    Node *front = NULL;

public:
    void enQueue(int value);
    void deQueue();
    int peak();
    int size();
    bool isEmpty();
    void Print();
};

int main()
{
    Queue q;
    q.enQueue(12);
    cout << q.size() << endl;
    q.Print(); cout << endl;
    q.enQueue(10);
    cout << q.size() << endl;
    q.Print(); cout << endl;
    q.enQueue(15);
    cout << q.size() << endl;
    q.Print(); cout << endl;
    q.deQueue();
    cout << q.size() << endl;
    q.Print(); cout << endl;
    q.deQueue();
    cout << q.size() << endl;
    q.Print(); cout << endl;
    q.deQueue();
    cout << q.size() << endl;
    q.Print(); cout << endl;
    //q.Print();

    return 0;
}

void Queue::enQueue(int value)
{
    Node *newNode = makeNode(value);
    Node *tmp = front;
    if(front == NULL)
    {
        front = newNode;
        return;
    }
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void Queue::deQueue()
{
    if(front == NULL)
        return;
    Node *temp = front;
    front = front->next;
    delete temp;
}

int Queue::peak()
{
    if(front != NULL)
        return front->data;
}

int Queue::size()
{
    int count = 0;
    Node *temp = front;
    while(temp != NULL)
    {
        ++count;
        temp = temp->next;
    }
    return count;
}

void Queue::Print()
{
    Node *temp = front;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool Queue::isEmpty()
{
    return (front == NULL) ? true : false;
}