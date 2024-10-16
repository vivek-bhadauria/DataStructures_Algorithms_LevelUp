#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<int>> a){
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a[0].size(); j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isPossible(vector<vector<int>> board, int i, int j, int rows, int cols, int choice){

    if(i<0 or i>=rows or j<0 or j>=cols){
        return false;
    }
    if(board[i][j] > 0){
        return false;
    }

    /* check grid */
    int rowStart = (i/3)*3;
    int rowEnd = rowStart+2;
    int colStart = (j/3)*3;
    int colEnd = colStart+2;
    for(int k=rowStart; k<=rowEnd; k++){
        for(int l=colStart; l<=colEnd; l++){
            if(board[k][l] == choice){
                return false;
            }
        }
    }

    /* check vertical */
    for(int k=1; i-k>=0 or i+k<rows; k++){
        if(i-k>=0 and board[i-k][j] == choice){
            return false;
        }
        if(i+k<rows and board[i+k][j] == choice){
            return false;
        }
    }

    /* check horizontal */
    for(int k=1; j-k>=0 or j+k<cols; k++){
        if(j-k>=0 and board[i][j-k] == choice){
            return false;
        }
        if(j+k<cols and board[i][j+k] == choice){
            return false;
        }
    }

    return true;
}

bool sudoku(vector<vector<int>> &board, int rows, int cols, int i, int j){

    if(i==rows){
        printBoard(board);
        return true;
    }
    if(j==cols){
        return sudoku(board, rows, cols, i+1, 0);
    }
    if(board[i][j]!=0){
        return sudoku(board, rows, cols, i, j+1);
    }

    for(int choice=1; choice<=9; choice++){
        if(isPossible(board, i, j, rows, cols, choice)){
            board[i][j] = choice;
            if(sudoku(board, rows, cols, i, j+1)){
               return true;
            }
            board[i][j] = 0;
        }
    }
    board[i][j] = 0;
    return false;
}


int main(){

    vector<vector<int>> board = {{0,3,0,0,0,0,9,0,0},
                                 {0,0,6,0,0,0,0,0,0},
                                 {0,0,0,2,4,1,0,3,0},
                                 {0,0,0,9,0,0,7,0,0},
                                 {0,0,0,0,0,2,0,0,4},
                                 {0,8,0,0,7,0,0,2,0},
                                 {8,5,0,0,0,0,0,0,0},
                                 {0,9,0,7,0,4,0,0,0},
                                 {0,0,0,0,0,6,0,0,1}};

    sudoku(board, 9, 9, 0, 0);
}