#include <bits/stdc++.h>

using namespace std;

long long int pow2(int i){
    long long int aux = 1;
    for(int k = 0; k < i; k++) aux *= 2;
    return aux;
}

int main(){
    int n; cin >> n;

    vector <int> pot(35, 0);
    for(int i = 0; i < n; i++){
        int aux, j = 0; cin >> aux;
        while(aux > 0){
            pot[j++] += aux % 2;
            aux /= 2;
        }
    }

    vector <long long int> ans(n, 0);

    for(int i = 0; i < pot.size(); i++){
        for(int j = 0; j < pot[i]; j++){
            ans[j] += pow2(i);
        }
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}