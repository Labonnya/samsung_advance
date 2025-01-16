#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<unordered_map>
#include<cstring>

using namespace std;

bool canReachGoal(vector<vector<int>>&grid, int n, int m, int d)
{
    int sr = n-1;
    int sc = 0;

    vector<vector<bool>>visited(n,vector<bool>(n,false));

    visited[sr][sc]=true;

    queue<pair<int,int>>q;
    q.push({sr,sc});

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();

        int r = it.first;
        int c = it.second;

        if(grid[r][c]==3)
        {
            return true;
        }

        if(c-1>=0)
        {
            int nr = r;
            int nc = c-1;
            if(!visited[nr][nc] && (grid[nr][nc]==1 || grid[nr][nc]==3))
            {
                visited[nr][nc]=true;
                q.push({nr,nc});
            }
        }

        if(c+1<m)
        {
            int nr = r;
            int nc = c+1;
            if(!visited[nr][nc] && (grid[nr][nc]==1 || grid[nr][nc]==3))
            {
                visited[nr][nc]=true;
                q.push({nr,nc});
            }
        }

        for(int k=1;k<=d;k++)
        {
            int nrUp = r-k;
            int nc = c;

            if(nrUp>=0)
            {
                if(!visited[nrUp][nc] && (grid[nrUp][nc]==1 || grid[nrUp][nc]==3))
                {
                    visited[nrUp][nc]=true;
                    q.push({nrUp,nc});
                }
            }

            int nrDown = r+k;
            if(nrDown<n)
            {
                if(!visited[nrDown][nc] && (grid[nrDown][nc]==1 || grid[nrDown][nc]==3))
                {
                    visited[nrDown][nc]=true;
                    q.push({nrDown,nc});
                }
            }
        }
    }

    return false;
}

int main()
{
  int n,m;
  cin>>n>>m;

  vector<vector<int>>grid(n,vector<int>(m,0));

  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          cin>>grid[i][j];
      }
  }
  int high = n-1;
  int low = 0;

  int ans = -1;

  while(low<=high)
  {
      int mid = low+ (high-low)/2;

      if(canReachGoal(grid,n,m,mid))
      {
          ans = mid;
          high = mid-1; //may change
      }
      else
      {
          low = mid+1;
      }
  }

  cout<<ans<<endl;
}



