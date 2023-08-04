#include <iostream>

using namespace std;

int area(int l,int b){return l*b;}
int perimeter(int l,int b){return 2*(l+b);}
int main()
{
    cout << "Essential Concepts: Modular Programming" << endl;
    int length=0,breadth=0;

    cout<<"Enter the Length and Breadth:"<<endl;
    cin>>length>>breadth;

    int a=area(length,breadth);
    int p=perimeter(length,breadth);

    cout<<"Area is "<<a<<endl;
    cout<<"Perimeter is "<<p<<endl;
    return 0;
}
