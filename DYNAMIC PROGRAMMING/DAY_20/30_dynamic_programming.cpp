#include<bits/stdc++.h>
using namespace std;

int fibonacciSeries(int n,vector<int>& dp){
    if(n<=1)
    return n;
    if(dp[n]!=-1)  return dp[n];

    return dp[n]=fibonacciSeries(n-1,dp)+fibonacciSeries(n-2,dp);
}

int tabulation(int n){
    vector<int>dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    // int dp[n+1];
    // memset(dp,-1,sizeof dp);
    vector<int>dp(n+1,-1);

    cout<<fibonacciSeries(n,dp)<<endl;
    // T.C  -> O(n)     S.C -> O(n)+O(n)

    cout<<tabulation(n)<<endl;
        // T.C  -> O(n)     S.C ->O(n)

     // spaceoptimization
    int prev2=0,prev1=1;

    for(int i=2;i<=n;i++){
          int curr=prev2+prev1;
          prev2=prev1;
         prev1=curr;
    }
    cout<<prev1<<endl;
    // T.C  -> O(n)     S.C ->O(1)
    return 0;
}