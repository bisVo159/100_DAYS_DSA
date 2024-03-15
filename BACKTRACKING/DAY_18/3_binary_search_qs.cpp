#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m,int mid){
    int studentCount = 1;
    int pageSum = 0;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m) 
            return false;
        
            pageSum = arr[i];
        }
       
    }
    return true;
}


int findPages(vector<int>& arr, int n, int m) {
    if(n<m)
    return -1;
    
    int s = 0;
    int e = 0;
    
    for(int i = 0; i<n; i++) {
        e += arr[i];
        s=max(s,arr[i]);
    }
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    // Allocate Books    -> https://www.codingninjas.com/studio/problems/allocate-books_1090540

    // Painter's Partition Problem  -> https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557

    // Aggressive Cows  -> https://www.codingninjas.com/studio/problems/aggressive-cows_1082559?leftPanelTabValue=
    return 0;
}