#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vector <lli> aux(n+1, 0);
        for(int i = 1; i <= n; i++) cin >> aux[i];

        vector <lli> pref(n+1, 0),suf(n+2, 0);

        for(int i = 1; i <= n; i++) pref[i] = pref[i-1]+max(aux[i], (lli)(0));
        for(int i = n; i >= 1; i--) suf[i] = suf[i+1]+min(aux[i], (lli)(0));

        lli ans = 0;
        for(int i = 1; i <= n; i++) ans = max(ans, pref[i]-suf[i]);
        
        cout << ans << endl;
    }

    return 0;
}