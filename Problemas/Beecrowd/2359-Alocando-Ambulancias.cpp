#include <bits/stdc++.h>
#define MAXN 1007
#define INF 1007*1007*100

using namespace std;

int n, m, q;
vector <pair <int, int>> graph[MAXN];
int dist[MAXN];
bool vis[MAXN];
vector <int> hosp;

void djikstra(){
	for(int i = 0; i <= n; i++) dist[i] = INF;
	priority_queue<pair<int, int>, vector <pair <int, int>>, greater <pair<int, int>>> pq;
	for(int aux : hosp){
		dist[aux] = 0;
		pq.push({dist[aux], aux});
	}
	memset(vis, 0, sizeof(vis));

	while(!pq.empty()){
		pair<int, int> curr = pq.top();
		pq.pop();
		int davez = curr.second;

		if(vis[davez]) continue;
		vis[davez] = 1;

		for(int i = 0; i < graph[davez].size(); i++){
			pair<int, int> ngbr = graph[davez][i];
			if(dist[ngbr.second] > dist[davez] + ngbr.first){
				dist[ngbr.second] = dist[davez] + ngbr.first;
				pq.push({dist[ngbr.second], ngbr.second});
			}
		}
	}
}

int main(){
	while(scanf("%d %d %d", &n, &m, &q) != EOF){
		for(int i = 0; i < m; i++){
			int a, b, w; scanf("%d %d %d", &a, &b, &w);
			graph[a].push_back({w, b});
			graph[b].push_back({w, a});
		}

		for(int i = 0; i < q; i++){
			int x; scanf("%d", &x);
			hosp.push_back(x);
		}

		djikstra();

		int ans = 0;

		for(int i = 1; i <= n; i++) ans = max(ans, dist[i]);

		printf("%d\n", ans);

		for(int i = 0; i <= n; i++) graph[i].clear();
		hosp.clear();
	}
	return 0;
}
