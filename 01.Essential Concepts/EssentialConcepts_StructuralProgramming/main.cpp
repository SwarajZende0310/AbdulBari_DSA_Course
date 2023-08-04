#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void initializeRect(struct Rectangle *p,int l,int b)
{
    p->length=l;
    p->breadth=b;
}
void area(struct Rectangle r)
{
    cout<<"Area is "<<r.length*r.breadth<<endl;
}

void perimeter(struct Rectangle r)
{
    cout<<"Perimeter is "<<2*(r.length+r.breadth)<<endl;
}
int main()
{
    cout << "Essential Concepts : Structural Programming" << endl;
    struct Rectangle r1;
    int l,b;
    cout<<"Enter Length and Breadth: "<<endl;
    cin>>l>>b;

    initializeRect(&r1,l,b);
    area(r1);
    perimeter(r1);
    return 0;
}

