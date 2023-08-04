#include <iostream>

using namespace std;

void swap1(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}
void swap2(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void swap3(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
    cout << "Essential Concepts:Parameter Passing" << endl;
    int a1=1,a2=2,a3=3;
    int b1=5,b2=6,b3=7;

    printf("\nPassing by Value:\n");
    printf("Number before swapping %d and %d\n",a1,b1);
    swap1(a1,b1);
    printf("Number after swapping %d and %d\n\n",a1,b1);

    printf("Passing by Address:\n");
    printf("Number before swapping %d and %d\n",a2,b2);
    swap2(&a2,&b2);
    printf("Number after swapping %d and %d\n\n",a2,b2);

    printf("Passing by Reference:\n");//    Only allowed in C++
    printf("Number before swapping %d and %d\n",a3,b3);
    swap3(a3,b3);
    printf("Number after swapping %d and %d\n\n",a3,b3);
    return 0;
}
