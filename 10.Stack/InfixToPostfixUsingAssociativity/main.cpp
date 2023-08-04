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
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')')
        return false;
    return true;
}

int outpre(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 3;
    else if(x=='^')
        return 6;
    else if(x=='(')
        return 7;
    else if(x==')')
        return 0;
    return 0;
}

int inpre(char x)
{
    if(x=='+' || x=='-')
        return 2;
    else if(x=='*' || x=='/')
        return 4;
    else if(x=='^')
        return 5;
    else if(x=='(')
        return 0;
    else if(x==')')
        return 0;
    return 0;
}
string InfixToPostfixUsingAssociativity(string infix)
{
    Stack s(infix.size()+2);
    string postfix;
    int i=0;

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix+=infix[i++];
        else if(infix[i]==')')
        {
            while(!s.isEmpty() && infix[i]!='(')
            {
                postfix+=s.pop();
            }
            //Poping opening parenthesis
            s.pop();
        }
        else
        {
            if(s.isEmpty() || outpre(infix[i]) > inpre(s.StackTop()))
                s.push(infix[i++]);
            else
            {
                while(!s.isEmpty() && outpre(infix[i])<inpre(s.StackTop()))
                {
                    postfix+=s.pop();
                }
                s.push(infix[i++]);
            }
        }
    }
    while(!s.isEmpty())
    {
        postfix+=s.pop();
    }
    return postfix;
}
int main()
{
    cout << "Infix to postfix using Associativity" << endl;
    string infix;
    cin>>infix;
    string postfix=InfixToPostfixUsingAssociativity(infix);
    cout<<postfix<<endl;
    return 0;
}
