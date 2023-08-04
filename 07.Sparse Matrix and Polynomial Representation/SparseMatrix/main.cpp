#include <iostream>

using namespace std;

class element
{
public:
    int i;
    int j;
    int x;
};

class Sparse:public element
{
private:
    int m;
    int n;
    int num;
    element*e;
public:
    Sparse(int m,int n,int num)
    {
        this->m=m;
        this->n=n;
        this->num=num;
        e=new element[this->num];
    }
    ~Sparse()
    {
        delete []e;
    }
    void read()
    {
        cout<<"Enter all Non Zero Elements"<<endl;
        for(int i=0;i<num;i++)
        {
            cout<<"Enter Row,Column and Element:";
            cin>>e[i].i>>e[i].j>>e[i].x;
        }
    }
    void display()
    {
        int k=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==e[k].i && j==e[k].j)
                {
                    cout<<e[k++].x<<" ";
                }
                else
                {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }
    friend istream& operator>>(istream &is,Sparse &s);
    friend ostream& operator<<(ostream &os,Sparse &s);
    Sparse* operator+(Sparse &s);
};

istream& operator>>(istream &is,Sparse &s)
{
    cout<<"Enter all Non Zero Elements"<<endl;
        for(int i=0;i<s.num;i++)
        {
            cout<<"Enter Row,Column and Element:";
            cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
        }
        return is;
}

ostream& operator<<(ostream &os,Sparse &s)
{
    int k=0;
        for(int i=0;i<s.m;i++)
        {
            for(int j=0;j<s.n;j++)
            {
                if(i==s.e[k].i && j==s.e[k].j)
                {
                    cout<<s.e[k++].x<<" ";
                }
                else
                {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
        return os;
}

Sparse* Sparse :: operator+(Sparse &s)
{
    int i,j,k;
    i=j=k=0;
    Sparse *sum=new Sparse(m,n,num+s.num);
    if(m!=s.m || n!=s.n)
    {
        //return nullptr;
    }
    while(i<num && j<s.num)
    {
        if(e[i].i<s.e[j].i)
        {
            sum->e[k++]=e[i++];
        }
        else if(e[i].i>s.e[j].i)
        {
            sum->e[k++]=s.e[j++];
        }
        else
        {
            if(e[i].j<s.e[j].j)
            {
                sum->e[k++]=e[i++];
            }
            else if(e[i].j>s.e[j].j)
            {
                sum->e[k++]=s.e[j++];
            }
            else
            {
                sum->e[k]=e[i++];
                sum->e[k++].x += s.e[j++].x;
            }
        }
    }
    //Copying remaining elements
    for(;i<num;i++)
    {
        sum->e[k++]=e[i];
    }
    for(;j<s.num;j++)
    {
        sum->e[k++]=s.e[j];
    }
    sum->num=k;
    return sum;
}
int main()
{
    cout << "Sparse matrix" << endl;
    Sparse s1(5,5,5);
    Sparse s2(5,5,5);
    cin>>s1; //s1.read();
    cin>>s2;
    //cout<<s1;//s1.display();

    Sparse* sum=s1+s2;
    cout<<"First Matrix:"<<endl<<s1;
    cout<<"Second Matrix:"<<endl<<s2;
    cout<<"Sum Matrix:"<<endl<<*sum;
    return 0;
}
