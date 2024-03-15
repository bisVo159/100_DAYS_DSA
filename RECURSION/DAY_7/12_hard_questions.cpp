#include<iostream>
using namespace std;

 int minDistance(string &a, string &b,int i,int j){
        if(i==a.length())
            return b.length()-j;
        if(j==b.length())
            return a.length()-i;

        if(a[i]==b[j])
            // match
            return minDistance(a,b,i+1,j+1);
        else{
            // no match
            int insertAns=minDistance(a,b,i,j+1);
            int replaceAns=minDistance(a,b,i+1,j+1);
            int deleteAns=minDistance(a,b,i+1,j);
            
            return min(insertAns,min(replaceAns,deleteAns))+1;
        }
    }

int main(){
    // 72. Edit Distance
    string str1="intention";
    string str2="execution";
    cout<<"Minimum number of operations to convert "<<str1<<" into "<<str2<<": "<<minDistance(str1,str2,0,0)<<endl;

    return 0;
}