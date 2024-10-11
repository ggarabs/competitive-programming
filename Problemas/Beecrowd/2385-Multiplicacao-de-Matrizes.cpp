#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int main(){
  int n, p, q, r, s, x, y, i, j;
  cin >> n;

  cin >> p >> q >> r >> s >> x >> y >> i >> j;

  int a[MAXN], b[MAXN];

  for(int k = 1; k <= n; k++){
    a[k] = (p*i + q*k)%x;
    b[k] = (r*k + s*j)%y;
  }

  long long int prod = 0;

  for(int k = 1; k <= n; k++){
    prod += a[k]*b[k];
  }

  cout << prod << endl;

  return 0;
  
}
