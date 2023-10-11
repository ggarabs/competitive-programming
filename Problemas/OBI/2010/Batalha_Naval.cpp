#include <bits/stdc++.h>
#define MAXN 107

using namespace std;

char tab[MAXN][MAXN];
int desl_x[] = {0, 0, 1, -1};
int desl_y[] = {1, -1, 0, 0};

bool DFS(int x, int y){
  tab[x][y] = 'v';
  bool ans = true;
  for(int i = 0; i < 4; i++){
    int new_x = x + desl_x[i], new_y = y + desl_y[i];
    if(tab[new_x][new_y] == '#') ans = false;
    else if(tab[new_x][new_y] == '@'){
      ans = min(ans, DFS(new_x, new_y));
    }
  }
  return ans;
}

int main(){
  int n, m;
  cin >> n >> m;

  memset(tab, ',', sizeof(tab));

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> tab[i][j];
    }
  }

  int k;
  cin >> k;

  for(int i = 0; i < k; i++){
    int x, y;
    cin >> x >> y;
    if(tab[x][y] == '#') tab[x][y] = '@';
  }

  int navios = 0;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(tab[i][j] == '@' && DFS(i, j)) navios++;
    }
  }

  cout << navios << endl;

  return 0;
}
