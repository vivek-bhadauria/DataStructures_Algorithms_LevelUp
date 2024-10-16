#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<int>> a){
    cout<<"Board"<<endl;
    for(auto v : a){
        for(auto x : v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

bool isPossible(vector<vector<int>> board, int i, int j, int rows, int cols){

    if(i<0 or i>=rows or j<0 or j>=cols){
        return false;
    }

    if(board[i][j] == 1){
        return false;
    }


    /* check left diagonal */
    for(int k=1; i-k>=0 and j-k>=0; k++){
        if(board[i-k][j-k] == 1){
            return false;
        }
    }

    /* check right diagonal */
    for(int k=1; i-k>=0 and j+k<cols; k++){
        if(board[i-k][j+k] == 1){
            return false;
        }
    }

    /* check horizontal */
    for(int k=1; j-k>=0; k++){
        if(board[i][j-k] == 1){
            return false;
        }
    }

    /* check vertical */
    for(int k=1; i-k>=0; k++){
        if(board[i-k][j] == 1){
            return false;
        }
    }

    return true;

}


bool nqueen(vector<vector<int>> &board, int rows, int cols, int n, int i, int j){

    if(n==0){
        printBoard(board);
        return true;
    }
    if(i>=rows or j>cols){
        return false;
    }
    if(j==cols){
        return nqueen(board, rows, cols, n, i+1, 0);
    }

    if(isPossible(board, i, j, rows, cols)){
        board[i][j] = 1;
        if(nqueen(board, rows, cols, n-1, i+1, 0)){
            return true;
        }
        board[i][j] = 0;
    }
    return nqueen(board, rows, cols, n, i, j+1);

}

void nqueenAll(vector<vector<int>> &board, int rows, int cols, int n, int i, int j){

    if(n==0){
        printBoard(board);
        return;
    }
    if(i>=rows or j>cols){
        return;
    }
    if(j==cols){
        nqueenAll(board, rows, cols, n, i+1, 0);
    }

    if(isPossible(board, i, j, rows, cols)){
        board[i][j] = 1;
        nqueenAll(board, rows, cols, n-1, i+1, 0);
        board[i][j] = 0;
    }
    nqueenAll(board, rows, cols, n, i, j+1);
}

int nqueenCount(vector<vector<int>> &board, int rows, int cols, int n, int i, int j){
    int c=0;
    if(n==0){
        return 1;
    }
    if(i>=rows or j>cols){
        return 0;
    }
    if(j==cols){
       return nqueenCount(board, rows, cols, n, i+1, 0);
    }

    if(isPossible(board, i, j, rows, cols)){
        board[i][j] = 1;
        c += nqueenCount(board, rows, cols, n-1, i+1, 0);
        board[i][j] = 0;
    }
    c += nqueenCount(board, rows, cols, n, i, j+1);
    return c;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n,0));
    /*bool isPossible = nqueen(board,n,n,n,0,0);
    cout<<"Possible ? "<<(isPossible ? "YES" : "NO");*/
    //nqueenAll(board,n,n,n,0,0);
    cout<<"Count of possibile N Queen Configurations : "<<nqueenCount(board,n,n,n,0,0);
}