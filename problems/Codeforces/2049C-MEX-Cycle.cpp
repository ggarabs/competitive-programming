#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, x, y; cin >> n >> x >> y;

        vector <int> sol(n+1, 0);
        if(y < x) swap(x, y);

        int curr = 0;
        for(int i = 0; i < n; i++){
            sol[(i+x)%n] = curr;
            curr = (curr+1)%2;
        }

        if(n % 2 || (x-y) % 2 == 0) sol[x%n] = 2;

        for(int i = 1; i <= n; i++) cout << sol[i%n] << " ";
        cout << endl;

    }
    return 0;
}