#include<bits/stdc++.h>
using namespace std;
int solve(int n,int length,vector<int> &price,vector<vector<int>>&dp){
    if(length==0) return 0;
    if(n==0){
        return length*price[0];
    }
    if(dp[n][length]!=-1) return dp[n][length];

    int notCut=solve(n-1,length,price,dp);
    int cut=0;
    if(n+1<=length)
    cut=price[n]+solve(n,length-n-1,price,dp);

    return dp[n][length]=max(cut,notCut);
}

int solveTab(int n,int length,vector<int> &price){
    vector<vector<int>>dp(n,vector<int>(length+1,0));

    for(int i=1;i<=length;i++){
        dp[0][i]=i*price[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int l=1;l<=length;l++){
            int notCut=dp[ind-1][l];
            int cut=0;
            if(ind+1<=l)
            cut=price[ind]+dp[ind][l-ind-1];

            dp[ind][l]=max(cut,notCut);
        }
    }
    return dp[n-1][length];
}

int solveTabSO(int n,int length,vector<int> &price){
    vector<int>prev(length+1,0);
    vector<int>curr(length+1,0);

    for(int i=1;i<=length;i++){
        prev[i]=i*price[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int l=1;l<=length;l++){
            int notCut=prev[l];
            int cut=0;
            if(ind+1<=l)
            cut=price[ind]+curr[l-ind-1];

            curr[l]=max(cut,notCut);
        }
        prev=curr;
    }
    return prev[length];
}

int solveTabSO2(int n,int length,vector<int> &price){
    vector<int>curr(length+1,0);

    for(int i=1;i<=length;i++){
        curr[i]=i*price[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int l=1;l<=length;l++){
            int notCut=curr[l];
            int cut=0;
            if(ind+1<=l)
            cut=price[ind]+curr[l-ind-1];

            curr[l]=max(cut,notCut);
        }
    }
    return curr[length];
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // return solve(n-1,n,price,dp);

    // Tabulation
    // return solveTab(n,n,price);

    // Tabulation + SO
    // return solveTabSO(n,n,price);

      // Tabulation + SO2
    return solveTabSO2(n,n,price);
}

int main(){
    //  Unbounded Knapsack  -> https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029?leftPanelTabValue=PROBLEM
    // T.C>>O(2^n) S.C>>O(w)
    // memorization->T.C-> O(n*w) S.C->O(w)+O(n*w)
    // Tabulation->T.C-> O(n*w) S.C->O(n*w)
    // Tabulation+SO ->T.C-> O(n*w) S.C->O(w)

    //  Rod cutting problem -> https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284
    // T.C>>O(2^n) S.C>>O(length)
    // memorization->T.C-> O(n*n) S.C->O(w)+O(n*n)
    // Tabulation->T.C-> O(n*n) S.C->O(n*n)
    // Tabulation+SO ->T.C-> O(n*n) S.C->O(n)
    return 0;
}