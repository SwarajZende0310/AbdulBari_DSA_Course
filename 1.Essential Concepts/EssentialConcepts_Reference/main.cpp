#include <iostream>

using namespace std;

int main()
{
    cout << "Essential Concepts:Reference" << endl;
    int a=10;
    int &r=a;//Reference is the nickname to the given variable
    cout<<"Value of a:"<<a<<endl<<"Value of r:"<<r<<endl;
    r++;
    cout<<"Value of a:"<<a<<endl<<"Value of r:"<<r<<endl;

    int b=30;
    r=b;//This is assignment not initialization as in 'r' is still reference to a
    cout<<"Value of a:"<<a<<endl<<"Value of r:"<<r<<endl;
    return 0;
}
