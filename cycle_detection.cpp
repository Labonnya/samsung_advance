#include<bits/stdc++.h>
using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
int min_cost_of_cycle = INT_MAX;
vector<int> min_cost_cycle;
void detect_cycle(vector<vector<int>> &adj, int nodes);
void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int>&path);
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    vector<vector<int>>adj(nodes+1);

    int u,v;

    for(int i=0; i<edges; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }

    detect_cycle(adj, nodes);

    if(min_cost_cycle.empty())
    {
        cout<<"No cycle found"<<endl;
    }
    else
    {
        for(int i=0; i<min_cost_cycle.size();i++)
        {
            cout<<min_cost_cycle[i]<<" ";
        }
    }
}

void detect_cycle(vector<vector<int>> &adj, int nodes)
{
    vector<int>visited(nodes+1, WHITE), path(nodes+1, -1);

    for(int i=1; i<=nodes;i++)
    {
        if(visited[i]==WHITE)
        {
            dfs(i,adj,visited,path);
        }
    }
}

void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int>&path)
{
    visited[node]=GRAY;

    for(int neighbour : adj[node])
    {
        if(visited[neighbour]==WHITE)
        {
            path[neighbour]=node;
            dfs(neighbour, adj, visited,path);
        }
        else if(visited[neighbour]==GRAY)
        {
            //cycle detected
            vector<int>cycle;
            int parent = node;
            int cost = neighbour;

            cycle.push_back(neighbour);

            while(parent!=neighbour)
            {
                cost =+ cycle.back();
                cycle.push_back(parent);
                parent = path[parent];
            }

            if(min_cost_of_cycle>cost)
            {
                sort(cycle.begin(), cycle.end());
                min_cost_cycle = cycle;
                min_cost_of_cycle = cost;
            }
        }
    }

    visited[node]=WHITE;
}
