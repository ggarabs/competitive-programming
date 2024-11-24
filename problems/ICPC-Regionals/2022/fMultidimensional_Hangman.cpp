#include <bits/stdc++.h>
#define MAXN 10007

using namespace std;

int main(){
    int n, c;
    cin >> n >> c;

    string word[MAXN], aux[MAXN];

    for(int i = 0; i < n; i++){
        cin >> word[i];
        aux[i] = word[i];
    }

    int ans = 0, parc = 0;
    string c_word = "";

    for(int i = 0; i < n; i++){
        int x_letter = -1;
        for(int m = 0; m < c; m++) if(aux[i][m] == '*') x_letter = m;

        for(char k = 'a'; k <= 'z'; k++){
            aux[i][x_letter] = k;

            parc = 0;

            for(int j = 0; j < n; j++){
                bool comp = true;
                for(int l = 0; l < c; l++){
                    if(aux[i][l] != word[j][l] && word[j][l] != '*'){
                        comp = false;
                        break;
                    }
                }
                if(comp) parc++;
            }

            if(parc == ans){
                if(aux[i] < c_word || c_word == "") c_word = aux[i];
            }else if(parc > ans){
                ans = parc;
                c_word = aux[i];
            }
        }
    }

    cout << c_word << " " << ans << endl;

    return 0;
}