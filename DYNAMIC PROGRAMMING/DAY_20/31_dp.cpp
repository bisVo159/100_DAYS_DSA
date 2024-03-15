#include<bits/stdc++.h>
using namespace std;

int solveMem(int n, vector<int> &heights,vector<int>&dp){
    if(n==0)
    return 0;
    if(dp[n]!=-1) return dp[n];

    int step2=INT_MAX;
    int step1=abs(heights[n]-heights[n-1])+solveMem(n-1,heights,dp);
    if(n>1)
     step2=abs(heights[n]-heights[n-2])+solveMem(n-2,heights,dp);

    return dp[n]=min(step1,step2);
}

int solveTab(int n, vector<int> &heights){
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        int step2=INT_MAX;
        int step1=abs(heights[i]-heights[i-1])+dp[i-1];
        if(i>1)
        step2=abs(heights[i]-heights[i-2])+dp[i-2];

         dp[i]=min(step1,step2);
    }
    return dp[n];
}

int solveTabSO(int n, vector<int> &heights){
    int prev1=0;
    int prev2=0;

    for(int i=1;i<=n;i++){
        int step1=abs(heights[i]-heights[i-1])+prev1;
        int step2=INT_MAX;
        if(i>1)
        step2=abs(heights[i]-heights[i-2])+prev2;

        int curr=min(step1,step2);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n,-1);
    return solveMem(n-1,heights,dp);
}

int main(){
    // climbing stairs
    // frog jump   https://www.codingninjas.com/studio/problems/frog-jump_3621012
    return 0;
}