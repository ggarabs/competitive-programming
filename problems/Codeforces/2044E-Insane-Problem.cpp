#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        lli k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
        vector <lli> sols;
        lli ini = 1;
        while(ini <= r2/l1){
            if(ini < l2/r1){
                ini *= k;
                continue;
            }
            sols.push_back(ini);
            ini *= k;
        }

        lli ans = 0;
        for(int i = 0; i < sols.size(); i++){
            lli lb = max((lli)ceil((double)l2/sols[i]), l1);
            lli ub = min(r2/sols[i], r1);
            if(ub >= lb) ans += (ub - lb + 1);
        }

        cout << ans << endl;
    }
    return 0;
}