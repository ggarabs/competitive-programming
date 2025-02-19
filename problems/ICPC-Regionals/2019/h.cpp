#include <bits/stdc++.h>

using namespace std;

int main(){
    int v, n; cin >> v >> n;

    double total = v*n;

    cout.precision(0);
    cout.setf(ios::fixed);

    for(double i = 1; i <= 9; i++) cout << ceil(total*i/10.0) << " ";

    cout << endl;

    return 0;
}