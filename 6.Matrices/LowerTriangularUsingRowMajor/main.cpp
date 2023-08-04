#include <iostream>

using namespace std;

class LowTriangular
{
private:
    int *A;
    int n;
public:
    LowTriangular(int x)
    {
        n=x;
        A=new int[n*(n+1)/2];
    }
    void Set(int i,int j,int x)
    {
        if(i>=j)
        {
            A[(i*(i-1)/2)+(j-1)]=x;//Or (j-1)
        }
    }
    int Get(int i,int j)
    {
        if(i>=j)
            return A[(i*(i-1)/2)+(j-1)];
        return 0;
    }
    void display();
    ~LowTriangular()
    {
        delete []A;
        A=nullptr;
    }
};

void LowTriangular::display()
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
    cout << "Lower Triangular Matrix using Row Major" << endl;
    cout<<"Enter the Dimension of Array: "<<endl;
    cin>>d;
    LowTriangular m(d);
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
