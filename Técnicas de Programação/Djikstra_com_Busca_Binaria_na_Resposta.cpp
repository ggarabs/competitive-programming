#include <bits/stdc++.h>
#define MAXN 100007
#define INF 100000000000007
#define pb push_back

using namespace std;

struct edge{
	int target;
	long long int height, cost;

	bool operator < (const edge &other) const {
		return cost <= other.cost;
	}

	bool operator > (const edge &other) const {
		return cost > other.cost;
	}
};

int n, m;
vector <edge> graph[MAXN];
long long int total_cost[MAXN], max_cost;
bool vis[MAXN];

int djikstra(long long int h){
	for(int i = 1; i <= n; i++){
		total_cost[i] = INF;
		vis[i] = false;
	}

	total_cost[1] = 0;
	priority_queue <edge, vector <edge>, greater <edge>> fila;

	fila.push({1, 0, 0});

	while(true){
		int atual = -1;

		while(!fila.empty()){
			int aux = fila.top().target;
			fila.pop();
			if(!vis[aux]){
				atual = aux;
				break;
			}
		}

		if(atual == -1) break;

		vis[atual] = true;

		for(int i = 0; i < graph[atual].size(); i++){
			int viz = graph[atual][i].target;
			long long int alt = graph[atual][i].height;
			long long int cust = graph[atual][i].cost;

			if(total_cost[viz] > total_cost[atual] + cust && alt <= h){
				total_cost[viz] = total_cost[atual] + cust;
				fila.push({viz, alt, cust});
			}
		}
	}

	if(total_cost[n] < max_cost) return 1;

	return 0;
}

int main(){

	cin >> n >> m >> max_cost;

	for(int i = 0; i < m; i++){
		int u, v;
		long long int h, c;
		cin >> u >> v >> h >> c;
		graph[u].pb({v, h, c});
		graph[v].pb({u, h, c});
	}

	if(djikstra(INF)==-1){
		cout << "Não há caminho para esse custo!" << endl;
		return 0;
	}

	long long int ini = 1, fim = INF;

	while(ini < fim){
		long long int meio = (ini+fim)/2;
		if(djikstra(meio)) fim = meio;
		else ini = meio + 1;
	}

	cout << fim << endl;

	return 0;
}
