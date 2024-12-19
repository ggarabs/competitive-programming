#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int l = 1, r = n;
        for(int i = 1; i <= n; i++){
            if(i % k == 0){
                cout << l++ << " ";
            }else{
                cout << r-- << " ";
            }
        }
        cout << endl;
    }
    return 0;
}