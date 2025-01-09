#include<iostream>

using namespace std;

int n;
int arr[100][100]={0};
bool isBipartite(int i, int color[]);

int main()
{
    cin>>n;
    int color[n];

    for(int i=0;i<n;i++)
    {
        color[i]=-1;
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            color[i]=0;
            if(!isBipartite(i,color))
            {
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(color[i]==0)
        {
            cout<<i<<" ";
        }
    }
}


bool isBipartite(int i, int color[])
{
    bool flag = true;

    for(int j=0;j<n;j++)
    {
        if(arr[i][j]==1)
        {
            if(color[j]==-1)
            {
                color[j]=1-color[i];
                flag = flag & isBipartite(j,color);
            }
            else if(color[i]==color[j])
            {
                return false;
            }
        }
    }

    return flag;
}
