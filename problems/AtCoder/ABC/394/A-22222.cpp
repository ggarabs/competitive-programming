#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;

    int cont = 0;
    for(char c : s) cont += (c == '2');

    while(cont--) cout << '2';
    cout << endl;

    return 0;
}