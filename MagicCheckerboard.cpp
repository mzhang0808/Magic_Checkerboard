#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long heightIsOne(vector<vector<long long>>& board);
long long widthIsOne(vector<vector<long long>>& board);
void assignTop(vector<vector<long long>>& board, long long r, long long c, long long& val);
void assignLeft(vector<vector<long long>>& board, long long r, long long c, long long& val);
long long findMinSumIfEvenEven(vector<vector<long long>> board);
long long findMinSumIfEvenOdd(vector<vector<long long>> board);
long long findMinSumIfOddEven(vector<vector<long long>> board);
long long findMinSumIfOddOdd(vector<vector<long long>>& board);

//If height is 1
long long heightIsOne(vector<vector<long long>>& board){
    long long s = 0;
    for(long long i=0;i<board[0].size();i++){
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
        }
        else{
            //Check that increasing property is still upheld
            if(i!=0 && board[0][i] <= board[0][i-1]){
                return -1;
            }
        }
        s+=board[0][i];
    }
    return s;
}

//If width is 1
long long widthIsOne(vector<vector<long long>>& board){
    long long s = 0;
    for(long long i=0;i<board.size();i++){
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
        }
        else{
            //Check that increasing property is upheld
            if(i!=0 && board[i][0] <= board[i-1][0]){
                return -1;
            }
        }
        s+=board[i][0];
    }
    return s;
}

//Finds value above current cell
void assignTop(vector<vector<long long>>& board, long long r, long long c, long long& val){
    if(r == 0){
        val = 0;
    }
    else{
        val = board[r-1][c];
    }
}

//Finds value to left of current cell
void assignLeft(vector<vector<long long>>& board, long long r, long long c, long long& val){
    if(c == 0){
        val = 0;
    }
    else{
        val = board[r][c-1];
    }
}

//Begins with Even Even {e.g. 2 4} --> columns must be same parity
long long findMinSumIfEvenEven(vector<vector<long long>> board){
    //cout << "findMinSumIfEvenEven" << endl;
    long long s = 0;
    long long t = 0;
    long long l = 0;
    for(long long i=0;i<board.size();i++){
        for(long long j=0;j<board[0].size();j++){
            assignTop(board, i, j, t);
            assignLeft(board, i, j, l);
            //Need to change value to minimum possible
            if(board[i][j] == 0){
                //to ensure that it stays in increasing order
                board[i][j] = max(t, l) + 1;
                if(board[i][j] % 2 != i%2){
                    board[i][j]++;
                }
            }
            //Rows must be same parity
            else if( i%2!=board[i][j]%2 
                || board[i][j] <= l || board[i][j] <= t){
                    return LLONG_MAX;
            }
            s += board[i][j];
            //cout << board[i][j] << " ";
        }
        //cout << endl;
    }
    return s;
}

long long findMinSumIfOddEven(vector<vector<long long>> board){
    //cout << "findMinSumIfOddEven" << endl;
    long long s = 0;
    long long t = 0;
    long long l = 0;
    for(long long i=0;i<board.size();i++){
        for(long long j=0;j<board[0].size();j++){
            assignTop(board, i, j, t);
            assignLeft(board, i, j, l);
            //Need to change value to minimum possible
            if(board[i][j] == 0){
                //to ensure that it stays in increasing order
                board[i][j] = max(t, l) + 1;
                if(board[i][j]%2 == j%2){
                    board[i][j]++;
                }
            }
            //Columns must be same parity, rows must alternate
            else if( j%2==board[i][j]%2 
                || board[i][j] <= l || board[i][j] <= t){
                    return LLONG_MAX;
            }
            s += board[i][j];
            //cout << board[i][j] << " ";
        }
        //cout << endl;
    }
    return s;
}

long long findMinSumIfEvenOdd(vector<vector<long long>> board){
    //cout << "findMinSumIfEvenOdd" << endl;
    long long s = 0;
    long long t = 0;
    long long l = 0;
    for(long long i=0;i<board.size();i++){
        for(long long j=0;j<board[0].size();j++){
            assignTop(board, i, j, t);
            assignLeft(board, i, j, l);
            //Need to change value to minimum possible
            if(board[i][j] == 0){
                //to ensure that it stays in increasing order
                board[i][j] = max(t, l) + 1;
                if(board[i][j] % 2 != j%2){
                    board[i][j]++;
                }
            }
            //Columns must be same parity, rows must alternate
            else if( j%2!=board[i][j]%2  
                || board[i][j] <= l || board[i][j] <= t){
                    return LLONG_MAX;
            }
            s += board[i][j];
            //cout << board[i][j] << " ";
        }
        //cout << endl;
    }
    return s;
}

long long findMinSumIfOddOdd(vector<vector<long long>>& board){
    //cout << "findMinSumIfOddOdd" << endl;
    if(board[0][0] == 0){
        board[0][0] = 1;
    }
    long long s = 0;
    long long t = 0;
    long long l = 0;
    for(long long i=0;i<board.size();i++){
        for(long long j=0;j<board[0].size();j++){
            assignTop(board, i, j, t);
            assignLeft(board, i, j, l);
            //Need to change value to minimum possible
            if(board[i][j] == 0){
                //to ensure that it stays in increasing order
                board[i][j] = max(t, l) + 1;
                if(board[i][j] % 2 == i%2){
                    board[i][j]++;
                }
            }
            //Rows must be same parity
            else if( i%2==board[i][j]%2  
                || board[i][j] <= l || board[i][j] <= t){
                    return LLONG_MAX;
            }
            s += board[i][j];
            //cout << board[i][j] << " ";
        }
        //cout << endl;
    }
    return s;
}

int main(){
    long long r = 0, c = 0;
    cin >> r >> c;
    vector<vector<long long>> board(r,vector<long long>(c));
    for(long long i=0;i<r;i++){
        for(long long j=0;j<c;j++){
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
        long long a = min(findMinSumIfEvenEven(board), findMinSumIfEvenOdd(board));
        long long b = min(findMinSumIfOddOdd(board), findMinSumIfOddEven(board));
        long long c = min(a, b);
        if(c == LLONG_MAX){
            cout << -1;
        }
        else{
            cout << c;
        }
    }
}