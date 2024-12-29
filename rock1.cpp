#include<bits/stdc++.h>

using namespace std;

bool dfs(int n, int m, int r, int c, vector<vector<int>>&grid, vector<vector<int>>&visited, vector<vector<int>>&dp);

int main()
{
    int n,m,x,y;

    cin>>n>>m;

    vector<vector<int>>grid(n, vector<int>(m,0));
    vector<vector<int>>visited(n, vector<int>(m,0));
    vector<vector<int>>dp(n, vector<int>(m,-1));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]==3)
            {
                x=i;
                y=j;
            }
        }
    }
    dp[n-1][0]=0;
    dfs(n,m,x,y,grid,visited,dp);
    cout<<dp[x][y]<<endl;
}

bool dfs(int n, int m, int r, int c, vector<vector<int>>&grid, vector<vector<int>>&visited, vector<vector<int>>&dp)
{
    if(r==(n-1) && c==0)
    {
        return true;
    }

    if(dp[r][c]!=-1)
    {
        return true;
    }

    int temp = INT_MAX;

    visited[r][c]=1;

    //left

    for(int i = c-1; i>=0; i--)
    {
        if(grid[r][i]==0)
        {
            break;
        }

        if(visited[r][i]==0 && dfs(n,m,r,i,grid,visited,dp))
        {
            temp = min(temp, dp[r][i]);
        }
    }

    //right
    for(int i=c+1; i<m; i++)
    {
        if(grid[r][i]==0)
        {
            break;
        }
        if(visited[r][i]==0 && dfs(n,m,r,i,grid,visited,dp))
        {
            temp = min(temp, dp[r][i]);
        }
    }

    //upward

    for(int i=r-1; i>=0; i--)
    {
        if(grid[i][c]==0)
        {
            continue;
        }

        if(visited[i][c]==0 && dfs(n,m,i,c,grid,visited,dp))
        {
            temp = min(temp, max(dp[i][c], abs(r-i)));
        }
        else if(dp[i][c]!=INT_MAX && dp[i][c]!=-1)
        {
            temp = min(temp, max(dp[i][c], abs(r-i)));
        }
    }

    //down

    for(int i= r+1; i<n; i++)
    {
        if(grid[i][c]==0)
        {
            continue;
        }

        if(visited[i][c]==0 && dfs(n,m,i,c,grid,visited,dp))
        {
            temp = min(temp, max(dp[i][c], abs(r-i)));
        }
        else if(dp[i][c]!=INT_MAX && dp[i][c]!=-1)
        {
            temp = min(temp, max(dp[i][c], abs(r-i)));
        }
    }

    dp[r][c]=temp;
    return temp!=INT_MAX;
}
