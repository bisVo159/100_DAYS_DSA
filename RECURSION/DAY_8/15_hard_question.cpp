#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s,unordered_map<string,bool>&m){
    if(s.length()==0)
        return 1;

        bool present=0;
        for(int i=1;i<=s.length();i++){
            if(m[s.substr(0,i)]&&wordBreak(s.substr(i),m))
                return true;
        }
        return false;
    }

int main(){
    // 139. Word Break
    string s="aaaaaaa";
    vector<string>wordDict={"aaaa","aaa"};
    unordered_map<string,bool>m;
        for(int i=0;i<wordDict.size();i++){
            m[wordDict[i]]=true;
        }

     wordBreak(s,m)?cout<<"can be segmented"<<endl:cout<<"cannot be segmented"<<endl;
    return 0;
}