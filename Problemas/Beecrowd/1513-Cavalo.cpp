#include <bits/stdc++.h>
#define MAXN 102
#define MAXP 17

using namespace std;

char tab[MAXN][MAXN];
int dist[MAXN][MAXN], dist_pc[MAXP+5][MAXP+5];
int dp[1 << MAXP][MAXP];
vector <pair<int, int>> p;

int desl_x[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int desl_y[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int n, m, k;

int tsp(int n){
	dp[1][0] = 0;

	int mask;

	for (mask = 1; mask < (1 << n); mask+=2) {
		for (int i = 0; i < n; i++) {
			if (!(mask & (1 << i))) continue;

			for (int j = 1; j < n; j++) {
				if (mask & (1 << j) || !dist_pc[i][j]) continue;

				dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dist_pc[i][j]);
			}
		}
	}

	int ans = 1e9;
	mask = (1 << n)-1;

	for(int i = 1; i < n; i++){
		dp[mask][i] += dist_pc[i][0];
		ans = min(ans, dp[mask][i]);
	}

	return ans;
}

bool in(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void BFS(int ind){
	vector <vector <bool>> vis(n+2, vector<bool>(m+2, false));
	memset(dist, 0, sizeof(dist));
	queue <pair<int, int>> q;

	pair <int, int> orig = p[ind];

	q.push({orig.first, orig.second});

	while(!q.empty()){
		pair<int, int> f = q.front();
		q.pop();

		vis[f.first][f.second] = 1;

		for(int i = 0; i < 8; i++){
			int new_x = f.first + desl_x[i], new_y = f.second + desl_y[i];
			if(!in(new_x, new_y) || tab[new_x][new_y] == '#') continue;
			if(!vis[new_x][new_y]){
				dist[new_x][new_y] = dist[f.first][f.second] + 1;
				vis[new_x][new_y] = 1;
				q.push(make_pair(new_x, new_y));
			}
		}
	}
}

int main(){
	while(cin >> n >> m >> k && n && m && k){
		fill(&dist_pc[0][0], &dist_pc[0][0] + (MAXP + 5) * (MAXP + 5), 1e9);
		fill(&dp[0][0], &dp[0][0] + (1 << MAXP) * (MAXP), 1e9);
		p.clear();

		map <pair<int, int>, int> hs;
		pair<int, int> c;
		int cont = 1;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
			cin >> tab[i][j];
			if(tab[i][j] == 'P'){
				p.push_back({i, j});
				hs[make_pair(i, j)] = cont++;
			}
			if(tab[i][j] == 'C'){
				c = {i, j};
				p.insert(p.begin(), c);
				hs[make_pair(i, j)] = 0;
			}
		}

		for(int k = 0; k < p.size(); k++){
			BFS(k);
			for(int i = 1; i < p.size(); i++){
				pair <int, int> curr = p[i];
				dist_pc[k][i] = dist[curr.first][curr.second];
				dist_pc[i][k] = dist[curr.first][curr.second];
			}
		}		

		cout << tsp(p.size()) << endl;
	}

	return 0;
}