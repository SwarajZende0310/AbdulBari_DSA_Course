#include <iostream>

using namespace std;

class Toeplitz
{
private:
    int *A;
    int n;
public:
    Toeplitz(int x)
    {
        n=x;
        A=new int[3*n-2];
    }
    void Set(int i,int j,int x)
    {
        if(i<=j)
        {
            A[j-i]=x;
        }
        else
        {
            A[n+i-j-1]=x;
        }
    }
    int Get(int i,int j)
    {
        if(i<=j)
        {
            return A[j-i];
        }
        else
        {
            return A[n+i-j-1];
        }
    }
    void display();
    ~Toeplitz()
    {
        delete []A;
        A=nullptr;
    }
};

void Toeplitz::display()
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
    cout << "Toeplitz Matrix" << endl;
    cout<<"Enter the Dimension of Array: "<<endl;
    cin>>d;
    Toeplitz m(d);
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
