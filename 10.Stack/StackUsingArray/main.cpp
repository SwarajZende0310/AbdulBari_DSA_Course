#include <iostream>

using namespace std;

class Stack
{
public:
    int top;
    int sz;
    int *s;

    Stack(int sz)
    {
        this->sz=sz;
        s=new int[sz];
        top=-1;
    }

    bool isEmpty()
    {
        if(top==-1)
            return true;
        return false;
    }

    bool isFull()
    {
        if(top==sz-1)
            return true;
        return false;
    }

    int StackTop()
    {
        return s[top];
    }

    void push(int x)
    {
        if(isFull())
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            top++;
            s[top]=x;
        }
    }

    int pop()
    {
        int x=-1;
        if(isEmpty())
        {
            cout<<"Stack Underflow"<<endl;
        }
        else
        {
            x=s[top];
            top--;
        }
        return x;
    }

    int peek(int pos)
    {
        int x=-1;
        if(top-pos+1<0)
        {
            cout<<"Invalid Position"<<endl;
        }
        else
        {
            x=s[top-pos+1];
        }
        return x;
    }
    void display()
    {
        for(int i=0;i<sz;i++)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    cout << "Stack Using Array" << endl;
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    cout<<"Top of stack = "<<s1.StackTop()<<endl;
    s1.push(60);
    cout<<s1.pop()<<" popped out of stack"<<endl;
    cout<<"Element at position 2 is "<<s1.peek(2)<<endl;

    s1.display();
    return 0;
}
