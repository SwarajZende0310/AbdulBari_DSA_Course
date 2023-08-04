#include <iostream>

using namespace std;

int main()
{
    cout << "Essential Concepts Monolithic Programming" << endl;
    int length=0,breadth=0;

    cout<<"Enter Length and Breadth of Rectangle:"<<endl;
    cin>>length>>breadth;

    int area=length*breadth;
    int perimeter=2*(length+breadth);

    cout<<"Area of Rectangle is "<<area<<endl;
    cout<<"Perimeter of Rectangle is "<<perimeter<<endl;
    return 0;
}
