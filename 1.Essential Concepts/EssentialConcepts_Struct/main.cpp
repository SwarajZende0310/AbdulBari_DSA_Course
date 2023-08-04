#include <iostream>

using namespace std;

struct Rectangle
{
private:
    int length;
    int breadth;
public:
    Rectangle(int l=1,int b=1)
    {
        length=l;
        breadth=b;
    }
    int Area(){return length*breadth;}
    int Perimeter(){return 2*(length+breadth);}
    int getLength(){return length;}
    int getBreadth(){return breadth;}
    void setLength(int l){length=l;}
    void setBreadth(int b){breadth=b;}
    ~Rectangle(){cout<<"Rectangle Destroyed"<<endl;}
};
int main()
{
    cout << "Essential Concepts: Struct" << endl;
    struct Rectangle r1(5,5);
    cout<<"Area of Rectangle is "<<r1.Area()<<endl;
    cout<<"Perimeter of Rectangle is "<<r1.Perimeter()<<endl;

    return 0;
}
