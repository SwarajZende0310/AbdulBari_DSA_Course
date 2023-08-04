#include <iostream>

using namespace std;

class Rectangle
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
    void area()
    {
        cout<<"Area is "<<length*breadth<<endl;
    }
    void perimeter()
    {
        cout<<"Perimeter is "<<2*(length+breadth)<<endl;
    }
};
int main()
{
    cout << "Essential Concepts: Object Oriented Programming" << endl;
    int l,b;
    cout<<"Enter the Length and Breadth:"<<endl;
    cin>>l>>b;
    Rectangle r(l,b);
    r.area();
    r.perimeter();
    return 0;
}
