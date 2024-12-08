#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector <vector<int>> div(k, vector<int>());

        for(int i = 1; i <= n; i++){
            int aux; cin >> aux;
            div[aux%k].push_back(i);
        }

        bool solved = false;

        for(int i = 0; i < k; i++){
            if(div[i].size() == 1){
                cout << "YES" << endl;
                cout << div[i][0] << endl;
                solved = true;
                break;
            }
        }

        if(!solved) cout << "NO" << endl;
    }
    return 0;
}