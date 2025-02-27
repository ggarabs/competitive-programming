#include <bits/stdc++.h>

using namespace std;

string bin_transf(int x){
    string aux = "";
    while(x > 0){
        aux += (x%2)+'0';
        x /= 2;
    }
    return aux;
}

bool is_ok(int a, int b){
    string bina = bin_transf(a), binb = bin_transf(b);

    for(int i = 0; i < binb.size(); i++){
        if(binb[i] == '1' && bina[i] == '0') return false;
    }
    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;

        int orv = 0;

        vector <int> ans;

        int i = 0;
        for(; i < n-1; i++){
            int curr = orv | i;
            if(curr > x || !is_ok(x, i)) break;
            ans.push_back(i);
            orv |= i;
        }

        if(orv == x){
            if((orv | i) == x) ans.push_back(i);
        }else{
            if((orv | i) == x) ans.push_back(i);
            else ans.push_back(x);
        }

        if(ans.size() < n) ans.resize(n, 0);

        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}