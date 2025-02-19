#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    lli n; cin >> n;

    int bits = 0;
    while(n){
        bits += n % 2;
        n = n >> 1;
    }

    cout << (lli)pow(2, bits) << endl;

    return 0;
}