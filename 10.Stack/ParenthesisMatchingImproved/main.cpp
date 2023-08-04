#include <iostream>
#include<string.h>

using namespace std;

class Stack
{
public:
    int top;
    int sz;
    char *s;

    Stack(int sz)
    {
        this->sz=sz;
        s=new char[sz];
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

    char StackTop()
    {
        return s[top];
    }

    void push(char x)
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

    char pop()
    {
        char x=-1;
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

    char peek(int pos)
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
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            {
                s.push(exp[i]);
            }
        else if(exp[i]<50 && exp[i]-s.pop()==1)
        {
            continue;
        }
        else if(exp[i]>90 && exp[i]-s.pop()==2)
        {
            continue;
        }
        else if(exp[i]==')' || exp[i]=='{' || exp[i]==']')
        {
            return false;
        }
    }
    return s.isEmpty() ? true:false;
}
int main()
{
    cout << "Parenthesis Matching Improved" << endl;
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
