#include<iostream>
using namespace std;

// HeapSort
// Array convert MaxHeap
// MaxHeap to sorted array

void Heapify(int arr[],int index,int size){
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<size&&arr[left]>arr[largest]) largest=left;
    if(right<size&&arr[right]>arr[largest]) largest=right;

    if(index!=largest){
        swap(arr[largest],arr[index]);
        Heapify(arr,largest,size);
    }
}

void BuildMaxHeap(int arr[],int n){
    // step down
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,i,n);
    }
}

void sortArray(int arr[],int n){

    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        Heapify(arr,0,i);
    }
}


void printHeap(int arr[],int n){
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
}
int main(){
    // T.C ->O(n)
    int arr[]={10,3,8,9,5,13,18,14,11,70};
    BuildMaxHeap(arr,10);

    // HeapSort -> O(nlogn)
    sortArray(arr,10);

   printHeap(arr,10);
    return 0;
}