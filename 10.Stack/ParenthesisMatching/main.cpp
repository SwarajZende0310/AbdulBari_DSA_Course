#include <iostream>
#include<string.h>

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

bool isBalance(string exp)
{
    int sz=exp.size();
    Stack s(sz);
    for(int i=0;i<sz;i++)
    {
        if(exp[i]=='(')
            s.push(1);
        else if(exp[i]==')')
        {
            if(s.isEmpty())
            {
                return false;
            }
            s.pop();
        }
    }
    return s.isEmpty() ? true:false;
}
int main()
{
    cout << "Parenthesis Matching" << endl;
    string s;
    cin>>s;
    if(isBalance(s))
    {
        cout<<"Parenthesis Matching"<<endl;
    }
    else
    {
        cout<<"Parenthesis not Matching"<<endl;
    }
    return 0;
}
