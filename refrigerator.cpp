#include<bits/stdc++.h>
using namespace std;




int find_minimum_travel(const vector<pair<int,int>>& coordinates,int n);
int tsp(int source, int mask, const vector<vector<int>>& graph, vector<vector<int>>& dp);
int manhattan_distance(pair<int,int>A,pair<int,int>B);

int main()
{
    int test_case=10;

    for(int tc=1;tc<=test_case;tc++)
    {
        int n,x,y;
        cin>>n;
        vector<pair<int,int>>coordinates(n+2);
        n+=2;

        cin>>x>>y;
        coordinates[0]={x,y};
        cin>>x>>y;
        coordinates[n-1]={x,y};
        for(int i=1;i<n-1;i++){
            cin>>x>>y;
            coordinates[i]={x,y};
        }

        cout<<"#"<<tc<<" "<<find_minimum_travel(coordinates,n)<<endl;
    }

}

int manhattan_distance(pair<int,int>A,pair<int,int>B)
{
    return abs(A.first-B.first)+abs(A.second-B.second);
}

int find_minimum_travel(const vector<pair<int,int>>& coordinates,int n)
{
    vector<vector<int>> graph(n, vector<int>(n,0));

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int distance = manhattan_distance(coordinates[i],coordinates[j]);
            graph[i][j]=distance;
            graph[j][i]=distance;
        }
    }
    vector<vector<int>>dp(1<<n,vector<int>(n,-1));

    int temp = tsp(0,1,graph,dp); //current location at start & first node is visited
    return temp;
}

int tsp(int source, int mask, const vector<vector<int>>& graph, vector<vector<int>>& dp)
{
    int n=graph.size();
    if(dp[mask][source]!=-1)
    {
        return dp[mask][source];
    }
    if(mask == ((1<<n)-1))
    {
        return graph[source][n-1];
    }

    int min_cost = INT_MAX;

    for(int loc=1;loc<n;loc++)
    {
        if(!(mask & (1<<loc)))
        {
            int new_mask = mask | (1<<loc);
            min_cost = min(min_cost, graph[source][loc]+tsp(loc,new_mask,graph,dp));
        }
    }

    return dp[mask][source]=min_cost;
}


