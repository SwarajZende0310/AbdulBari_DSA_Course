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
    void changeLength(int l)
    {
        length=l;
    }
};
int main()
{
    cout << "Essential Concepts: Converting Struct to Class in C++" << endl;
    Rectangle r(10,5);
    r.area();
    r.changeLength(20);
    r.area();
    return 0;
}
