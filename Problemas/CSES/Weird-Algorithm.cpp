#include <bits/stdc++.h>

using namespace std;

void solve(long long int x){
    cout << x << " ";
    if(x == 1) return;
    if(x % 2 == 0) solve(x/2);
    else solve(3*x+1);
}

int main(){
    long long int n; cin >> n;

    solve(n);
    cout << endl;

    return 0;
}