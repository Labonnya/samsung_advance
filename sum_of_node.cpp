#include<iostream>
#include<cstring>
#include<climits>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
    int k;
    cin>>k;

    string s;
    cin>>s;

    int l=-1, n=s.length(), sum=0;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            l++;
        }
        else if(s[i]==')')
        {
            l--;
        }

        else if(l==k)
        {
            string  temp = "";
            while(i<n && s[i]!='(' && s[i]!=')')
            {
                temp +=s[i]++;
            }
            sum += stoi(temp);
            i--;
        }
    }

    cout<<sum<<endl;
}
