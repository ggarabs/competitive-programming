#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k, maxv = 0; cin >> n >> k;

        string cells; cin >> cells;

        vector <int> pen(n, 0);
        for(int &a: pen){
            cin >> a;
            maxv = max(a, maxv);
        }

        int l = 0, r = maxv+1;

        while(l <= r){
            int ans = (l+r)/2;

            string seg = "R";

            for(int i = 0; i < cells.size(); i++){
                if(pen[i] > ans) seg += cells[i];
            }

            int min_k = 0;
            char last = 'R';
            for(char aux : seg){
                if(aux == 'B' && last == 'R') min_k++;
                last = aux;
            }

            if(min_k > k) l = ans+1;
            else r = ans-1;
        }

        cout << l << endl;
    }
    return 0;
}