#include<bits/stdc++.h>
using namespace std;

int minSwap(vector<int>& num1, vector<int>& num2,int index,int prev1,int prev2){
        if(index==num1.size())
        return 0;

        int swap=INT_MAX;
        int noswap=INT_MAX;
 
        if(num1[index]>prev1&&num2[index]>prev2)
         noswap= minSwap(num1,num2,index+1,num1[index],num2[index]);

        if(num1[index]>prev2&&num2[index]>prev1)
         swap= 1+minSwap(num1,num2,index+1,num2[index],num1[index]);

        return min(swap,noswap);
}

int main(){
    // 801. Minimum Swaps To Make Sequences Increasing
    
    vector<int>nums1={0,4,4,5,9};
    vector<int>nums2={0,1,6,8,10};
    cout<<"minimum number of needed operations to make nums1 and nums2 strictly increasing "<<minSwap(nums1,nums2,0,-1,-1)<<endl;
    return 0;
}