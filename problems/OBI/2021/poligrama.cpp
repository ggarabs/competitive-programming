#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    string poligram; cin >> poligram;

    vector <int> divisors;

    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            divisors.push_back(i);
            divisors.push_back(n/i);
        }
    }

    sort(divisors.begin(), divisors.end());

    for(int tam : divisors){
        bool has_sol = true;
        vector <int> letters(30, 0);
        for(int i = 0; i < n/tam; i++){
            if(i == 0){
                for(int j = 0; j < tam; j++) letters[poligram[j]-'a']++;
                continue;
            }
            vector <int> aux(30, 0);
            for(int j = tam*i; j < tam*(i+1); j++) aux[poligram[j]-'a']++;
            for(int i = 0; i < 30; i++){
                if(aux[i] != letters[i]){
                    has_sol = false;
                    break;
                }
            }
        }
        if(has_sol){
            cout << poligram.substr(0, tam) << endl;
            return 0;
        }
    }

    cout << "*" << endl;

    return 0;
}