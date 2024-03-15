#include<bits/stdc++.h>
using namespace std;

 bool isSafe(vector<vector<int>>& cuboids,int curr,int prev){
        return cuboids[curr][1]<=cuboids[prev][1]&&cuboids[curr][2]<=cuboids[prev][2];
    }

 int maxHeight(vector<vector<int>>& cuboids,int curr,int prev){
        if(curr<0)
        return 0;

        int take=0;
        if(prev==-1||isSafe(cuboids,curr,prev))
            take=cuboids[curr][2]+maxHeight(cuboids,curr-1,curr);

        int notTake=maxHeight(cuboids,curr-1,prev);

        return max(take,notTake);
    }

int main(){
    // 1691. Maximum Height by Stacking Cuboids
    vector<vector<int>>cuboids={
        {50,45,20},{95,37,53},{45,23,12}
    };
    // step1 : sort all dimensions
        
        for(int i=0;i<cuboids.size();i++)
            sort(cuboids[i].begin(),cuboids[i].end());

        // step2: sort basis on first parameter
        sort(cuboids.begin(),cuboids.end());
        for(auto i:cuboids){
            for(auto j:i)
                cout<<j<<" ";
                cout<<endl;
        }
        cout<<"the maximum height of the stacked cuboids "<<maxHeight(cuboids,cuboids.size()-1,-1)<<endl;  
          return 0;
}