#include <bits/stdc++.h>
#define mod %
#define lli long long int

const int INF = 1e9+7;

using namespace std;

int main(){
    int n; cin >> n;

    while(n--){
        lli a, b; cin >> a >> b;

        lli ans = 1;

        while(b > 0){
            if(b & 1) ans = (ans * a) mod INF;
            b = b >> 1;
            a = (a * a) mod INF;
        }

        cout << ans << endl;
    }

    return 0;
}