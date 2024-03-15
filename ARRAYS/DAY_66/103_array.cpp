#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        int start,ansStart,ansEnd;

        for(int i=0;i<nums.size();i++){
            if(sum==0) start=i;

            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
                ansStart=start,ansEnd=i;
            }
            sum=max(0,sum);
        }

        return maxi;
    }

int main(){
    // 1. Two Sum

    // Dutch National flag algorithm
    // 75. Sort Colors

    // 169. Majority Element

    // 53. Maximum Subarray
    // to prtint the longest subarray sum in an array of integers
    // maxSubArray()
    return 0;
}