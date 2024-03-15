#include<bits/stdc++.h>
using namespace std;

int solveTabSO(vector<int> &nums){
    int prev1=0;
    int prev2=0;

    for(int i=nums.size()-1;i>=0;i--){
        int include=nums[i];
        int exclude=0;
        if(i+2<nums.size())
            include=nums[i]+prev2;
        if(i+1<nums.size())
            exclude=prev1;

        prev2=prev1;
        prev1=max(include,exclude);
    }  

    return prev1;  
   
} 
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];

    vector<int>temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }
    int ans1=solveTabSO(temp1);
    int ans2=solveTabSO(temp2);
    return max(ans1,ans2);
}

int main(){
    // 1. House Robber II  -> https://www.codingninjas.com/studio/problems/house-robber_839733
    // check in leetcode

    // 2.  Ninja’s Training -> https://www.codingninjas.com/studio/problems/ninja-s-training_3621003
    return 0;
}