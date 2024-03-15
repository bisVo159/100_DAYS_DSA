#include<iostream>
#include<vector>
using namespace std;

  bool isSubsequence(string &s,string &t,int i,int j){
        if((i==s.length()&&j==t.length())||(i==s.length()&&j!=t.length()))
        return true;
        if(i!=s.length()&&j==t.length())
        return false;

        if(s[i]==t[j])
            return isSubsequence(s,t,i+1,j+1);

        return isSubsequence(s,t,i,j+1);

    }

     int lengthOfLIS(vector<int>&nums,int prev,int i){
        if(i==nums.size())
        return 0;

        int include=0;
            if(nums[i]==-1||nums[i]>prev)
            include=1+lengthOfLIS(nums,nums[i],i+1);
        int exclude=lengthOfLIS(nums,prev,i+1);

        return max(include,exclude);
    }

    int longestCommonSubsequence(string &text1,string &text2,int i,int j){
        if(i==text1.length()||j==text2.length())
        return 0;

        if(text1[i]==text2[j])
        return 1+longestCommonSubsequence(text1,text2,i+1,j+1);
        else
            return max(longestCommonSubsequence(text1,text2,i+1,j),longestCommonSubsequence(text1,text2,i,j+1));
    }

    int longestArithSeqLength(vector<int>& nums,int prev,int curr,int &diff){
        if(curr==nums.size())
        return 0;

        if(diff==prev-nums[curr])
            return 1+longestArithSeqLength(nums,nums[curr],curr+1,diff);
        else
            return longestArithSeqLength(nums,prev,curr+1,diff);
    }

    int longestArithSeqLength2(vector<int>& nums,int i,int &diff){
        if(i==0)
        return 0;

        int ans=0;
        for(int k=i-1;k>=0;k--){
            if(nums[i]-nums[k]==diff)
            ans=max(ans,1+longestArithSeqLength2(nums,k,diff));
        }
        return ans;
    }

int main(){
    // leetcode 392 subsequence
    // string s = "abc", t = "ahbgdc";
    // isSubsequence(s,t,0,0)?cout<<"Yes\n":cout<<"No\n";

    // 300. Longest Increasing Subsequence
    vector<int>nums={7,7,7,7,7,7,7};
       cout<<lengthOfLIS(nums,-1,0)<<endl;

    //    1143. Longest Common Subsequence
    string a="abcde";
    string b="ace";
    cout<<longestCommonSubsequence(a,b,0,0)<<endl;

    // 1027. Longest Arithmetic Subsequence
    int longest=0;
    for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
            int diff=nums[i]-nums[j];
            longest=max(longest,longestArithSeqLength(nums,nums[j],j+1,diff));
        }
    }
    for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
            int diff=nums[i]-nums[j];
            longest=max(longest,2+longestArithSeqLength2(nums,i,diff));
        }
    }
    return 0;
}