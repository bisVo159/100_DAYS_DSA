#include<iostream>
#include<vector>
using namespace std;

int solve(int n,int &k){
    if(n==1)
    return k;
    if(n==2)
    return k*k;

    return solve(n-1,k)*(k-1)+solve(n-2,k)*(k-1);
}

  int maxSizeSlices(vector<int>&slices,int s,int e,int count){
        if(count==0||s>e)
        return 0;

        int include=slices[s]+maxSizeSlices(slices,s+2,e,count-1);
        int exclude=maxSizeSlices(slices,s+1,e,count);
        return max(include,exclude);
    }

int main(){
    // Painting Fence
    // int n=5,k=3;
    // cout<<"No of possibilities to paint "<<n<<" fence "<<solve(n,k)<<endl;

    // 1388. Pizza With 3n Slices
    vector<int>slices={8,9,8,6,1,1};
    cout<<"maximum possible sum of slice sizes "<<max(maxSizeSlices(slices,0,slices.size()-2,slices.size()/3),maxSizeSlices(slices,1,slices.size()-1,slices.size()/3));

    return 0;
}