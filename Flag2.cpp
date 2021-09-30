#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9 + 5;
using namespace std;


int main()
{
    ll n;
    cin >> n;
    ll k;
    cin>>k;

    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
   ll dp[n];
    for(int i=0;i<n;i++){
        dp[i]=MOD;    
        }
    dp[0]=0;
    
    for (int i = 1; i <n; i++)
    {
           for(int j=1;j<=k&&j<=i;j++)
            dp[i] = min(dp[i],dp[i-j]+abs(a[i-j]-a[i]));
    
    }
    //cout<<flag1(dp,n,a,0);
    cout<<dp[n-1];
}