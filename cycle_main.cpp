#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void printCycle(vector<int>&parent,int start,int end)
{
    int current = start;
    vector<int>cycle;
    while(current!=end)
    {
        cycle.push_back(current);
        current = parent[current];
    }
    cycle.push_back(end);

    sort(cycle.begin(),cycle.end());

    for(int node:cycle)
    {
        cout<<node<<" ";
    }

    cout<<endl;
}

bool dfs(int node, vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&instack,vector<int>&parent)
{
    visited[node]=true;
    instack[node]=true;

    for(int neighbor : adj[node])
    {
        parent[neighbor]=node;
        if(!visited[neighbor])
        {
            if(dfs(neighbor,adj,visited,instack,parent))
            {
                return true;
            }
        }
        else if(instack[neighbor])
        {
            printCycle(parent,node,neighbor);
            return true;
        }
    }

    instack[node]=false;
    return false;
}

int main()
{

    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<bool>visited(n+1,false);
    vector<bool>instack(n+1,false);
    vector<int>parent(n+1,-1);

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,adj,visited,instack,parent))
            {
                break;
            }
        }
    }

    cout<<0<<endl;
}
