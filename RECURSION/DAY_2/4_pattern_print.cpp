#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    // 1
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<j<<" ";
    //     }cout<<endl;
    // }

    // 2
    // int i=1;
    // int count=1;
    // while(i<=n){
    //     int j=1;
    //     while(j<=n){
    //         cout<<count++<<" ";
    //         j++;
    //     }cout<<endl;
    //     i++;
    // }


// 3
    // for(int row=1;row<=n;row++){
    //     for(int col=1;col<=row;col++){
    //         cout<<"*";
    //     }cout<<endl;
    // }

// 4
    // int row=1;
    // while(row<=n){
    //     int col=1;
    //     while(col<=row){
    //         cout<<row;
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }


// 5
    // int row=1;
    // while(row<=n){
    //     int col=1;
    //     int count=row;
    //     while(col<=row){
    //         cout<<count;
    //         count++;
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }

    // 6
    //     int row=1;
    // while(row<=n){
    //     int col=1;
    //     while(col<=row){
    //         cout<<row-col+1;
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }

// 7
    //    int row=1;
    // while(row<=n){
    //     int col=1;
    //     char ch='A'+row-1;
    //     while(col<=n){
    //         cout<<ch;
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }

    // 8
    // int row=1;
    // while(row<=n){
    //     int col=1;
    //     while(col<=n){
    //         char ch='A'+col-1;
    //         cout<<ch;
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }

    // 9
    // int row=1;
    // int start=0;
    // while(row<=n){
    //     int col=1;
    //     while(col<=n){
    //         char ch='A'+start++;
    //         cout<<ch;
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }

    // 10
    // int row=1;
    // while(row<=n){
    //     int col=1;
    //     while(col<=n){
    //         char ch='A'+col+row-2;
    //         cout<<ch;
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }

    // 11
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<char('A'+i-1);
    //     }cout<<endl;
    // }

    // 12
    // int i=1;
    // int k=0;
    // while(i<=n){
    //     int j=1;
    //     while(j<=i){
    //         cout<<char('A'+k++);
    //         j++;
    //     }cout<<endl;
    //     i++;
    // }

    // 13
    // int i=1;
    // while(i<=n){
    //     int j=1;
    //     while(j<=i){
    //         cout<<char('A'+i+j-2);
    //         j++;
    //     }cout<<endl;
    //     i++;
    // }

    // 14
    // int i=1;
    // while(i<=n){
    //     int j=1;
    //     char start='A'+n-i;
    //     while(j<=i){
    //         cout<<start++;
    //         j++;
    //     }cout<<endl;
    //     i++;
    // }

    // 15
    // for(int row=1;row<n;row++){
    //     for(int space=1;space<=n-row;space++){
    //         cout<<" ";
    //     }
    //     for(int star=1;star<=row;star++){
    //         cout<<"*";
    //     }cout<<endl;
    // }

    // 16
    // int row=1;
    // while(row<=n){
    //     int col=1;
    //     while(col<=n-row+1){
    //         cout<<"*";
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }

    // 17
    //     int row=1;
    // while(row<=n){
    //     int space=1;
    //     while(space<=row-1){
    //         cout<<" ";
    //         space++;
    //     }
    //     int col=1;
    //     while(col<=n-row+1){
    //         cout<<"*";
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }

    // 18
    //     int row=1;
    // while(row<=n){
    //     int space=1;
    //     while(space<=row-1){
    //         cout<<" ";
    //         space++;
    //     }
    //     int col=1;
    //     while(col<=n-row+1){
    //         cout<<row;
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }

    // 19
    //     int row=1;
    // while(row<=n){
    //     int space=1;
    //     while(space<=n-row){
    //         cout<<" ";
    //         space++;
    //     }
    //     int col=1;
    //     while(col<=row){
    //         cout<<row;
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }

    // 20
    //         int row=1;
    // while(row<=n){
    //     int space=1;
    //     while(space<=row-1){
    //         cout<<" ";
    //         space++;
    //     }
    //     int col=1;
    //     while(col<=n-row+1){
    //         cout<<col+space-1;
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }

    // 21
    //         int row=1;
    //         int count=1;
    // while(row<=n){
    //     int space=1;
    //     while(space<=n-row){
    //         cout<<" ";
    //         space++;
    //     }
    //     int col=1;
    //     while(col<=row){
    //         cout<<count++;
    //         col++;
    //     }cout<<endl;
    //     row++;
    // }

    // 22
    // int row=1;
    // while(row<=n){
    //     int space=1;
    //     while(space<=n-row){
    //         cout<<" ";
    //         space++;
    //     }

    //     int col=1;
    //     int k=1;
    //     while(col<=2*row-1){
    //         if(col<=row){
    //              cout<<k;
    //              if(k<row)
    //              k++;
    //         }
    //         else{
    //             cout<<--k;
    //         }

    //         col++;
    //     }cout<<endl;
    //     row++;
    // }


    // 23
    int i=1;
    while(i<=n){
        int j=1;
        int k=0;
        while(j<=2*n){
            if(j<=n-i+1){
                cout<<++k;
            }
            else if(j>n-i&&j<n+i){
                cout<<"*";
            }
            else{
                cout<<k--;
            }
            j++;
        }cout<<endl;
        i++;
    }

     return 0;
}