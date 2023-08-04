#include <iostream>

using namespace std;
double pow(int m,int n);
double fact(int m);

double Sine(int x,int n)
{
    static int l=1;
    if(n==0)
        return x;
    l++;
    return Sine(x,n-1) - pow(-1,l)*pow(x,n+l)/fact(n+l);
}
double pow(int m,int n)
{
    if(n==0)
        return 1;
    else if(n%2==0)
        return pow(m*m,n/2);
    else
        return m*pow(m*m,(n-1)/2);
}
double fact(int m)
{
    if(m==0)
        return 1;
    return m*fact(m-1);
}
int main()
{
    cout << "Taylor Series for Sine Function" << endl;
    double r=Sine(30,10);
    cout<<r;
    return 0;
}
