#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int goal = 3;
const int step = 1;
const int empty = 0;

bool valid_move(int x, int y, vector<vector<int>>&grid);
int find_least_difficulty(int x, int y, vector<vector<int>>&grid);
void dfs(int x, int y, vector<vector<int>>&grid, vector<vector<int>>&dp);

int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> grid(r, vector<int>(c));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>grid[i][j];
        }
    }

    cout<<find_least_difficulty(r,c,grid)<<endl;
}


bool valid_move(int x, int y, vector<vector<int>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();

    if(y>=0 && y<m && grid[x][y]!=0)
    {
        return true;
    }
    return false;
}

int find_least_difficulty(int x, int y, vector<vector<int>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>dp(n, vector<int>(m,n-1));

    dp[n-1][0]=0;

    dfs(n-1,0,grid,dp);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==goal)
            {
                return dp[i][j];
            }
        }
    }

    return 0;
}

void dfs(int x, int y, vector<vector<int>>&grid, vector<vector<int>>&dp)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>>q;

    q.push({x,y});

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        //left-right
        if(valid_move(x,y-1,grid)&& dp[x][y-1]>dp[x][y])
        {
            {
                dp[x][y-1]=dp[x][y];
                q.push({x,y-1});
            }
        }
        if(valid_move(x,y+1,grid)&& dp[x][y+1]>dp[x][y])
        {
            {
                dp[x][y+1]=dp[x][y];
                q.push({x,y+1});
            }
        }

        //up down
        int difficulty =0;
        for(int r=0; r<n;r++)
        {
            if(grid[r][y]==step || grid[r][y]==goal)
            {
                difficulty = max(abs(r-x),dp[x][y]);
                if(difficulty<dp[r][y])
                {
                    dp[r][y]=difficulty;
                    q.push({r,y});
                }
            }
        }
    }
}
