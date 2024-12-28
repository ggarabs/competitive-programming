#include <bits/stdc++.h>
#define lli long long int

using namespace std;

lli log(lli x){
    lli i = 1, cont = 0;
    while(i <= x){ i *= 4, cont++; }
    return cont-1;
}

lli solve(lli x){
    lli ans = 1, cont = 1;
    while(cont <= x){
        ans *= 2;
        cont++;
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        lli n; cin >> n;

        cout << solve(log(n)) << endl;
    }
}