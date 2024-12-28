#include<bits/stdc++.h>
using namespace std;

int find_max_score(vector<int> &b, int n);
int calculate_score(vector<int> &b, vector<vector<int>> &dp, int start, int end, int n);

int main()
{
    int n;
    cin >> n;

    vector<int> b;
    b.push_back(1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    b.push_back(1);
    n += 2;

    cout << find_max_score(b, n) << endl;
}

int find_max_score(vector<int> &b, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return calculate_score(b, dp, 1, n - 2, n);
}

int calculate_score(vector<int> &b, vector<vector<int>> &dp, int start, int end, int n)
{
    int score = 0, max_score = INT_MIN;
    if (start > end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    for (int i = start; i <= end; i++)
    {
        if (((start - 1) == 0) && ((end + 1) == (n - 1)))
        {
            score = b[i] + calculate_score(b, dp, start, i - 1, n) + calculate_score(b, dp, i + 1, end, n);
        }
        else
        {
            score = b[start - 1] * b[end + 1] + calculate_score(b, dp, start, i - 1, n) + calculate_score(b, dp, i + 1, end, n);
        }
        max_score = max(score, max_score);
    }
    return dp[start][end] = max_score;
}
