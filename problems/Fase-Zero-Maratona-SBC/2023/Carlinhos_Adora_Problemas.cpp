#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long k, value;
    cin >> n >> k;

    for(int i = 2*n; i >= 1; i--){
        value = pow(i, 2);
        if(abs(value - k) % (2*n + 1) == 0 && value != k) break;
    }

    cout << value << endl;

    return 0;
}