#include<iostream>
#include<vector>

using namespace std;

struct point
{
    int x,y;
};

struct wormhole
{
    point source, destination;
    int cost;
};

int find_min_cost(point source, point destination, vector<wormhole>&whs);
int manhattan_distance(point A, point B);
int recursively_calculate(point curr_source, point final_destination,vector<wormhole>&whs, vector<int>&visited );

int main()
{
    int tt, no_of_wormholes;
    cin>>tt;

    point source, destination;

    for(int tc = 0; tc<tt ; tc++)
    {
        cin>> no_of_wormholes>>source.x>>source.y>>destination.x>>destination.y;

        vector<wormhole> whs(no_of_wormholes);

        for( int i=0; i<no_of_wormholes; i++)
        {
            cin>>whs[i].source.x>>whs[i].source.y;
            cin>>whs[i].destination.x>>whs[i].destination.y;
            cin>>whs[i].cost;
        }

        cout<<find_min_cost(source, destination, whs)<<endl;
    }
}

int find_min_cost(point source, point destination, vector<wormhole>&whs)
{
    vector<int>visited(whs.size(),0);

    return recursively_calculate(source, destination, whs, visited);
}

int manhattan_distance(point A, point B)
{
    return abs(A.x-B.x)+abs(A.y-B.y);
}

int recursively_calculate(point curr_source, point final_destination,vector<wormhole>&whs, vector<int>&visited )
{
    int min_cost = INT_MAX;

    min_cost = min(min_cost, manhattan_distance(curr_source, final_destination));

    for(int i=0; i<whs.size();i++)
    {
        if(visited[i])
        {
            continue;
        }
        visited[i]=1;

        min_cost = min(min_cost, manhattan_distance(curr_source,whs[i].source)+whs[i].cost+recursively_calculate(whs[i].destination, final_destination, whs, visited));

        min_cost = min(min_cost, manhattan_distance(curr_source,whs[i].destination)+whs[i].cost+recursively_calculate(whs[i].source, final_destination, whs, visited));

        visited[i]=0;
    }
    return min_cost;
}
