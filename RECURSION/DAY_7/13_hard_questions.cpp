#include<iostream>
using namespace std;

bool isMatch(string &s, string &p,int i,int j){
        if(i==0&&j==0)
        return true;
        if(i>0&&j==0)
        return false;
        if(i==0&&j>0){
            for(int k=j;k>0;k--){
                if(p[k-1]!='*')
                return false;
            }
            return true;
        }


        if(s[i-1]==p[j-1]||p[j-1]=='?')
            return isMatch(s,p,i-1,j-1);
        
        else if(p[j-1]=='*')
            return isMatch(s,p,i,j-1)||isMatch(s,p,i-1,j);
        else
            return false;
    }

int main(){
    // 44. Wildcard Matching
    string a="cb",b="?a";
    isMatch(a,b,a.length(),b.length())?cout<<"Matched"<<endl:cout<<"Not Matched "<<endl;
    return 0;
}