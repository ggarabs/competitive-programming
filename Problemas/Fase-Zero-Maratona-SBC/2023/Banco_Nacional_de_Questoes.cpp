#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;

    char esc;
    cin >> esc;

    if(esc == 'A') cout << (long long)floor(a + 3*b/2.0 + 5*c/2.0) << endl;
    else if(esc == 'B') cout << (long long)floor(b + 2*a/3.0 + 5*c/3.0) << endl;
    else cout << (long long)floor(2*a/5.0 + 3*b/5.0 + c) << endl;

    return 0;
}