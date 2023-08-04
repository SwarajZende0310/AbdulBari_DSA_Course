#include <iostream>

using namespace std;

class Sort
{
public:
    void BubbleSort(int A[],int n)
    {
        for(int i=0;i<n-1;i++)
        {
            int swaps=0;
            for(int j=0;j<n-i-1;j++)
            {
                if(A[j]>A[j+1])
                {
                    swap(A[j],A[j+1]);
                    swaps++;
                }
            }
            if(swaps==0)
                break;
        }
    }

    void InsertionSort(int A[],int n)
    {
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            int x=A[i];
            while(j>-1 && A[j]>x)
            {
                A[j+1]=A[j];
                j--;
            }
            A[j+1]=x;
        }
    }

    void SelectionSort(int A[],int n)
    {
        int i,j,k;
        for(i=0;i<n-1;i++)
        {
            for(j=k=i;j<n;j++)
            {
                if(A[j]<A[k])
                {
                    k=j;
                }
            }
            swap(A[i],A[k]);
        }
    }

    int Partition(int A[],int l,int h)
    {
        int pivot=A[l];
        int i=l,j=h;

        do
        {
            do{i++;}while(A[i]<=pivot);
            do{j--;}while(A[j]>pivot);

            if(i<j)
            {
                swap(A[i],A[j]);
            }
        }while(i<j);

        swap(A[l],A[j]);

        return j;
    }

    void QuickSort(int A[],int l,int h)
    {
        int j;
        if(l<h)
        {
            j=Partition(A,l,h);
            QuickSort(A,l,j);
            QuickSort(A,j+1,h);
        }
    }

    void Merge(int A[],int l,int mid,int h)
    {
        int i=l;
        int j=mid+1;
        int k=l;
        int B[h+1];

        while(i<=mid && j<=h)
        {
            if(A[i]<A[j])
                B[k++]=A[i++];
            else
                B[k++]=A[j++];
        }

        for(;i<=mid;i++)
            B[k++]=A[i];
        for(;j<=h;j++)
            B[k++]=A[j];

        //Copying Merged elements
        for(int m=l;m<=h;m++)
            {
                A[m]=B[m];
            }
    }

    void IMergeSort(int A[],int n)
    {
        int p,i,l,mid,h;

        for(p=2;p<=n;p*=2)//For log n times
        {
            for(i=0;i+p-1<n;i+=p)//Merging each list
            {
                l=i;
                h=i+p-1;
                mid=(l+h)/2;
                Merge(A,l,mid,h);
            }
        }
        if(p/2<n)
        {
            Merge(A,0,(p/2)-1,n);
        }
    }

    void RMergeSort(int A[],int l,int h)
    {
        if(l<h)
        {
            int mid=(l+h)/2;
            RMergeSort(A,l,mid);
            RMergeSort(A,mid+1,h);
            Merge(A,l,mid,h);
        }
    }

    int findMax(int A[],int n)
    {
        int m=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]>m)
                m=A[i];
        }
        return m;
    }

    void CountSort(int A[],int n)
    {
        int i,j,m,*c;
        m=findMax(A,n);
        c=new int[m+1];

        for(i=0;i<m+1;i++)
        {
            c[i]=0;
        }
        for(i=0;i<n;i++)
        {
            c[A[i]]++;
        }

        i=0;
        j=0;
        while(i<m+1)
        {
            if(c[i]>0)
            {
                A[j++]=i;
                c[i]--;
            }
            else
            {
                i++;
            }
        }
    }

    void ShellSort(int A[],int n)
    {
        int gap,i,j,temp;

        for(gap=n/2;gap>=1;gap/=2)
        {
            for(i=gap;i<n;i++)
            {
                temp=A[i];
                j=i-gap;
                while(j>=0 && A[j]>temp)
                {
                    A[j+gap]=A[j];
                    j=j-gap;
                }
                A[j+gap]=temp;
            }
        }
    }
};
int main()
{
    cout << "Sorting Techniques" << endl;
    int A[]={5,3,4,9,1,2,7};
    Sort s1;
    s1.ShellSort(A,7);

    cout<<"Sorted Array: "<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
