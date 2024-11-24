#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector <int> list(n-1, 0);
    for(int i = 0; i < n-1; i++) cin >> list[i];

    sort(list.begin(), list.end());

    for(int i = 1; i <= n-1; i++){
        if(i != list[i-1]){
            cout << i << endl;
            return 0;
        }
    }

    cout << n << endl;

    return 0;
}