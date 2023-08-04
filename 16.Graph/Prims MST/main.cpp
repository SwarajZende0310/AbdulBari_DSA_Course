#include <iostream>

using namespace std;

#define I 65536

int cost[8][8]={ {I,I,I,I,I,I,I,I},
                 {I,I,25,I,I,I,5,I},
                 {I,25,I,12,I,I,I,10},
                 {I,I,12,I,8,I,I,I},
                 {I,I,I,8,I,16,I,14},
                 {I,I,I,I,16,I,20,18},
                 {I,I,I,I,I,20,I,I},
                 {I,I,10,I,14,18,I,I}};

int near[8]={I,I,I,I,I,I,I,I};
int t[2][6];

int main()
{
    cout << "Prims Minimum cost Spanning Tree" << endl;
    int i,j,k,u,v,n=7,mini=I;

    //Finding minimum cost edge while searching only in Upper Triangular Array
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(cost[i][j]<mini)
            {
                mini=cost[i][j];
                u=i;
                v=j;
            }
        }
    }

    //Updating minimum cost edge in t Array i.e.Solution
    t[0][0]=u;
    t[1][0]=v;
    //Updating near array that u and v already updated
    near[u]=0;
    near[v]=0;

    //Updating the near matrix
    for(i=1;i<=n;i++)
    {
        if(near[i]!=0)
        {
           if(cost[i][u]<cost[i][v])
           {
             near[i]=u;
           }
           else
           {
             near[i]=v;
           }
        }
    }

    //MAIN ALGORITHM WITH REPEATING STEPS
    for(i=1;i<n-1;i++)
    {
        mini=I;
        //Finding minimum cost edge in adjacent vertex
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][near[j]]<mini)
            {
                mini=cost[j][near[j]];
                k=j;
            }
        }

        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;    //Updating that this edge already used

        //Updating near Array as new Edge added
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][k]<cost[j][near[j]])
            {
                near[j]=k;
            }
        }
    }

    //Printing Solution

    for(i=0;i<6;i++)
    {
       cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    }
    return 0;
}
