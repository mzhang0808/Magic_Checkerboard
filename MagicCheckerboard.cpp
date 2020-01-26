#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long heightIsOne(vector<vector<long>>& board);
long widthIsOne(vector<vector<long>>& board);
void assignTop(vector<vector<long>> board, long r, long c, long& val);
void assignLeft(vector<vector<long>> board, long r, long c, long& val);
long findMinSumIfEvenEven(vector<vector<long>> board);
long findMinSumIfEvenOdd(vector<vector<long>> board);
long findMinSumIfOddEven(vector<vector<long>> board);
long findMinSumIfOddOdd(vector<vector<long>>& board);

//If height is 1
long heightIsOne(vector<vector<long>>& board){
    long s = 0;
    for(long i=0;i<board[0].size();i++){
        //Replace value if it is 0 cell
        if(board[0][i] == 0){
            //0th-cell must begin with 1 for minimal sum (if replacing)
            if(i == 0){
                board[0][i] = 1;
            }
            //Replace with previous cell + 1 to satisfy increasing property
            else{
                board[0][i] = board[0][i-1] + 1;
            }
            s+=board[0][i];
        }
        else{
            //Check that increasing property is still upheld
            if(board[0][i] <= board[0][i-1]){
                return -1;
            }
        }
    }
    return s;
}

//If width is 1
long widthIsOne(vector<vector<long>>& board){
    long s = 0;
    for(long i=0;i<board.size();i++){
        //Replace value if is 0 cell
        if(board[i][0] == 0){
            //0th-cell must begin with 1 for minimal sum (if replacing)
            if(i == 0){
                board[i][0] = 1;
            }
            //Replace with previous cell + 1 to satisfy increasing property
            else{
                board[i][0] = board[i-1][0] + 1;
            }
            s+=board[i][0];
        }
        else{
            //Check that increasing property is upheld
            if(board[i][0] <= board[i-1][0]){
                return -1;
            }
        }
    }
    return s;
}

//Finds value above current cell
void assignTop(vector<vector<long>> board, long r, long c, long& val){
    if(r == 0){
        val = 0;
    }
    else{
        val = board[r-1][c];
    }
}

//Finds value to left of current cell
void assignLeft(vector<vector<long>> board, long r, long c, long& val){
    if(c == 0){
        val = 0;
    }
    else{
        val = board[r][c-1];
    }
}

//Begins with Even Even {e.g. 2 4} --> columns must be same parity
long findMinSumIfEvenEven(vector<vector<long>> board){
    cout << "findMinSumIfEvenEven";
    long s = 0;
    long t = 0;
    long l = 0;
    for(long i=0;i<board.size();i++){
        for(long j=0;j<board[0].size();j++){
            assignTop(board, i, j, t);
            assignLeft(board, i, j, l);
            //Need to change value to minimum possible
            if(board[i][j] == 0){
                //to ensure that it stays in increasing order
                board[i][j] = max(t+1, l+2);
            }
            //Rows must be same parity
            else if( ( (i!=0) && ((board[i][j] % 2) == (board[i-1][j] % 2))) 
                || board[i][j] <= l || board[i][j] <= t){
                    return INT_MAX;
            }
            s += board[i][j];
            cout << board[i][j];
        }
        cout << endl;
    }
    return s;
}

long findMinSumIfOddEven(vector<vector<long>> board){
    cout << "findMinSumIfOddEven" << endl;
    if(board[0][0] == 0){
        board[0][0] = 1;
    }
    long s = 0;
    long t = 0;
    long l = 0;
    for(long i=0;i<board.size();i++){
        for(long j=0;j<board[0].size();j++){
            assignTop(board, i, j, t);
            assignLeft(board, i, j, l);
            //Need to change value to minimum possible
            if(board[i][j] == 0){
                //to ensure that it stays in increasing order
                board[i][j] = max(t+2, l+1);
            }
            //Columns must be same parity, rows must alternate
            else if( ( (i!=0) && ((board[i][j] % 2) == (board[i][j-1] % 2))) 
                || board[i][j] <= l || board[i][j] <= t){
                    return INT_MAX;
            }
            s += board[i][j];
            cout << board[i][j];
        }
        cout << endl;
    }
    return s;
}

long findMinSumIfEvenOdd(vector<vector<long>> board){
    cout << "findMinSumIfEvenOdd" << endl;
    long s = 0;
    long t = 0;
    long l = 0;
    for(long i=0;i<board.size();i++){
        for(long j=0;j<board[0].size();j++){
            assignTop(board, i, j, t);
            assignLeft(board, i, j, l);
            //Need to change value to minimum possible
            if(board[i][j] == 0){
                //to ensure that it stays in increasing order
                board[i][j] = max(t+2, l+1);
            }
            //Columns must be same parity, rows must alternate
            else if( ( (i!=0) && ((board[i][j] % 2) == (board[i][j-1] % 2))) 
                || board[i][j] <= l || board[i][j] <= t){
                    return INT_MAX;
            }
            s += board[i][j];
            cout << board[i][j];
        }
        cout << endl;
    }
    return s;
}

long findMinSumIfOddOdd(vector<vector<long>>& board){
    cout << "findMinSumIfOddOdd" << endl;
    if(board[0][0] == 0){
        board[0][0] = 1;
    }
    long s = 0;
    long t = 0;
    long l = 0;
    for(long i=0;i<board.size();i++){
        for(long j=0;j<board[0].size();j++){
            assignTop(board, i, j, t);
            assignLeft(board, i, j, l);
            //Need to change value to minimum possible
            if(board[i][j] == 0){
                //to ensure that it stays in increasing order
                board[i][j] = max(t+1, l+2);
            }
            //Rows must be same parity
            else if( ( (i!=0) && ((board[i][j] % 2) == (board[i-1][j] % 2))) 
                || board[i][j] <= l || board[i][j] <= t){
                    return INT_MAX;
            }
            s += board[i][j];
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return s;
}

int main(){
    long r = 0, c = 0;
    cin >> r >> c;
    vector<vector<long>> board(r,vector<long>(c));
    for(long i=0;i<r;i++){
        for(long j=0;j<c;j++){
            cin >> board[i][j];
        }
    }
    //Height is 1
    if(r==1){
        cout << heightIsOne(board);
    }
    //Width is 1
    else if(c == 1){
        cout << widthIsOne(board);
    }
    else{
        int a = min(findMinSumIfEvenEven(board), findMinSumIfEvenOdd(board));
        int b = min(findMinSumIfOddOdd(board), findMinSumIfOddEven(board));
        int c = min(a, b);
        if(c == INT_MAX){
            cout << -1;
        }
    }
}