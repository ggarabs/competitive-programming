#include <bits/stdc++.h>

using namespace std;

int main(){
        int n; cin >> n;
        while(n--){
                int l; cin >> l;
                vector <int> vagoes(l, 0);

                for(int i = 0; i < l; i++) cin >> vagoes[i];

                int cont = 0;
                for(int i = 0; i < l; i++){
                        for(int j = 0; j < l-1; j++){
                                if(vagoes[j] > vagoes[j+1]){
                                        swap(vagoes[j], vagoes[j+1]);
                                        cont++;

                                }
                        }
                }

                cout << "Optimal train swapping takes " << cont << " swaps." << endl;
        }
        return 0;
}
