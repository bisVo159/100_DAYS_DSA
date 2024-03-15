#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b){
    if(a==1&&b==1)
    return 0;

    if(a==b)
    return 1;
    int ans1=a>1?solve(a-1,b):INT_MAX;

    int ans2=b>1?solve(a,b-1):INT_MAX;

    int ans3=!(a%b)&&b>1?solve(a/b,b):INT_MAX;
  
    int ans4=!(b%a)&&a>1?solve(a,b/a):INT_MAX;

    return min(ans1,min(ans2,min(ans3,ans4)))+1;
}
int main(){
    // Minimize operations to reduce A and B to 1 by decrementing 1 or dividing A by B and B by A
    int a=13,b=5;

    cout<<"Minimum number of operations required: "<<solve(a,b)<<endl;
    return 0;
}