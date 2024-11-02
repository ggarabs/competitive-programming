#include <bits/stdc++.h>

using namespace std;

string s;

bool solve(int ind){
    return s[ind] == '1' && s[ind+1] == '1' && s[ind+2] == '0' && s[ind+3] == '0';
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> s;

        set <int> idx;

        for(int i = 0; i < s.size()-3; i++){
            if(solve(i)) idx.insert(i);
        }

        int q; cin >> q;

        for(int i = 0; i < q; i++){
            int ind, v; cin >> ind >> v;
            if(s[--ind] != '0'+v){
                for(int j = 0; j <= min(3, ind); j++) if(idx.count(ind-j)) idx.erase(ind-j);
                s[ind] = '0'+v;
                for(int j = 0; j <= min(3, ind); j++) if(solve(ind-j)) idx.insert(ind-j);
            }

            cout << (idx.empty() ? "NO" : "YES") << endl;
        }

    }
    return 0;
}