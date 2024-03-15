#include<iostream>
#include<stack>
using namespace std;

void printFront(int a[],int i,int size){
    if(i==size){
        return;
    }

    cout<<a[i]<<endl;
    printFront(a,++i,size);
}
void printReverse(int a[],int size){
    if(size<0){
        return;
    }

    cout<<a[size]<<endl;
    printReverse(a,--size);
}
void print3(int a[],int size){
    if(size==1){
        cout<<a[0]<<endl;
        return;
    }

    cout<<a[0]<<" , ";
    print3(a+1,size-1);
}

int maxValue(int a[],int size){
    if(size==1){
        return a[0];
    }

    return max(a[0],maxValue(a+1,size-1));
}

void getMaxi(int a[],int& size,int index,int& maxi){
    if(index==size)
    return;

    maxi=max(a[index],maxi);

    getMaxi(a,size,index+1,maxi);
}

int targetIndex(int a[],int& size,int index,int& target){
    if(index==size&&a[index]!=target)
        return -1;
    if(a[index]==target)
        return index;

    return   targetIndex(a,size,index+1,target);
}

int lastOcc(int a[],int size,int& target){
        if(size<0)
        return -1;

        if(a[size]==target)
        return size;

        return lastOcc(a,size-1,target);
}

void findAllOcc(int a[],int index,int size,int target,stack<int>&s){
    if(index==size)
         return ;

    if(a[index]==target)
        s.push(index);

    findAllOcc(a,index+1,size,target,s);
    
}

int main(){
    // int arr[]={1,2,3,4,5,6,7,8,9,10};
    // printFront(arr,0,sizeof(arr)/sizeof(int));
    // printReverse(arr,sizeof(arr)/sizeof(int)-1);
    // print3(arr,sizeof(arr)/sizeof(int));


    int arr[]={7,2,15,9,21,18};
        int size=6;
    // cout<<maxValue(arr,6)<<endl;

    // int maxi=INT16_MIN;
    // getMaxi(arr,size,0,maxi);
    // cout<<"Maximum value : "<<maxi<<endl;


    // Find the first index of target
    // int target=2;
    // cout<<"Index of "<<target<<" -> "<<targetIndex(arr,size,0,target)<<endl;

    // last Occurance
    //    int a[]={7,2,15,9,21,18,15,2,21,18,7};
    //     int s=11;
    //     int target=21;
    //     cout<<"Last Occurance "<<" -> "<<lastOcc(a,s-1,target)<<endl;


    // find all occurance
    stack<int> s;
     int a[]={7,2,15,9,21,18,15,2,21,18,7,2,9};

    findAllOcc(a,0,13,2,s);
    while(s.size()!=0){
        cout<<s.top()<<" , ";
        s.pop();
    }cout<<endl;

    return 0;
}