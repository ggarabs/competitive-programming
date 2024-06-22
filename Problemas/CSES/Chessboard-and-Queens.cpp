#include <bits/stdc++.h>
#define MAXN 8

using namespace std;

char board[MAXN][MAXN];

bool is_free(int x, int y, char board[MAXN][MAXN]){
    for(int i = 0; i < MAXN; i++) if(board[i][y] == 'Q' || board[x][i] == 'Q') return false;
    for(int i = x, j = y; i < MAXN && j < MAXN; i++, j++) if(board[i][j] == 'Q') return false;
    for(int i = x, j = y; i >= 0 && j >= 0; i--, j--) if(board[i][j] == 'Q') return false;
    for(int i = x, j = y; i >= 0 && j >= 0 && i < MAXN && j < MAXN; i++, j--) if(board[i][j] == 'Q') return false;
    for(int i = x, j = y; i >= 0 && j >= 0 && i < MAXN && j < MAXN; i--, j++) if(board[i][j] == 'Q') return false;
    return true;
}

int solve(char board[MAXN][MAXN], int row){
    if(row == MAXN) return 1;
    int ans = 0;
    for(int j = 0; j < MAXN; j++){
        if(board[row][j] == '.' && is_free(row, j, board)){
            char aux = board[row][j];
            board[row][j] = 'Q';
            ans += solve(board, row+1);
            board[row][j] = aux;
        }
    }

    return ans;
}

int main(){
    for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXN; j++) cin >> board[i][j];

    cout << solve(board, 0) << endl;

    return 0;
}