#include <iostream>

using namespace std;

int main()
{
    cout << "Increasing size of Array:" << endl;
    //Actually cannot increase the size of same array as we don't know whether further consecutive location are free or not
    int *p=new int[5];
    p[0]=1;
    p[1]=3;
    p[2]=5;
    p[3]=7;
    p[4]=9;
    int *q;
    int desiredsize=10;
    q=new int[desiredsize];
    for(int i=0;i<5;i++)
    {
        q[i]=p[i];
    }
    delete []p;
    p=q;
    q=nullptr;

    cout<<"Displaying new Array"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<p[i]<<" ";
    }
    return 0;
}
