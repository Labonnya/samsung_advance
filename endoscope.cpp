#include<iostream>
#include<vector>

using namespace std;

int direction[][4]= {
    {0,0,0,0}, //lrtd
    {-1,1,-1,1},
    {0,0,-1,1},
    {-1,1,0,0},
    {0,1,-1,0},
    {0,1,0,1},
    {-1,0,0,1},
    {-1,0,-1,0}
};
int calculate_exploration(int w,int h,int r,int c,int s, const vector<vector<int>>&grid);
void dfs(int r, int c, int s, int &explored_pipe_count,  vector<vector<int>>&visited,  vector<vector<int>>&dfsvisited,const vector<vector<int>>&grid);

int main()
{
    int tt,w,h,r,c,s;

    cin>>tt;

    for(int i=0;i<tt;i++)
    {
        cin>>w>>h>>r>>c>>s;
        vector<vector<int>>grid(w,vector<int>(h));
        for(int m=0;m<w;m++)
        {
            for(int j=0;j<h;j++)
            {
                cin>>grid[m][j];
            }
        }
        cout<<calculate_exploration(w,h,r,c,s,grid)<<endl;
    }

}


int calculate_exploration(int w,int h,int r,int c,int s, const vector<vector<int>>&grid)
{
  vector<vector<int>> visited(w, vector<int>(h,0));
  vector<vector<int>> dfsvisited(w, vector<int>(h,0));

  int explored_pipe_count=0;

  dfs(r,c,s,explored_pipe_count,visited,dfsvisited,grid);
  return explored_pipe_count;

}

void dfs(int r, int c, int s, int &explored_pipe_count,  vector<vector<int>>&visited,  vector<vector<int>>&dfsvisited, const vector<vector<int>>&grid)
{
  int n = grid.size();
  int m = grid[0].size();

  if(r<0 || r>n || c<0 || c>m)
  {
      return;
  }
  if(s<=0)
  {
      return ;
  }

  if(dfsvisited[r][c])
  {
      return ;

  }

  if(!visited[r][c])
  {
      explored_pipe_count++;
      visited[r][c]=1;
  }
  dfsvisited[r][c]=1;

  int left = direction[grid[r][c]][0];
  int right = direction[grid[r][c]][1];
  int up = direction[grid[r][c]][2];
  int down = direction[grid[r][c]][3];

  if(c+left>=0 && c+left<m && direction[grid[r][c+left]][1]==1)
  {
    dfs(r,c+left,s-1,explored_pipe_count, visited, dfsvisited, grid);
  }
  if(c+right>=0 && c+right<m && direction[grid[r][c+right]][0]==-1)
  {
    dfs(r,c+right,s-1,explored_pipe_count, visited, dfsvisited, grid);
  }
  if(r+up>=0 && r+up<n && direction[grid[r+up][c]][3]==1)
  {
    dfs(r+up,c,s-1,explored_pipe_count, visited, dfsvisited, grid);
  }
  if(r+down>=0 && r+down<n && direction[grid[r+down][c]][2]==-1)
  {
    dfs(r+down,c,s-1,explored_pipe_count, visited, dfsvisited, grid);
  }

  dfsvisited[r][c]=0;
}



