#include <bits/stdc++.h>

const int INF = 1e6+7;

using namespace std;

int main(){
    int n; cin >> n;

    vector <vector <char>> pele(n+2, vector<char>(n+2, '#'));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> pele[i][j];

    for(int i = 1; i <= n; i++){
        bool mancha = false;
        int cont = 0;
        for(int j = 1; j <= n; j++){
            if(!mancha && pele[i][j] == '*'){
                mancha = true;
                cont++;
            }else if(mancha && pele[i][j] == '.') mancha = false;
        }
        if(cont > 1){
            cout << "N" << endl;
            return 0;
        }
    }

    for(int j = 1; j <= n; j++){
        bool mancha = false;
        int cont = 0;
        for(int i = 1; i <= n; i++){
            if(!mancha && pele[i][j] == '*'){
                mancha = true;
                cont++;
            }else if(mancha && pele[i][j] == '.') mancha = false;
        }
        if(cont > 1){
            cout << "N" << endl;
            return 0;
        }
    }

    cout << 'S' << endl;

    return 0;
}