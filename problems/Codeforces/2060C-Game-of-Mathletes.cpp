#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;

        vector <int> board(n, 0);
        map <int, int> qtd;
        for(int i = 0; i < n; i++){
            cin >> board[i];
            qtd[board[i]]++;
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(2*board[i] == k && qtd[board[i]] > 1){
                ans++;
                qtd[board[i]] -= 2;
            }else if(2*board[i] != k && qtd[board[i]] > 0 && qtd[k-board[i]] > 0){
                ans++;
                qtd[board[i]]--;
                qtd[k-board[i]]--;
            }
        }

        cout << ans << endl;
    }
    return 0;
}