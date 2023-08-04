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

bool isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return false;
    return true;
}

int EvalPost(string postfix)
{
    Stack s(postfix.size()+2);
    int x1,x2,r;

    for(int i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            s.push(postfix[i]-'0');
        }
        else
        {
            x2=s.pop();
            x1=s.pop();
            switch (postfix[i])
            {
            case '+':
                r=x1+x2;
                s.push(r);
                break;
            case '-':
                r=x1-x2;
                s.push(r);
                break;
            case '*':
                r=x1*x2;
                s.push(r);
                break;
            case '/':
                r=x1/x2;
                s.push(r);
                break;
            }
        }
    }
    return s.pop();
}
int main()
{
    cout << "Evaluation of Postfix" << endl;
    string postfix;
    cin>>postfix;
    cout<<"Evaluation is "<<EvalPost(postfix)<<endl;
    return 0;
}
