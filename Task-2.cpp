/* Welcome to my new project Sudoku Solver:-
   Here you input your Sudoku Game and will get your answer.
   A Sudoku solution must satisfy all of the following rules:-

   Each of the digits 1-9 must occur exactly once in each row.
   Each of the digits 1-9 must occur exactly once in each column.
   Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
   The '.' character indicates empty cells.
*/

#include<bits/stdc++.h>
using namespace std;

bool check(int num,vector<vector<char> >&board,int i,int j){
    char c='0'+num;
    //Check at same row
    for(int col=0;col<9;col++){
        if(board[i][col]==c)
        return 0;
    }
    //Check at same column 
    for(int row=0;row<9;row++){
        if(board[row][j]==c)
        return 0;
    }
    //Check at same box
    int row=(i/3)*3,col=(j/3)*3;
    for(int a=row;a<row+3;a++)
    for(int b=col;b<col+3;b++){
        if(board[a][b]==c)
        return 0;
    }
    return 1;
}

bool find(int i,int j,vector<vector<char> >&board){
    //Base condition
    if(i==9)
    return 1;

    if(j==9)
    return find(i+1,0,board);

    if(board[i][j]!='.')
    return find(i,j+1,board);

    for(int num=1;num<10;num++){
        if(check(num,board,i,j)){
            board[i][j]='0'+num;
            if(find(i,j+1,board))
            return 1;
            board[i][j]='.';//Back track
        }
    }
    return 0;
}

 bool solveSudoku(vector<vector<char> >& board) {
        return find(0,0,board);
    }

    int main(){
        vector<vector<char> >board(9,vector<char>(9));
        cout<<"Enter the Sudoku you want to solve\n";
        for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            //Empty cell is denoted as '.' here
            cout<<"Enter "<<i<<" th row and "<<j<<" th column element of the Sudoku ";
            cin>>board[i][j];
        }
        if(solveSudoku(board)){
            for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
        }
        }
        else 
        cout<<"No solution exists\n";
        return 0;
    }