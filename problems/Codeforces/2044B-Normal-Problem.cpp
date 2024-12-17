#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string a; cin >> a;
        for(int i = 0; i < a.size(); i++) a[i] == 'p' ? a[i] = 'q' : (a[i] == 'q' ? a[i] = 'p' : a[i]);
        reverse(a.begin(), a.end());
        cout << a << endl;
    }
}