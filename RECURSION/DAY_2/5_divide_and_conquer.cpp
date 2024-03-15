#include<iostream>
using namespace std;

void solve(int *arr,int s,int e){
    if(s>=e){
        cout<<arr[s]<<endl;
        return;
    }

    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    int mid=s+(e-s)/2;
    solve(arr,s,mid);
    solve(arr,mid+1,e);
}

void merge(int *arr,int s,int mid,int e){
    int len1=mid-s+1;
    int len2=e-mid;

    int *first=new int[len1];
    int *second=new int[len2];

    int i=0;
    for(int index=s;index<=mid;index++){
        first[i]=arr[index];
        i++;
    }
    int j=0;
    for(int index=mid+1;index<=e;index++){
        second[j]=arr[index];
        j++;
    }

    int originalIndex=s;
    int index1=0;
    int index2=0;
    while(index1<len1&&index2<len2){
        if(first[index1]<=second[index2]){
            arr[originalIndex]=first[index1];
            index1++;
        }
        else{
            arr[originalIndex]=second[index2];
            index2++;
        }
        originalIndex++;
    }

    while(index1<len1){
        arr[originalIndex++]=first[index1++];
    }
    while(index2<len2){
        arr[originalIndex++]=second[index2++];
    }


}

void mergeSort(int *arr,int s,int e){
    if(s==e)
    return;

    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

int main(){
    int a[]={3,4,1,5,9,2};
    mergeSort(a,0,5);
    for(int i=0;i<=5;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
   
    return 0;
}