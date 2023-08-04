#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};
int main()
{
    cout << "Essential Concepts:Pointer to Struct" << endl;
    //Creating object in stack
    struct Rectangle r1={10,20};
    struct Rectangle *p=&r1;
    cout<<"Length:"<<p->length<<endl;
    cout<<"Breadth:"<<p->breadth<<endl;

    //Creating object in Heap in C
    struct Rectangle *p1;
    p1=(struct Rectangle*)malloc(sizeof(struct Rectangle));
    p1->length=30;
    p1->breadth=40;
    cout<<"Length:"<<p1->length<<endl;
    cout<<"Breadth:"<<p1->breadth<<endl;
    free(p1);

    //Creating object in Heap in C++
    Rectangle *p2;
    p2=new Rectangle();
    p2->length=50;
    p2->breadth=60;
    cout<<"Length:"<<p2->length<<endl;
    cout<<"Breadth:"<<p2->breadth<<endl;
    delete p2;
    return 0;
}
