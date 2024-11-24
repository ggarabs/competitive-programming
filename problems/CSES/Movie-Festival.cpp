#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    vector <pair<int, int>> movies(n, {0, 0});
    for(int i = 0; i < n; i++) cin >> movies[i].second >> movies[i].first;

    sort(movies.begin(), movies.end());

    int cont = 0, time = 0;
    for(int i = 0; i < n; i++){
        if(movies[i].second >= time){
            time = movies[i].first;
            cont++;
        }
    }

    cout << cont << endl;

    return 0;
}