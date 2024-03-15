#include<iostream>
#include<vector>
#include<string> 
using namespace std;

string reverse(string &s,int i){
    if(i==s.length())
        return "";

    return reverse(s,i+1)+s[i];
}

void reverse1(string &s,int i,int j){
    if(i>=j)
    return;

    swap(s[i],s[j]);
    reverse1(s,i+1,j-1);
}

void subSequence(string s,int i,string ans,vector<string>&v){
    if(i==s.length()){
        v.push_back(ans);
        return;
    }

    subSequence(s,i+1,ans,v);
    subSequence(s,i+1,ans+s[i],v);
}

void addStrings(string a,string b,int carry,string& ans,int i,int j){
    if(i<0&&j<0&&carry==0)
    return;

    int first=0;
    int second=0;
    if(i>=0)
         first=a[i]-'0';
    if(j>=0)
        second=b[j]-'0';

    int sum=first+second+carry;

    int lastDigit=sum%10;
     carry=sum/10;

    ans=to_string(lastDigit)+ans;
    addStrings(a,b,carry,ans,i-1,j-1);
}


int main(){
    string str="babbar";
//     cout<<reverse(str,0)<<endl;
//    reverse1(str,0,str.length()-1);
//    cout<<str<<endl;


// Subsequence of string
// vector<string> subStr;
// string sub="";
// subSequence("anik", 0,sub,subStr);
// for (auto x : subStr) {
//     cout<<x<<endl;
// }


// Add two string
string a="43";
string b="393";
string ans="";
addStrings(a,b,0,ans,a.length()-1,b.length()-1);
cout<<ans<<endl;

    return 0;
}