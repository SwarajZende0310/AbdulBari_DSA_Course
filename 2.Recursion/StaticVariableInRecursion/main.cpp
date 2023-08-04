#include <iostream>

using namespace std;

int fun1(int x)
{
    if(x>0)
        return fun1(x-1)+x;
    return 0;
}

int fun2(int x)
{
    static int n=0;
    if(x>0)
    {
        n++;
        return fun2(x-1)+n;
    }
    return 0;
}
int main()
{
    cout << "Static Variable in Recursion" << endl;
    cout<<fun1(5)<<endl;
    cout<<fun2(5)<<endl;
    return 0;
}
