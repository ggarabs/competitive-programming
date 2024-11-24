#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l, d;
    cin >> n >> l >> d;

    cout << ceil(n*d/double(l*1000))*l << endl;

    return 0;

}