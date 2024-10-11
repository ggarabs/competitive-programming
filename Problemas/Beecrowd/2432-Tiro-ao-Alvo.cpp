#include <bits/stdc++.h>
#define MAXN 100007
#define INF 9999999

using namespace std;

int raios[MAXN], c, t;

long long int dist(long long int x, long long int y){
  return x*x + y*y;
}

long long int busca_b(int x, int y){
  long long int ini = 0, fim = c, meio;

  while(ini <= fim){
    meio = (ini+fim)/2;

    if(dist(x, y) == dist(raios[meio], 0)) return meio;
    else if(dist(x, y) > dist(raios[meio], 0)) fim = meio-1;
    else ini = meio+1;
  }

  return ini-1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> c >> t;

  raios[0] = INF;
  for(int i = 0; i < c; i++){
    cin >> raios[c-i];
  }

  long long int pont = 0;

  for(int i = 0; i < t; i++){
    int x, y;
    cin >> x >> y;

    long long int parcial = busca_b(x,y);

    pont += parcial;
  }

  cout << pont << endl;

  return 0;
}
