#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int a, b; cin >> a >> b;
        if((2*a - b) % 3 != 0 || (2*b - a) % 3 != 0) cout << "NO" << endl;
        else if(2*min(a, b) - max(a, b) >= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}