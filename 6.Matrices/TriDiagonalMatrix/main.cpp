#include <iostream>

using namespace std;

class Tridiagonal
{
private:
    int *A;
    int n;
public:
    Tridiagonal(int x)
    {
        n=x;
        A=new int[3*n-2];
    }
    void Set(int i,int j,int x)
    {
        if(i-j==1)
        {
            A[i-2]=x;
        }
        else if(i-j==0)
        {
            A[n+i-2]=x;
        }
        else if(i-j==-1)
        {
            A[2*n+i-2]=x;
        }
    }
    int Get(int i,int j)
    {
        if(i-j==1)
        {
            return A[i-2];
        }
        else if(i-j==0)
        {
            return A[n+i-2];
        }
        else if(i-j==-1)
        {
            return A[2*n+i-2];
        }
        else
        {
            return 0;
        }
    }
    void display();
    ~Tridiagonal()
    {
        delete []A;
        A=nullptr;
    }
};

void Tridiagonal::display()
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
    cout << "Tridiagonal Matrix" << endl;
    cout<<"Enter the Dimension of Array: "<<endl;
    cin>>d;
    Tridiagonal m(d);
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
