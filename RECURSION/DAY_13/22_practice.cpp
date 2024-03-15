#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int>v={2,1,5,4,3,0,0};
    next_permutation(v.begin(),v.end());
    // for(auto &i:v)
    // cout<<i<<" ";
    // cout<<endl;

    // reverse(v.begin()+2,v.end());
     for(auto &i:v)
    cout<<i<<" ";
    cout<<endl;

    // 31. Next Permutation
    // 10. Regular Expression Matching

    return 0;
}