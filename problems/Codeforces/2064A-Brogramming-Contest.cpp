#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        char last = s[0];
        int moves = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == last) continue;
            else{
                moves++;
                last = s[i];
            }
        }

        if(s[0] == '1') moves++;

        cout << moves << endl;
    }
    return 0;
}