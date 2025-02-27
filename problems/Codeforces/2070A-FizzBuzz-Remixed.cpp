#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        lli n; cin >> n;
        lli ans = ((n/15)+1)*3;

        if(n % 15 == 0) ans -= 2;
        else if(n % 15 == 1) ans -= 1;

        cout << ans << endl;
    }
    return 0;
}