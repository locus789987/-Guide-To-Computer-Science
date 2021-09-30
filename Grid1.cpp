#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
char a[1001][1001];
int dpsol(int n,int m)
{
   int dp[1001][1001];
   dp[n][m] = 1;
   for(int i=n-1;i>0;i--)
   {
       
     if(a[i][m]=='.')
     {
         dp[i][m] = dp[i+1][m];
     }
     else
     {
         dp[i][m] =0;
     }
     
   }
   for(int i=m-1;i>0;i--)
   {
       if(a[n][i]=='.')
       {
           dp[n][i] = dp[n][i+1];
       }
       else
       {
           dp[n][i] = 0;
       }
       
   }
   for(int i=n-1;i>0;i--)
   {
       for(int j=m-1;j>0;j--)
       {
           if(a[i][j]=='.')
           { //cout<<i<<" "<<j<<"\n";
              dp[i][j] = (dp[i+1][j]+dp[i][j+1])%mod;
           }
           else
           {
               dp[i][j] = 0;
           }
        //   cout<<dp[i][j]<<" "; 
       }
    //    cout<<"\n";
       
   }
//    for(int i =1;i<=n;i++)
//    {
//        for(int j=1;j<=m;j++)
//        cout<<dp[i][j]<<" ";
//        cout<<"\n";
//    }

   return dp[1][1];
}
int main()
{
   int h,w;
   cin>>h>>w;
   
   for(int i=1;i<=h;i++)
   {
       for(int j=1;j<=w;j++)
       {
           cin>>a[i][j];
        // a[i][j] ='.';
       }
   }
   cout<<dpsol(h,w);
}
