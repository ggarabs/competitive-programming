#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, r, g; cin >> a >> b >> r >> g;

    if(a >= 2*r && b >= 2*r && 360 % g == 0) cout << "S";
    else cout << "N" << endl;

    return 0;
}