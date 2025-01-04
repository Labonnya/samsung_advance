#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin>>tt;

    for(int  tc=0; tc<tt; tc++)
    {
        int n;
        cin>>n;
        n+=2;

        int sourceX,sourceY,desX,desY,cost;

        cin>>sourceX>>sourceY;
        cin>>desX>>desY;

        vector<vector<int>>portal;
        portal.push_back({sourceX,sourceY,sourceX,sourceY,0});
        portal.push_back({desX,desY,desX,desY,0});

        for(int i=1; i<n-1; i++)
        {
            int inX,inY,outX,outY;

            cin>>inX>>inY>>outX>>outY>>cost;

            portal.push_back({inX,inY,outX,outY,cost});
            portal.push_back({outX,outY,inX,inY,cost});
        }

        int totalNodes = portal.size();
        vector<pair<int,int>>adjacencyList[totalNodes];
        vector<bool>visited(totalNodes, false);
        vector<int>distance(totalNodes, INT_MAX);

        for(int i=0; i<totalNodes; i++)
        {
            for(int j=i+1; j<totalNodes; j++)
            {
                int w1 = abs(portal[i][2]-portal[j][0])+abs(portal[i][3]-portal[j][1])+portal[j][4]; //j
                int w2 = abs(portal[j][2]-portal[i][0])+abs(portal[j][3]-portal[i][1])+portal[i][4];
                adjacencyList[i].push_back({j,w1});
                adjacencyList[j].push_back({i,w2});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        q.push({0,0}); //  distance, node

        distance[0]=0;

        while(!q.empty())
        {
            int u = q.top().second;

            q.pop();

            if(visited[u])
            {
                continue;
            }

            visited[u]=true;

            for( auto it : adjacencyList[u])
            {
                int v = it.first;
                int w = it.second;

                if(distance[u]+w< distance[v])
                {
                    distance[v]=distance[u]+w;
                    q.push({distance[v],v});
                }
            }
        }

        cout<<distance[1]<<endl;

    }
}
