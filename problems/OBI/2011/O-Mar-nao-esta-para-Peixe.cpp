#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+7;

int main(){
    int n; cin >> n;

    vector <vector <bool>> mar(MAXN, vector<bool>(MAXN, false));

    int cont = 0;

    for(int i = 0; i < n; i++){
        int xi, xf, yi, yf; cin >> xi >> xf >> yi >> yf;

        for(int j = xi+1; j <= xf; j++) for(int k = yi+1; k <= yf; k++){
            if(!mar[j][k]) cont++;
            mar[j][k] = 1;
        }
    }

    cout << cont << endl;

    return 0;
}