#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int store[10000][10];
int visited[11]={0};
int parent[11]={-1};
int incurrentdfs[11]={0};
int edvisited[11][11]={0};
int adj[11][11];
int t=0;

void dfs(int x,int n);

int main()
{
    int n,m;
    cin>>n>>m;

    for(int j=0;j<m;j++)
    {
        int a,b;
        cin>>a>>b;
        adj[a][b]=1;
    }

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
           {
               dfs(i,n);
           }
    }

    int sum=INT_MAX;
    int index=-1;
    for(int i=0;i<t;i++)
    {
        int temp=0;
        for(int j=1;j<n;j++)
        {
            if(store[i][j])
            {
                temp = temp+j;
            }
            if(temp<sum)
            {
                sum=temp;
                index=i;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(store[index][i])
        {
            cout<<i<<" ";
            return 0;
        }
    }
}

void dfs(int x,int n)
{
    visited[x]=1;
    incurrentdfs[x]=1;

    for(int j=1;j<=n;j++)
    {
        if(adj[x][j] && !visited[j])
        {
            edvisited[x][j]=1;
            parent[j]=x;
            dfs(j,n);
        }
        else if(adj[x][j] && visited[j] && incurrentdfs[j])
        {
            edvisited[x][j]=1;
            int c = x;
            while(c!=j)
            {
                store[t][c]=1;
                c=parent[c];
            }
            store[t][j]=1;
            t++;
        }
        else if(adj[x][j] && visited[j] && !incurrentdfs[j] && !edvisited[x][j])
        {
            edvisited[x][j]=1;
            parent[j]=x;
            dfs(j,n);
        }
    }
    incurrentdfs[x]=0;
}
