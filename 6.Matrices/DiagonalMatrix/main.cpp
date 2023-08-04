#include <iostream>

using namespace std;

class DiagonalMatrix
{
private:
    int *A;
    int n;
public:
    DiagonalMatrix(int x)
    {
        n=x;
        A=new int[n];
    }
    void Set(int i,int j,int x)
    {
        if(i==j)
        {
            A[i-1]=x;//Or (j-1)
        }
    }
    int Get(int i,int j)
    {
        if(i==j)
            return A[i-1];
        return 0;
    }
    void display();
    ~DiagonalMatrix()
    {
        delete []A;
        A=nullptr;
    }
};

void DiagonalMatrix::display()
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
    cout << "Diagonal Matrix" << endl;
    DiagonalMatrix m(3);
    m.Set(1,1,10);
    m.Set(2,2,15);
    m.Set(3,3,20);
    m.display();
    return 0;
}
