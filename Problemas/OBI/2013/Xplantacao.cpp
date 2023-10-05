#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector <int> arvores;

    int atual = 0;

    for(int i = 0; i < n; i++){
        int frutos;
        cin >> frutos;
        arvores.push_back(frutos);
        atual += frutos;
    }

    int begin = 0, saldo = 0, ans = 0, mortas = 0;
    vector<int>::iterator pt = arvores.begin();

    sort(arvores.begin(), arvores.end());

    for(int i = 0; i < k; i++){
        char chuva;
        cin >> chuva;

        if(chuva == 'E') saldo--;
        else saldo++;

        if(saldo < 0){
            pt = upper_bound(arvores.begin(), arvores.end(), -1*saldo);
            atual -= (arvores.end() - pt);
            cout << atual << endl;
            ans -= (arvores.end() - pt);
        }else{
            atual += (arvores.end() - pt);
            cout << atual << endl;
            ans +=  (arvores.end() - pt);
        }

        cout << "resp =" << ans << endl;
    }

    cout << ans << endl;

    return 0;
}