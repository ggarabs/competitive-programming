#include <bits/stdc++.h>

using namespace std;

int main(){
    int num_aerop, voos;

    int iteracao = 0;

    while(cin >> num_aerop >> voos){

        iteracao++;

        if(num_aerop == 0 && voos == 0) return 0;

        vector <int> aerop;

        for(int i = 0; i <= num_aerop; i++){
            if(i == 0) aerop.push_back(-1);
            else aerop.push_back(0);
        }

        int grau_maximo = 0;

        for(int i = 0; i < voos; i++){
            int u, v;

            cin >> u >> v;

            aerop[u]++;
            aerop[v]++;

            if(max(aerop[u], aerop[v]) > grau_maximo) grau_maximo = max(aerop[u], aerop[v]);

        }

        cout << "Teste " << iteracao << endl;

        for(int i = 1; i <= num_aerop; i++){
            if(aerop[i] == grau_maximo){
                cout << i << " ";
            }
        }

        cout << endl << endl;
    }
    
    cout << endl;
}