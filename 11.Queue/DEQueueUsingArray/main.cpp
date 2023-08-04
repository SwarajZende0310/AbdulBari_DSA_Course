#include <iostream>

using namespace std;

class DEQueue
{
public:
    int Front;
    int rear;
    int sz;
    int *q;

    DEQueue(int sz)
    {
        this->sz=sz;
        q=new int[sz];
        Front=rear=-1;
    }

    bool isEmpty()
    {
        if(Front==rear)
            return true;
        return false;
    }

    bool isFull()
    {
        if(rear==sz-1)
            return true;
        return false;
    }

    void frontEnqueue(int x)
    {
        if(Front==-1)
            cout<<"Cannot Insert from Front"<<endl;
        else
        {
            q[Front]=x;
            Front--;
        }
    }

    void rearEnqueue(int x)
    {
        if(isFull())
            cout<<"DEQueue is full"<<endl;
        else
        {
            rear++;
            q[rear]=x;
        }
    }

    int frontDequeue()
    {
        int x=-1;
        if(isEmpty())
            cout<<"DEQueue is Full"<<endl;
        else
        {
            Front++;
            x=q[Front];
        }
        return x;
    }

    int rearDequeue()
    {
        int x=-1;
        if(isEmpty())
            cout<<"DEQueue is Empty"<<endl;
        else
        {
            x=q[rear--];
        }
        return x;
    }

    void display()
    {
        for(int i=Front+1;i<rear;i++)
        {
            cout<<q[i]<<" ";
        }
        if(Front>=0)
        {
            for(int i=0;i<Front;i++)
            {
                cout<<q[i]<<" ";
            }
        }
        cout<<endl;
    }
};
int main()
{
    cout << "DEQueue using Array::" << endl;
    DEQueue q1(10);
    q1.rearEnqueue(1);
    q1.rearEnqueue(2);
    q1.rearEnqueue(3);
    q1.rearEnqueue(4);
    q1.rearEnqueue(5);
    q1.rearEnqueue(6);
    q1.display();

    q1.frontDequeue();
    q1.display();

    q1.frontEnqueue(7);
    q1.display();
    return 0;
}
