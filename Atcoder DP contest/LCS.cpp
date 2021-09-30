#include<bits/stdc++.h>
using namespace std;
void dpsol(string const& s,string const& t)
{
    int n = s.length();
    int m = t.length();
    int dp[n+1][m+1];

    for(int i=0;i<n+1;i++)
    {
        dp[i][0] = 0;
    }
    for(int i=0;i<m+1;i++)
    {
        dp[0][i] = 0;
    }

    //filling the dp

    for(int i =1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<"\n";
    }

    //after filling the dp now retrieval

    int i =n;
    int j= m;
     stack<char> a;
    while(i>0&&j>0)
    {
        if(dp[i][j]==dp[i-1][j])
        {
            i--;
        }
        else if(dp[i][j]==dp[i][j-1])
        {
            j--;
        }
        else
        {
            a.push(s[i-1]);
            
            i--;
            j--;
        }
        
    }
    // cout<<a.size()<<"\n";
    while(a.size()>0)
    {
        cout<<a.top();
        a.pop();
        // cout<<a.size();
    }
    
}
int main()
{
    string s,t;
    cin>>s>>t;
   dpsol(s,t);
   

}