#include <bits/stdc++.h>
#define INF 4000007

using namespace std;

struct piloto {
    int id;
    vector <int> prefix_sum;
};

int convert_to_int(string aux){
    int num = 0, ans = 0, cont = 0;
    for(int i = 0; i < aux.size(); i++){
        if(aux[i] == ':'){
            if(cont == 0) ans += num*60*1000;
            else if(cont == 1) ans += num*1000;
            num = 0;
            cont++;
        }else{
            num = 10*num + (aux[i]-'0');
        }
    }
    ans += num;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, v; cin >> n >> v;

    vector<piloto> Piloto;
    vector<pair<int, int>> better;
    vector<pair<int, int>> top_pilotos;

    int min_v = INF;
    for(int i = 0; i < n; i++){
        int pid; cin >> pid;
        vector <int> aux; aux.push_back(0);
        for(int j = 0; j < v; j++){
            string t; cin >> t;
            int intvalue = convert_to_int(t);
            aux.push_back(aux[j]+intvalue);
            if(intvalue < min_v){
                min_v = intvalue;
                better.clear();
                better.push_back({aux[j]+intvalue, pid});
            }else if(intvalue == min_v){
                better.push_back({aux[j]+intvalue, pid});
            }
            if(j == v-1) top_pilotos.push_back({aux[j]+intvalue, pid});
        }
        Piloto.push_back({pid, aux});
    }

    sort(top_pilotos.begin(), top_pilotos.end());

    if(better.size() <= 1){
        if(better.size()){
            for(int i = 0; i < 10; i++){
                if(top_pilotos[i].second == better[0].second){
                    cout << better[0].second << endl;
                    return 0;
                }
            }
        }
        cout << "NENHUM" << endl;
    }else{
        sort(better.begin(), better.end());
        cout << better[0].second << endl;
    }

    return 0;
}