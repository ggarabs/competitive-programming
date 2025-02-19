#include <bits/stdc++.h>
     
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> x;
        for(int i = 0; i < n-2; i++){
            int aux; cin >> aux;
            x.push_back(aux);
        }
        bool solved = true;
        for(int i = 1; i < x.size()-1; i++){
            if(x[i] == 0 && x[i-1] == 1 && x[i+1] == 1){
                cout << "NO" << endl;
                solved = false;
                break;
            }
        }
        if(solved) cout << "YES" << endl;
    }
    return 0;
}