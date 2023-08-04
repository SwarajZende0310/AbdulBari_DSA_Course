#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

struct test
{
    int A[5];
    int n;
};
void fun1(struct Rectangle r1)
{
    cout<<"Call by Value:"<<endl;
    r1.length++;
    r1.breadth++;
    cout<<"Length: "<<r1.length<<endl;
    cout<<"Breadth: "<<r1.breadth<<endl;
}
void fun2(struct Rectangle *r2)
{
    cout<<"Call by Address:"<<endl;
    r2->length++;
    r2->breadth++;
    cout<<"Length: "<<r2->length<<endl;
    cout<<"Breadth: "<<r2->breadth<<endl;
}
void fun3(struct Rectangle &r3)
{
    cout<<"Call by Reference:"<<endl;
    r3.length++;
    r3.breadth++;
    cout<<"Length: "<<r3.length<<endl;
    cout<<"Breadth: "<<r3.breadth<<endl;
}

void fun4(struct test t1)
{
    cout<<"Here Array is taken by call by value."<<endl;
    for(int i=0;i<5;i++)
    {
        t1.A[i]=2*(i+1);
    }
    //t1.A={2,4,6,8,10}
    cout<<"Printing Array from Function"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<t1.A[i]<<" ";
    }
    cout<<endl;
}
struct Rectangle *fun5()
{
    struct Rectangle *p;
    cout<<"Creating object in function outside main function"<<endl;
    p=(struct Rectangle *)malloc(sizeof(struct Rectangle));
    // OR //p=new Rectangle();
    p->length=10;
    p->breadth=20;
    return p;
};
int main()
{
    cout << "Essential Concepts : Struct as a Parameter" << endl;
    struct Rectangle r={10,5};
    fun1(r);
    cout<<"Length: "<<r.length<<endl;
    cout<<"Breadth: "<<r.breadth<<endl;

    fun2(&r);
    cout<<"Length: "<<r.length<<endl;
    cout<<"Breadth: "<<r.breadth<<endl;

    fun3(r);
    cout<<"Length: "<<r.length<<endl;
    cout<<"Breadth: "<<r.breadth<<endl;

    struct test t={{1,2,3,4,5},6};
    fun4(t);
    cout<<"Printing the array from main method"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<t.A[i]<<" ";
    }
    cout<<endl;

    struct Rectangle *ptr=fun5();
    cout<<"Length: "<<ptr->length<<endl;
    cout<<"Breadth: "<<ptr->breadth<<endl;
    return 0;
}
