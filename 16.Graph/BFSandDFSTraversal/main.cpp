#include <bits/stdc++.h>
using namespace std;

void BFS(int G[][7],int start,int n)
{
    int i=start;
    queue<int> q;
    int visited[n]={0};

    cout<<i<<" ";
    visited[i]=1;
    q.push(i);

    while(!q.empty())
    {
        i=q.front();
        q.pop();
        for(int j=1;j<=n;j++)
        {
            if(G[i][j]==1 && visited[j]!=1)
            {
                cout<<j<<" ";
                visited[j]=1;
                q.push(j);
            }
        }
    }
}

void DFS(int G[][7],int start,int n)
{
    static int visited[7]={0};

    if(visited[start]!=1)
    {
        cout<<start<<" ";
        visited[start]=1;
        for(int j=1;j<n;j++)
        {
            if(G[start][j]==1 && visited[j]!=1)
            {
                DFS(G,j,n);
            }
        }
    }
}
int main()
{
    cout << "BFS and DFS Traversal" << endl;

    int G[7][7]={{0,0,0,0,0,0,0},
                  {0,0,1,1,0,0,0},
                  {0,1,0,0,1,0,0},
                  {0,1,0,0,1,0,0},
                  {0,0,1,1,0,1,1},
                  {0,0,0,0,1,0,0},
                  {0,0,0,0,1,0,0} };

    DFS(G,1,7);
    return 0;
}
