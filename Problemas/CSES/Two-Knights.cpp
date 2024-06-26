#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int n; cin >> n;

    unsigned long long int ans;

    for(int i = 1; i <= n; i++){
        ans = i*i;
        ans *= (i*i-1);
        ans /= 2;
        ans -= 4*(i-1)*(i-2);
        cout << ans << endl;
    }

    return 0;
}