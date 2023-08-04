#include <iostream>

using namespace std;

template <class T>
class Arithamatic
{
private:
    T x;
    T y;
public:
    Arithamatic(T a,T b)
    {
        x=a;
        y=b;
    }
    T add();
    T sub();
} ;
template<class T>
T Arithamatic<T>::add()
{
    return x+y;
}

template<class T>
T Arithamatic<T>::sub()
{
    return x-y;
}
int main()
{
    cout << "Essential Concepts: Template classes" << endl;
    Arithamatic<int> arr(1,5);
    cout<<"Addition is "<<arr.add()<<endl;
    cout<<"Subtraction is "<<arr.sub()<<endl;
    cout<<endl;

    Arithamatic<float> arr2(1.5,0.7);
    cout<<"Addition is "<<arr2.add()<<endl;
    cout<<"Subtraction is "<<arr2.sub()<<endl;
    return 0;
}
