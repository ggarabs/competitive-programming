#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e7+10;

int spf[maxn]; // vetor que guarda o menor fator (divisor) primo de um número

void crivo(){
    for(int i=2; i<maxn; i++){
        if(spf[i] == 0){ // se i não tem nenhum fator primo
            spf[i] = i;  // i é primo, logo o seu menor divisor é i
            for(int j=i+i; j<maxn; j+=i){
                if(spf[j] == 0) spf[j] = i; // se j é múltiplo de i e ainda não tem fator primo, i é o seu menor fator primo
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    crivo();
    for(int i=0; i<n; i++){
        int v, aux;
        cin >> v;
        while(v != 1){
            cout << spf[v] << " "; // imprimimos o spf do valor atual
            v /= spf[v];           // e dividimos o valor atual pelo seu spf                               
        }
        cout << "\n";                                                    
    }
}