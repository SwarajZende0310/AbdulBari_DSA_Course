#include <iostream>

using namespace std;

class UpperTriangular
{
private:
    int *A;
    int n;
public:
    UpperTriangular(int x)
    {
        n=x;
        A=new int[n*(n+1)/2];
    }
    void Set(int i,int j,int x)
    {
        if(i<=j)
        {
            A[(n*(i-1)-(i-2)*(i-1)/2)+(j-i)]=x;
        }
    }
    int Get(int i,int j)
    {
        if(i<=j)
            return A[(n*(i-1)-(i-2)*(i-1)/2)+(j-i)];
        return 0;
    }
    void display();
    ~UpperTriangular()
    {
        delete []A;
        A=nullptr;
    }
};

void UpperTriangular::display()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<Get(i+1,j+1)<<" ";
            }
            cout<<endl;
        }
    }
int main()
{
    int x,d;
    cout << "Upper Triangular Matrix using Row Major" << endl;
    cout<<"Enter the Dimension of Array: "<<endl;
    cin>>d;
    UpperTriangular m(d);
    cout<<"Enter all Elements: "<<endl;
    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            cin>>x;
            m.Set(i,j,x);
        }
    }
    m.display();
    return 0;
}
