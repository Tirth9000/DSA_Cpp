#include<iostream>
using namespace std;

class Queue 
{
public: 
    int front,rear;
    int max;

private: 
    int que[];

public:
    Queue(int val)
    {
        max = val;
        front = -1;
        rear = -1;
        int que[max];
    }

    void insert(int a)
    {
        if (front == 0 && rear == max-1)
        {
            cout<<"ERROR: The Queue is full."<<endl;
        }
        else if(front != 0 && rear == max-1)
        {
            rear = 0;
        }
        else if(front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }

        que[rear] = a;
    }

    void deletion()
    {
        if(front == -1 && rear == -1)
        {
            cout<<"ERROR: The Queue is empty."<<endl;
        }
        else if(front == max-1 && rear != max-1)
        {
            que[front] = 0;
            front = 0;
        }
        else if(front == rear)
        {
            que[front] = 0;
            front = -1;
            rear = -1;
        }
        else 
        {
            que[front] = 0;
            front++;
        }
    }

    void print()
    {
        cout<<"Queue elements are:"<<endl;

        for(int i=0;i<max;i++)
        {
            cout<<"a["<<i<<"] = "<<que[i]<<endl;
        }
    }

};

int main()
{
    Queue q(10),u(7);

    q.insert(1);
    q.insert(1);
    q.insert(1);
    q.insert(1);
    q.insert(1);
    q.insert(1);
    q.insert(1);
    q.insert(1);
    q.insert(1);
    q.insert(1);

    q.print();

    q.deletion();
    q.deletion();
    q.deletion();
    q.deletion();
    q.deletion();
    q.deletion();

    q.print();

    q.insert(6);
    q.insert(9);
    q.insert(7);

    q.print();

    u.insert(8);
    u.insert(8);
    u.insert(8);
    u.insert(8);
    u.insert(8);
    u.insert(8);
    u.insert(8);

    u.print();

    u.deletion();
    u.deletion();
    u.deletion();
    u.deletion();
    u.deletion();
    u.deletion();
    u.deletion();
    u.deletion();
    u.deletion();

    u.print();
}