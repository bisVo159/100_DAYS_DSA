#include<iostream>
#include<vector>
using namespace std;

 int firstOcc(vector<int>& nums, int target,int n){
        int s=0,e=n-1;
        int mid=s+(e-s)/2;

        int ans=-1;

        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                e=mid-1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }

            mid=s+(e-s)/2;
        }
        return ans;
    }

    int lastOcc(vector<int>& nums, int target,int n,int left){
        int s=left,e=n-1;
        int mid=s+(e-s)/2;

        int ans=-1;

        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                s=mid+1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }

            mid=s+(e-s)/2;
        }
        return ans;
    }

int main(){
    // 34. Find First and Last Position of Element in Sorted Array

    vector<int>nums={5,7,7,8,8,8,8,8,8,8,8,10};
    int target=8;
    vector<int>pos={-1,-1};
        int n=nums.size();
        pos[0]=firstOcc(nums,target,n);
        if(pos[0]!=-1)
        pos[1]=lastOcc(nums,target,n,pos[0]);

        cout<<"first occurance "<<pos[0]<<endl;
        cout<<"last occurance "<<pos[1]<<endl;


        // Number of occurrence

        int occ=pos[1]-pos[0]+1;
        cout<<"Number of occurrence of "<<target<<" = "<<occ<<endl;

        // 852. Peak Index in a Mountain Array
    return 0;
}