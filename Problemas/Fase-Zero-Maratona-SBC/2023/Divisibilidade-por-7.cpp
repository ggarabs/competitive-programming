#include <bits/stdc++.h>

using namespace std;

void solve(long long int x){
    cout << (long long int)x << endl;
    if(x < 10) return;
    solve(3*(x/10) + x%10);
}

int main(){
    long long int x;
    cin >> x;

    solve(x);

    return 0;
}