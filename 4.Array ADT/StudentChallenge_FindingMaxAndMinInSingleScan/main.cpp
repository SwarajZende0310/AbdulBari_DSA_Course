#include <iostream>

using namespace std;

int main()
{
    cout << "Finding Max and Min in Single Scan: " << endl;
    int A[]={5,8,3,9,6,2,10,7,-1,4};
    int Alen=sizeof(A)/sizeof(int);

    int max1=A[0];
    int min1=A[0];
    for(int i=0;i<Alen;i++)
    {
        if(A[i]<min1)
        {
            min1=A[i];
        }
        else if(A[i]>max1)
        {
            max1=A[i];
        }
    }

    cout<<"Maximum is "<<max1<<endl;
    cout<<"Minimum is "<<min1<<endl;
    return 0;
}
