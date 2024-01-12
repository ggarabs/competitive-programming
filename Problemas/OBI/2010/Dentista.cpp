#include <bits/stdc++.h>

using namespace std;

struct consulta{
    int chegada, saida;
};

int func(consulta x1, consulta x2){
    return x1.saida < x2.saida;
}

int main(){
    int total_cons;
    consulta vetor[10007];

    cin >> total_cons;

    for(int i = 0; i < total_cons; i++){
        int chegada, saida;

        cin >> vetor[i].chegada >> vetor[i].saida;
    }

    sort(vetor, vetor+total_cons, func);

    int tempo = 0, ans = 0;

    for(int i = 0; i < total_cons; i++){
        if(vetor[i].chegada >= tempo){
            tempo = vetor[i].saida;
            ans++;
        }
    }

    cout << ans;

    return 0;

}