#include<iostream>
#include<vector>

using namespace std;

int find_min_distance(vector<vector<int>>&graph);
int tsp(int source, int mask, vector<vector<int>>&graph, vector<vector<int>>&dp);

int main()
{
    int tt, no_of_cities;
    cin>>tt;

    for(int tc=0;tc<tt;tc++)
    {
        cin>>no_of_cities;
        vector<vector<int>>graph(no_of_cities, vector<int>(no_of_cities));
        for(int i=0;i<no_of_cities;i++)
        {
            for(int j=0;j<no_of_cities;j++)
            {
                cin>>graph[i][j];
            }
        }

        cout<<find_min_distance(graph)<<endl;
    }
}

int find_min_distance(vector<vector<int>>&graph)
{
    int n=graph.size();
    vector<vector<int>>dp(1<<n, vector<int>(n,-1));

    return tsp(0,1,graph,dp);
}

int tsp(int source, int mask, vector<vector<int>>&graph, vector<vector<int>>&dp)
{
    int n = graph.size();

    if(dp[mask][source]!=-1)
    {
        return dp[mask][source];
    }

    if(mask==((1<<n)-1))
    {
        return graph[source][0];
    }

    int min_cost = INT_MAX;

    for(int loc=1; loc<n; loc++)
    {
        if(!(mask & (1<<loc)))
        {
            min_cost = min(min_cost, graph[source][loc]+tsp(loc, mask | 1<<loc, graph, dp));
        }
    }

    return dp[mask][source]=min_cost;
}
