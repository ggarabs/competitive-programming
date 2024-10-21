#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> a, b;
        for(int i = 0; i < n; i++){
            int aux; cin >> aux;
            a.push_back(aux);
        }
        for(int i = 0; i < n; i++){
            int aux; cin >> aux;
            b.push_back(aux);
        }

        int i = 0, j = 0, cont = 0;

        while(i < n && j < n){
            if(a[i] > b[j]) cont++;
            else i++;
            j++;
        }

        cout << cont << endl;

    }
    return 0;
}