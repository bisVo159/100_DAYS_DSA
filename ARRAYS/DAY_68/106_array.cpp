#include<iostream>
using namespace std;

// T.C -> O(r)
// S.C -> O(1)
int nCr(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }

    return res;
}

int main(){
    // 560. Subarray Sum Equals K
    // 118. Pascal's Triangle
    // Print Pascal’s Triangle ->https://www.codingninjas.com/studio/problems/print-pascal-s-triangle_6917910
    // to find r row c column value  in pascal triangle, we can use the formula
    /*
        (r-1)C(c-1)  -> nCr(r-1,c-1)
    */

//    119. Pascal's Triangle II
    return 0;
}