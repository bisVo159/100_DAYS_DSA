#include<iostream>
#include<utility>
using namespace std;

pair<int,bool>  binarySearch(int *a,int i,int j,int target){
    int mid=(i+j)/2;
      if(i==j&&a[mid]!=target){
        return {-1,0};
    }
    if(a[mid]==target)
    return {mid,1};

    if(target>a[mid])
    return binarySearch(a,mid+1,j,target);
    else
    return binarySearch(a,i,mid-1,target);
}

int main(){
    int a[]={23,34,56,67,78,90};
    pair<int,bool> p=binarySearch(a,0,5,90);
    cout<<p.first<<" "<<p.second<<endl;
    
    return 0;
}