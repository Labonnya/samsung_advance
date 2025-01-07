#include<bits/stdc++.h>

using namespace std;

static int dp[101][11][11][11];

int n,sumF=0;

vector<int>gate(3);
vector<int>people(3);

int find_min_distance(int index, int p0, int p1, int p2);

int main()
{
    cin>>n;

    for(int i=0;i<3; i++)
    {
        cin>>gate[i];
    }
    for(int i=0;i<3; i++)
    {
        cin>>people[i];
        sumF+= people[i];
    }

    memset(dp,-1,sizeof(dp));

    cout<<find_min_distance(1, people[0],people[1],people[2])<<endl;
}

int find_min_distance(int index, int p0, int p1, int p2)
{
    if(p0+p1+p2 == 0)
    {
        return 0;
    }

    if(index>n)
    {
        return INT_MAX;
    }

    int &res = dp[index][p0][p1][p2];

    if(res!=-1)
    {
        return res;
    }

    int best = find_min_distance(index+1, p0,p1,p2);

    if(p0>0)
    {
        int cost = abs(gate[0]-index)+1;
        int rec = find_min_distance(index+1, p0-1, p1,p2);

        if(rec != INT_MAX)
        {
            best = min(best, cost+rec);
        }
    }
    if(p1>0)
    {
        int cost = abs(gate[1]-index)+1;
        int rec = find_min_distance(index+1, p0, p1-1,p2);

        if(rec != INT_MAX)
        {
            best = min(best, cost+rec);
        }
    }
    if(p2>0)
    {
        int cost = abs(gate[2]-index)+1;
        int rec = find_min_distance(index+1, p0, p1,p2-1);

        if(rec != INT_MAX)
        {
            best = min(best, cost+rec);
        }
    }

    res = best;

    return res;
}
