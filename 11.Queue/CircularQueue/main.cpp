#include <iostream>

using namespace std;

class Queue
{
public:
    int sz;
    int Front;
    int rear;
    int *q;

    Queue(int sz)
    {
        this->sz=sz;
        Front=rear=0;
        q=new int[sz];
    }

    bool isEmpty()
    {
        if(Front==rear)
            return true;
        return false;
    }

    bool isFull()
    {
        if(Front==(rear+1)%sz)
            return true;
        return false;
    }

    void enqueue(int x)
    {
        if(isFull())
            cout<<"Queue is full"<<endl;
        else
        {
            rear=(rear+1)%sz;;
            q[rear]=x;
        }
    }

    int dequeue()
    {
        int x=-1;
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
        }
        else
        {
            Front=(Front+1)%sz;
            x=q[Front];
        }
        return x;
    }

    void display()
    {
        int i=Front+1;
        do
        {
            cout<<q[i]<<" ";
            i=(i+1)%sz;
        }while(i!=(rear+1)%sz);
        cout<<endl;
    }
};
int main()
{
    cout << "Queue using Array" << endl;
    Queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.display();

    q1.dequeue();
    q1.display();

    q1.enqueue(6);
    q1.display();
    return 0;
}
