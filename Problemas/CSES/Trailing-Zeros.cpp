#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    int n_five = 0;

    for(int i = 5; i <= n; i *= 5) for(int j = 1; j*i <= n; j++) n_five++;

    cout << n_five << endl;

    return 0;
}