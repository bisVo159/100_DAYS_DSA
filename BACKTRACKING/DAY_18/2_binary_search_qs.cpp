#include<iostream>
using namespace std;

int getPivot(int arr[],int n){
    int s=0,e=n-1;
    int mid=s+(e-s)/2;

    while(s<e){
        if(arr[0]<=arr[mid]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=(s+e)/2;
    }

    return s;
}

long long int sqrInteger(int n){
    int s=0,e=n;

    long long int mid=s+(e-s)/2;

    long long int ans=0;
    while(s<=e){
        long long int sqr=mid*mid;

        if(sqr==n)
        return mid;

        else if(sqr<n){
            ans=mid;
            s=mid+1;
        }
        else
        e=mid-1;

        mid=s+(e-s)/2;
    }
    return ans;
}

double morePrecision(int n,int precision,int tempSol){
    double factor=1;
    double ans=tempSol;

    for(int i=0;i<precision;i++){
        factor/=10.0;
        for(double j=ans;j*j<n;j+=factor){
            ans=j;
        }
        ans=ans;
    }

    return ans;
}

int main(){
    //1  -> // find pivot in an array
    int arr[5]={8,10,17,1,3};
    cout<<"pivot is "<<getPivot(arr,5)<<endl;

    //2 -> // 33. Search in Rotated Sorted Array

    // 69. Sqrt(x)
    int x = 5;
    int tempSol= sqrInteger(x);
    
    cout<<"Answer is "<<morePrecision(x,3,tempSol)<<endl;

    return 0;
}