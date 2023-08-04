#include <iostream>
#include<stdio.h>
using namespace std;

int add(int a,int b)
{
    return a+b;
}
int main()
{
    cout << "Essential Concepts:Functions" << endl;
    int x=10,y=20;
    int sum=add(x,y);
    printf("Sum is %d",sum);
    return 0;
}
