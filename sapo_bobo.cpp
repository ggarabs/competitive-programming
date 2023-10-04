#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

int mdc(int a, int b){
    if(b > a) swap(a, b);
    if(b == 0) return a;
    return mdc(b, a%b);
}

int main(){
    int n_tabuas, compr_tabua[MAXN], n_tabua[MAXN];
    cout << "Digite o número de tábuas diferentes: ";
    cin >> n_tabuas;

    for(int i = 1; i <= n_tabuas; i++){
        cout << "TÁBUA " << i << endl;
        cout << "Digite a quantidade de tábuas desse tipo: ";
        cin >> n_tabua[i];
        cout << "Digite o comprimento da tábua: ";
        cin >> compr_tabua[i];
    }

    int div = compr_tabua[1], ans = 0;

    for(int i = 1; i <= n_tabuas; i++) div = mdc(div, compr_tabua[i]);

    int value = 2;
    while(div >= 200){
        if(div % 2 == 0) div /= 2;
        else value++;
    }

    for(int i = 1; i <= n_tabuas; i++){
        ans += n_tabua[i]*compr_tabua[i]/div;
    }

    cout << "O número de novas peças de maior tamanho possível é " << ans << endl;

    return 0;
}