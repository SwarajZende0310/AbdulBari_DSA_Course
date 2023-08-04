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

bool isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return false;
    return true;
}

int pre(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}

string InfixToPostfix(string infix)
{
    Stack s(infix.size()+2);
    string postfix;
    int i=0;

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix+=infix[i++];
        else
        {
            if(pre(infix[i]) > pre(s.StackTop()))
                s.push(infix[i++]);
            else
                postfix+=s.pop();
        }
    }
    while(!s.isEmpty())
    {
        postfix+=s.pop();
    }
    cout<<postfix<<endl;
    return postfix;
}

/*char* InfixToPostfix(char* infix)
{
    Stack s(strlen(infix));
    char* postfix=new char[strlen(infix)+1];
    int i=0,j=0;

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(pre(infix[i]) > pre(s.StackTop()))
                s.push(infix[i++]);
            else
                postfix[j++]=s.pop();
        }
    }
    postfix[j]='\0';
    return postfix;
}*/
int main()
{
    cout << "Infix to Postfix using Stack" << endl;
    string infix="a+b*c";
    string postfix=InfixToPostfix(infix);
    cout<<"Postfix form :: "<<postfix<<endl;
    return 0;
}
