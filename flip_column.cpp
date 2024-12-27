#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k, ans=INT_MIN;

    cin>>n>>m>>k;

    unordered_map<string,int>freq;

    for(int i=0; i<n;i++)
    {
        int zeros = 0;

        string temp = "";
        for (int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            if(x==0)
            {
                zeros++;
            }
            temp += '0'+x;
        }

        if(zeros<=k && (k-zeros)%2==0)
        {
            freq[temp]++;
        }
    }

    for(auto it: freq)
    {
        if(it.second>ans)
        {
            ans=it.second;
        }
    }

    cout<<ans<<endl;

    return 0;
}

