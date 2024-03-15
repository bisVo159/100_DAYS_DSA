#include<iostream>
#include<vector>
using namespace std;

   int lastRemaining(int n) {
        if(n==1)
        return 1;
        return 2*(1+n/2-lastRemaining(n/2));
        
    }

    int solve(vector<int>& nums,int i,int j){
        if(i==j)
        return nums[i];
        if(i>j)
        return 0;

        int opt1=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        int opt2=nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));
        return max(opt1,opt2);
    }

     int kthGrammar(int n, int k) {
        if(n==1)
            return 0;

        if(k%2==0)
            return !kthGrammar(n-1,k/2);
        
        return kthGrammar(n-1,k/2+1);
    }

int main(){
    // 390. Elimination Game
    // cout<<"The last remaining number in the elimination game is: "<<lastRemaining(5);

    // 486. Predict the Winner
    // vector<int>nums={5,3,7,10};
    //   int total=0;
    //     for(auto i:nums){
    //         total+=i;
    //     }

    //     int p1=solve(nums,0,nums.size()-1);
    //     int p2=total-solve(nums,0,nums.size()-1);
    //      p1>=p2?cout<<"p1 winner\n":cout<<"p2 winner\n";

    // 779. K-th Symbol in Grammar
    cout<<"Kth symbol in grammar is :"<<kthGrammar(4,5);

    // 1823. Find the Winner of the Circular Game
    
    return 0;
}