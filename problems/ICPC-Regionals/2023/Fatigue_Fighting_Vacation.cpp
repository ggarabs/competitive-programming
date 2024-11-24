#include <bits/stdc++.h>
#define MAXN 10007

using namespace std;

int main(){
    long long d, c, r, ans = 0;
    cin >> d >> c >> r;

    int tiring[MAXN];

    for(int i = 0; i < c; i++) cin >> tiring[i];
    for(int i = 0; i < r; i++){
        int x;
        cin >> x;
        d += x;
    }

    int i = 0;
    while(d > 0 && i < c && d >= tiring[i]){
        d -= tiring[i];
        ans++;
        i++;
    }

    cout << ans+r << endl;

    return 0;
}