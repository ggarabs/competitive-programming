#include <bits/stdc++.h>
#define MAXN 107

using namespace std;

vector <int> graph[MAXN];
vector <int> graph1[MAXN];
double dist[MAXN];
bool vis[MAXN];

void DFS(int orig){
	vis[orig] = 1;
	for(int i = 0; i < graph1[orig].size(); i++){
		int ngbr = graph1[orig][i];
		if(!vis[ngbr]) DFS(ngbr);
	}
}

int main(){
	int n, a, b, c;
	while(cin >> n >> a >> b >> c){

		for(int i = 0; i < MAXN; i++) graph[i].clear();
		for(int i = 0; i < MAXN; i++) graph1[i].clear();

		for(int i = 0; i < n-1; i++){
			int x, y; cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		memset(dist, 0, sizeof(dist));

		stack <int> st;
		st.push(a);

		while(!st.empty()){
			int curr = st.top();
			st.pop();
			vis[curr] = 1;
			for(int i = 0; i < graph[curr].size(); i++){
				if(vis[graph[curr][i]]) continue;
				graph1[curr].push_back(graph[curr][i]);
				dist[graph[curr][i]] = dist[curr] + 1;
				st.push(graph[curr][i]);
			}
		}

		memset(vis, 0, sizeof(vis));

		DFS(b);

		cout.precision(6);
		cout.setf(ios::fixed);

		if(vis[b] && vis[c]){
			cout << 1.0 << endl;
			continue;
		}

		memset(vis, 0, sizeof(vis));

		DFS(c);

		if(vis[c] && vis[b]){
			cout << 0.0 << endl;
			continue;
		}

		cout << dist[c]/(dist[b] + dist[c]) << endl;


	}
	return 0;
}
