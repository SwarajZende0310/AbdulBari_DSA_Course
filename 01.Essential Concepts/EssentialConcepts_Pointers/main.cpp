#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    cout << "Essential Concepts:POINTERS" << endl;
    int a=10;
    int *p;
    p=&a;
    cout<<"a="<<a<<" and *p="<<*p<<endl;

    int b[]={1,2,3,4,5};
    p=b;//Points to starting element of an array
    //p=&b[0];  //Can also be done like this

    cout<<"Array b iterating using pointer p:"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<p[i]<<" ";//In case of an array pointer acts as name of the array
    }
    cout<<endl;

    //Creating array in heap in C
    int *p1;
    p1=(int*)malloc(5*sizeof(int));
    p1[0]=6,p1[1]=7,p1[2]=8,p1[3]=9,p1[4]=10;

    cout<<"Array from heap in C:"<<endl;
    for(int i=0;i<5;i++)
        cout<<p1[i]<<" ";
    free(p1);//Deallocating the memory
    cout<<endl;

    //Creating array in heap in C++
    char *p2;
    p2=new char[5];
    p2[0]='a',p2[1]='b',p2[2]='c',p2[3]='d',p2[4]='e';
    cout<<"Array from heap in C++:"<<endl;
    for(int i=0;i<5;i++)
        cout<<p2[i]<<" ";
    delete []p2;//Deallocating the memory
    cout<<endl;

    //Size of a pointer is same regardless of its data type
    int *p3;
    double *p4;
    char *p5;
    float *p6;

    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;
    cout<<sizeof(p6)<<endl;
    return 0;
}
