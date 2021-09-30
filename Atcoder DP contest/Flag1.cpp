#include <bits/stdc++.h>
using namespace std;
int flag1(int dp[],int n,int arr[],int i){
    if(i==n-1){
        dp[i]=0;
        // return 0;
    }
    else if(i==n-2){

        dp[i]=abs(arr[n-1]-arr[n-2]);

    }
    else
    {
        dp[i]=min(abs(arr[i+1]-arr[i])+flag1(dp,n,arr,i+1),abs(arr[i+2]-arr[i])+flag1(dp,n,arr,i+2));
    }
    return dp[i];
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int dp[n];
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            dp[i] = 0;
        }
        else if (i == n - 2)
        {
            dp[i] = abs(a[n -1] - a[n - 2]);
        }
        else
        {
            dp[i] = min(dp[i+1]+abs(a[i+1]-a[i]),dp[i+2]+abs(a[i+2]-a[i]));

        }
    
    }
    //cout<<flag1(dp,n,a,0);
    cout<<dp[0];
}