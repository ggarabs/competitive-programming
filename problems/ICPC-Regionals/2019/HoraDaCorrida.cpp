#include <bits/stdc++.h>

using namespace std;

int main(){
    int v, n; cin >> v >> n;

    double total = v*n;

    for(int i = 1; i < 10; i++){
        cout << (long long)ceil(i*total/10) << " ";
    }

    cout << endl;

    return 0;
}