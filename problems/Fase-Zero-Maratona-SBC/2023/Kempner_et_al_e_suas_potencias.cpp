#include <bits/stdc++.h>
#define MAXN 220

using namespace std;

vector<pair<long long int, pair<int, int>>> pairs;

int potencia(int x){
    return x*x*x*x;
}

int binary_search(int ini, int fim, int x){
    int mid;
    while(ini <= fim){
        mid = (ini+fim)/2;
        if(pairs[mid].first < x) ini = mid+1;
        else fim = mid-1;
    }
    return ini;
}

int main(){
    int q; cin >> q;

    for(int i = 0; i < MAXN; i++){
        for(int j = i; j < MAXN; j++){
            if(potencia(i)+potencia(j) <= pow(2, 31)+1){
                pairs.push_back({potencia(i)+potencia(j), {i, j}});
            }
        }
    } 

    sort(pairs.begin(), pairs.end());

    while(q--){
        int n; cin >> n;

        vector<tuple<int, int, int, int>> solution;

        int cont = 0;

        for(int i = 0; i < pairs.size() && 2*pairs[i].first <= n; i++){
            long long int value = pairs[i].first, complement = n - value;
            int index = binary_search(0, pairs.size()-1, complement);

            while(index >= 0 && index < pairs.size() && pairs[index].first == complement){
                if(pairs[index].second.first >= pairs[i].second.second){
                    solution.push_back({pairs[i].second.first, pairs[i].second.second, pairs[index].second.first, pairs[index].second.second});
                    cont++;
                }
                index++;
            }
        }

        sort(solution.begin(), solution.end());

        cout << cont << endl;

        for(int i = 0; i < solution.size(); i++){
            cout << get<0>(solution[i]) << " " << get<1>(solution[i]) << " " << get<2>(solution[i]) << " " << get<3>(solution[i]) << endl;
        }

    }
}