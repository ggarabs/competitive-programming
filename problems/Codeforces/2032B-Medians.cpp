#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector <int> sol;

        if(n == 1){
            cout << 1 << endl << 1 << endl;
            continue;
        }

        int l = k-1, r = k+1;
        sol.push_back(k);
        if(r > n || l == 0){
            cout << -1 << endl;
            continue;
        }
        sol.push_back(r);
        while(l % 2 == 0 || (n-r) % 2 == 1){
            if(l == 0 || r == n+1){
                cout << -1 << endl;
                continue;
            }
            sol.push_back(l--);
            r++;
            if(r != k+1) sol.push_back(r);
        }

        sort(sol.begin(), sol.end());

        if(sol[0] != 1) sol.insert(sol.begin(), 1);

        cout << sol.size() << endl;
        for(int value : sol) cout << value << " ";
        cout << endl;

    }
}