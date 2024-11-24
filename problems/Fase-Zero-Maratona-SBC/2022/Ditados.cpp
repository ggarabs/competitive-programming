#include <bits/stdc++.h>
#define MAXN 5

using namespace std;

int levenshtein(string orig, string tent){
    int dp[orig.size()+1][tent.size()+1];
    for(int i = 0; i <= orig.size(); i++) dp[i][0] = i;
    for(int i = 0; i <= tent.size(); i++) dp[0][i] = i;

    for(int i = 1; i <= orig.size(); i++){
        for(int j = 1; j <= tent.size(); j++){
            if(orig[i-1] == tent[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
        }
    }

    return dp[orig.size()][tent.size()];
}

int main(){
    int n; cin >> n;

    int pts[MAXN], pt_venc = 0;

    memset(pts, 0, sizeof(pts));

    for(int i = 0; i < n; i++){ 
        string ditado; cin >> ditado;
        vector <pair <int, int>> aux;
        for(int j = 0; j < 5; j++){
            string tent; cin >> tent;
            int dist = levenshtein(tent, ditado);
            aux.push_back({dist, j});
        }
        sort(aux.begin(), aux.end());
        int min_tam = aux[0].first;
        int pt = (min_tam == 0) ? 2 : 1;
        for(int j = 0; j < 5; j++){
            if(min_tam == aux[j].first){
                pts[aux[j].second] += pt;
                if(pts[aux[j].second] > pt_venc) pt_venc = pts[aux[j].second];
            }
            else break;
        }
    }

    cout.precision(1);
    cout.setf(ios::fixed);

    cout << (float)(pt_venc/(2.0)) << endl;

    vector <int> aux;

    for(int i = 0; i < 5; i++) if(pts[i] == pt_venc) aux.push_back(i+1);
    
    for(int i = 0; i < aux.size(); i++){
        cout << aux[i];
        if(i != aux.size()-1) cout << " ";
    }

    cout << endl;
    

    return 0;
}