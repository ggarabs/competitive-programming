#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    vector <int> a(n, 0);
    for(int &x : a) cin >> x;

    for(int i = 2; i < n; i++){
        if(a[i] == a[i-1] && a[i-1] == a[i-2]){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}