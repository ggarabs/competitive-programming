#include <bits/stdc++.h>

using namespace std;

vector<string> solve(int ind){
    if(ind == 0) return {""};

    vector <string> next = solve(ind-1);
    int tam = (int)next.size();

    vector <string> sol(2*tam, "");

    for(int i = 0; i < tam; i++) sol[i] = "0" + next[i];
    for(int i = 0; i < tam; i++) sol[i+tam] = "1" + next[tam-1-i];

    return sol;
}

int main(){
    int n; cin >> n;

    vector <string> ans = solve(n);

    for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << endl;

    return 0;
}