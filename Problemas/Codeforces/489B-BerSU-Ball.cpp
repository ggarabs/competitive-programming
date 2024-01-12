#include <bits/stdc++.h>
#define MAXN 107

using namespace std;

int main(){
  int n, boys[MAXN], m, girls[MAXN];
  
  cin >> n;
  for(int i = 0; i < n; i++) cin >> boys[i];
  cin >> m;
  for(int i = 0; i < m; i++) cin >> girls[i];

  sort(boys, boys+n);
  sort(girls, girls+m);

  int bi = 0, gi = 0, ans = 0;
  while(bi < n && gi < m){
    if(abs(boys[bi]-girls[gi]) <= 1){
      bi++;
      gi++;
      ans++;
    }else if(boys[bi] > girls[gi]) gi++;
    else bi++;
  }

  cout << ans << endl;
    
  return 0;
}