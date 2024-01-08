#include <bits/stdc++.h>

using namespace std;

int tab[11][11];

bool on_table(int x, int y){
    return x >= 1 && x <= 10 && y >= 1 && y <= 10;
}

int main(){
    int n;
    cin >> n;

    bool ans = true;

    for(int i = 0; i < n; i++){
        int d, l, r, c;
        cin >> d >> l >> r >> c;

        if(d == 0){
            for(int j = 0; j < l; j++){
                if(!on_table(r,c+j)){
                    ans = false;
                    break;
                }
                tab[r][c+j]++;
                if(tab[r][c+j] > 1){
                    ans = false;
                    break;
                }
            }
        }else{
            for(int j = 0; j < l; j++){
                if(!on_table(r+j,c)){
                    ans = false;
                    break;
                }
                tab[r+j][c]++;
                if(tab[r+j][c] > 1){
                    ans = false;
                    break;
                }
            }
        }

        if(!ans) break;

    }

    cout << (ans?'Y':'N') << endl;

    return 0;
}