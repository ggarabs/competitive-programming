#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, x; lli k;
        cin >> n >> x >> k;
        
        string moves; cin >> moves;

        lli ans = 0, i;
        int curr = x;
        bool sol = false;

        for(i = 1; i <= n; i++){
            if(moves[i-1] == 'L') curr--;
            else curr++;

            if(curr == 0){
                ans = 1;
                sol = true;
                break;
            }
        }

        lli tempo = i;

        if(!sol){
            cout << 0 << endl;
            continue;
        }

        curr = 0;
        sol = false;
        for(i = 1; i <= n; i++){
            if(moves[i-1] == 'L') curr--;
            else curr++;

            if(curr == 0){
                sol = true;
                break;
            }
        }

        if(!sol){
            cout << ans << endl;
            continue;
        }

        if(sol) ans += ((k-tempo)/i);

        cout << ans << endl;
    }
    return 0;
}