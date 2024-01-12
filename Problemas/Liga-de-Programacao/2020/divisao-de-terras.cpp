#include <bits/stdc++.h>
#define MAXN 100007
#define INF 1000000007

using namespace std;

struct Retangulo{
    int xa, ya, xb, yb;
};

int main(){
    int n, k;
    cin >> n >> k;

    Retangulo terra[MAXN];

    int ini = INF, fim = -INF;

    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        terra[i] = {x1, y1, x2, y2};
        ini = min(ini, y1);
        fim = max(fim, y2);
    }

    bool tem_solucao = false;

    while(ini <= fim){
        int meio = (ini+fim)/2;

        long long int area = 0;

        for(int i = 0; i < n; i++){
            if(terra[i].ya < meio){
                if(terra[i].yb >= meio){
                    area += abs(terra[i].xb - terra[i].xa)*(meio - terra[i].ya);
                }else{
                    area += abs(terra[i].xb - terra[i].xa)*(terra[i].yb - terra[i].ya);
                }
            }
        }

        if(area >= k){
            fim = meio-1;
            tem_solucao = true;
        }else if(area < k) ini = meio+1;
        else break;
    }

    if(tem_solucao) cout << ini << endl;
    else cout << "PERDAO MEU REI" << endl;

    return 0;
}