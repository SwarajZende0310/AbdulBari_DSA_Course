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

void changeLength(struct Rectangle *p,int l)
{
    p->length=l;
}
int main()
{
    cout << "Essential Concepts : Structures and Functions" << endl;
    struct Rectangle r1;
    initializeRect(&r1,10,20);
    area(r1);
    changeLength(&r1,20);
    area(r1);
    return 0;
}
