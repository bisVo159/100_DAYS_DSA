#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x,int y,vector<vector<char>>&board,vector<vector<bool>>&visited){
    int rowSize=board.size();
    int colSize=board[0].size();

    return (x>=0&&x<rowSize)&&
                    (y>=0&&y<colSize)&&
                        (!visited[x][y])&&
                            (board[x][y]=='.');
}
vector<string>path;

bool solve(int srcx,int srcy,int destx,int desty,vector<vector<char>>&board,vector<vector<bool>>&visited,string output){
    if (srcx == destx && srcy == desty) {
        path.push_back(output);
        return true;
        }

    visited[srcx][srcy]=1;

        // Down
        int newx=srcx+1;
        int newy=srcy;
        bool downAns=false;
        if(isSafe(newx,newy,board,visited)){
            downAns = solve(newx,newy,destx,desty,board,visited,output+"D");
        }

        // Right
        newx=srcx;
        newy=srcy+1;
        bool rightAns=false;
        if(isSafe(newx,newy,board,visited)){
            rightAns = solve(newx,newy,destx,desty,board,visited,output+"R");
        }

        // Up
        newx=srcx-1;
        newy=srcy;
        bool upAns=false;
        if(isSafe(newx,newy,board,visited)){
            upAns = solve(newx,newy,destx,desty,board,visited,output+"U");
        }
        // Left
        newx=srcx;
        newy=srcy-1;
        bool leftAns=false;
        if(isSafe(newx,newy,board,visited)){
            leftAns = solve(newx,newy,destx,desty,board,visited,output+"L");
        }

        visited[srcx][srcy]=0;
        return downAns||rightAns||upAns||leftAns;

}

// all movement in loop

    // void solve(int srcx, int srcy, int destx, int desty, vector<vector<int>>& board, vector<vector<bool>>& visited, string& output, vector<string>& path) {
    //     if (srcx == destx && srcy == desty) {
    //         path.push_back(output);
    //         return;
    //     }

    //     visited[srcx][srcy] = true;

    //     int dx[] = {1, 0, -1, 0};
    //     int dy[] = {0, 1, 0, -1};
    //     char dir[] = {'D', 'R', 'U', 'L'};

    //     for (int i = 0; i < 4; i++) {
    //         int newx = srcx + dx[i];
    //         int newy = srcy + dy[i];

    //         if (isSafe(newx, newy, board, visited)) {
    //             output.push_back(dir[i]);
    //             solve(newx, newy, destx, desty, board, visited, output, path);
    //             output.pop_back();
    //         }
    //     }

    //     visited[srcx][srcy] = false;
    // }

int main(){
    vector<vector<char>>board={
                                                                {'.','.','.','x'},
                                                                {'.','x','x','.'},
                                                                {'.','.','.','.'},
                                                                {'.','x','.','.'}
                                                            };

    vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),0));

    string output="";

    solve(0,0,board.size()-1,board[0].size()-1,board,visited,output)?cout<<"Src to dest is possible"<<endl:cout<<"Src to dest is not possible"<<endl;
    for (auto i : path) {
            cout << i<< " ";
            cout<<endl;
        }
    
    return 0;
}