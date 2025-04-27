#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    int value[4] = {8, 4, 2, 1};

    int mod = 0, i = 0;

    while(n > 0){
        if(n/value[i] > 0){
            mod++;
            n %= value[i];
        }
        i++;
    }

    cout << mod << endl;

    return 0;
}