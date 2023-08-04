#include <iostream>

using namespace std;

class Symmetric
{
private:
    int *A;
    int n;
public:
    Symmetric(int x)
    {
        n=x;
        A=new int[n*(n+1)/2];
    }
    void Set(int i,int j,int x)
    {
        if(i>=j)
        {
            A[(i*(i-1)/2)+(j-1)]=x;
        }
    }
    int Get(int i,int j)
    {
        if(i>=j)
            return A[(i*(i-1)/2)+(j-1)];
        else
        {
            return A[(j*(j-1)/2)+(i-1)];
        }
    }
    void display();
    ~Symmetric()
    {
        delete []A;
        A=nullptr;
    }
};

void Symmetric::display()
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
    cout << "Symmetric Matrix using Lower Triangular Row Major Mapping" << endl;
    cout<<"Enter the Dimension of Array: "<<endl;
    cin>>d;
    Symmetric m(d);
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
