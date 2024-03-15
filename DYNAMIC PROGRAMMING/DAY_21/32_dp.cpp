#include<bits/stdc++.h>
using namespace std;


// T.C -> O(n)*k
// S.C -> O(n)+O(n)
int solveMem(int n,int k, vector<int> &heights,vector<int>&dp){
    if(n==0)
    return 0;
    if(dp[n]!=-1) return dp[n];

   int cost=INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i>=0)
            cost=min(cost,abs(heights[n]-heights[n-i])+solveMem(n-i,k,heights,dp));
    }

    return dp[n]=cost;
}

int solveTab(int n,int k, vector<int> &heights){
    vector<int>dp(n+1,0);

    for(int i=1;i<=n;i++){
        int cost=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0)
                cost=min(cost,abs(heights[i]-heights[i-j])+dp[i-j]);
        }

        dp[i]=cost;
    }
  return dp[n];
}

int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
      // Memorization -> O(n)*k    S.C-> O(n)+O(n)
    // vector<int>dp(n,-1);
    // return solveMem(n-1,k,height,dp);

    // Tabulation -> O(n)*k    S.C-> O(n)
    return solveTab(n-1,k,height);
}

int main(){
    // Frog jump with k distance   ->https://www.codingninjas.com/studio/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
    return 0;
}