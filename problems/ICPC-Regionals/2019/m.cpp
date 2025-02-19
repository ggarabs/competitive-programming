#include <bits/stdc++.h>
#define lli long long int

const int INF = 2*1e9; 

using namespace std;

int main(){
    int n, c, t; cin >> n >> c >> t;

    vector <int> seq(n, 0);

    for(int i = 0; i < n; i++) cin >> seq[i];

    lli ini = 1, fim = 1e9;

    while(ini <= fim){
        lli i = (ini+fim)/2;

        lli total_time = i*t, workers = 0;

        lli acc = 0;
        for(int j = 0; j < seq.size(); j++){
            if(seq[j] > total_time){
                workers = INF;
                break;
            }
            if(acc + seq[j] <= total_time) acc += seq[j];
            else{
                acc = seq[j];
                workers++;
            }
        }
        if(acc > 0) workers++;

        if(workers <= c) fim = i-1;
        else ini = i+1;
    }

    cout << (lli)ini << endl;

    return 0;
}