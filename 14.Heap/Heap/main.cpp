#include <iostream>

using namespace std;

class MaxHeap
{
public:
    int csz;
    int sz;
    int *A;

    MaxHeap();
    MaxHeap(int s)
    {
        csz=1;
        sz=s;
        A=new int[s+1];
    }

    void Insert(int n)
    {
        int temp=A[n];
        int i=n;
        while(i>1 && temp>A[i/2])
        {
            A[i]=A[i/2];
            i=i/2;
        }
        A[i]=temp;
        //cout<<"Inserted "<<temp<<" at "<<i<<"th position"<<endl;
    }
    void createHeap()
    {
        cout<<"Enter all the elements: "<<endl;
        for(int i=1;i<=sz;i++)
        {
            cin>>A[i];
        }

        for(int i=2;i<=sz;i++)
        {
            Insert(i);
            csz++;
        }
    }

    void Delete()
    {
        int x,i,j;
        x=A[1];
        A[1]=A[csz];
        i=1,j=2*i;

        while(j<csz-1)
        {
            if(A[j+1]>A[j])
                j=j+1;
            if(A[i]<A[j])
            {
                swap(A[i],A[j]);
                i=j;
                j=2*j;
            }
            else
            {
                break;
            }
        }
        A[csz]=x;
        csz--;
        //display();
        //displaySorted();
    }

    void HeapSort()
    {
        int x=sz;
        for(int i=0;i<x;i++)
        {
            Delete();
        }
    }

    void display()
    {
        for(int i=1;i<=csz;i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }

    void displaySorted()
    {
        for(int i=1;i<=sz;i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
};
int main()
{
    int x;
    cout << "Heap using Array" << endl;
    cout<<"Enter the size of heap"<<endl;
    cin>>x;
    MaxHeap h(x);
    h.createHeap();
    h.display();
    h.HeapSort();
    h.displaySorted();
    return 0;
}
