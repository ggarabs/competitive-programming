#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector <int> list(n, 0);

    for(int i = 0; i < n; i++) cin >> list[i];

    long long int ans = 0;

    for(int i = 1; i < n; i++){
        if(list[i] < list[i-1]){
            ans += (list[i-1] - list[i]);
            list[i] = list[i-1];
        }
    }

    cout << ans << endl;

    return 0;
}