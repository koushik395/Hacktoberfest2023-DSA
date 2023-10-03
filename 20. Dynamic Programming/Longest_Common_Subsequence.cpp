#include <bits/stdc++.h>
using namespace std;
string s = "";

//tabulation
int lcs(string text1, string text2,int m,int n)
{
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j] =0;
            else if(text1[i-1] == text2[j-1])
            {
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else
            {
                int a = dp[i-1][j];
                int b = dp[i][j-1];
                dp[i][j] = max(a,b);
            }
        }
    }
    int i = m,j = n;
    while(i > 0 && j > 0)
    {
        if(text1[i-1] == text2[j-1])
        {
            s = text1[i-1] + s;
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return dp[m][n];
}

//space optimization
int lcsSpaceOptimization(string text1, string text2,int m,int n)
{
    vector<int> prev(n+1,0),curr(n+1,0);
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                curr[j] =0;
            else if(text1[i-1] == text2[j-1])
                curr[j] = 1+ prev[j-1];
            else
            {
                int a = prev[j];
                int b = curr[j-1];
                curr[j] = max(a,b);
            }
        }
        prev = curr;
    }
    return prev[n];
}

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    return lcs(text1,text2,m,n);
}

int main()
{
	string text1;
	string text2;
    cin >> text1;
    cin >> text2;

	cout << longestCommonSubsequence(text1,text2)<<endl;
	cout << s << endl;
}