#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int n; cin >> n;

    vector <int> modulo(n, 0);
    lli sum = 0, ans = 0;
    modulo[0] = 1;

    for(int i = 1; i <= n; i++){
        int num; cin >> num;
        sum += num;
        if(sum < 0) sum = n - ((-sum) % n);
        ans += modulo[sum%n];
        modulo[sum%n]++;
    }

    cout << ans << endl;

    return 0;
}