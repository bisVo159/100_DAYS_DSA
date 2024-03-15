#include<bits/stdc++.h>
using namespace std;

unordered_map<int,bool>done;
void solve(string& s,int i){
    if(i==s.length()){
        cout<<s<<endl;
        return;
    }

    if(!done[s[i]]){
        for(int j=i;j<s.length();j++){
            if((j!=i)&&(s[j]==s[i]))
            continue;
            swap(s[i],s[j]);
            solve(s,i+1);
            // backtrack
            swap(s[i],s[j]);
        }
        done[s[i]]=1;
    }
    else{
    solve(s,i+1);
    }

}


int main(){
    string str="abb";
    solve(str,0);cout<<endl;

    return 0;
}