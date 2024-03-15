#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;
void permutation(vector<int>&nums,vector<int>&ds,unordered_map<int,bool>&map){
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }

    for(int i=0;i<nums.size();i++){
        if(!map[nums[i]]){
            map[nums[i]] = true;
            ds.push_back(nums[i]);
            permutation(nums,ds,map);
            ds.pop_back();
            map[nums[i]] = false;
        }

    }
}

void permutation(vector<int>&nums,int index){
    if(index==nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=index;i<nums.size();i++){
        swap(nums[i],nums[index]);
        permutation(nums,index+1);
        swap(nums[i],nums[index]);
    }
}


int main(){
    unordered_map<int,bool>map;
    vector<int>nums={1,1,2,2};
    // vector<int>ds;
    // permutation(nums,ds,map);

    // permutation(nums,0);
    for(auto i:ans){
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }


    // 47. Permutations II
    // 60. Permutation Sequence
    
    return 0;
}