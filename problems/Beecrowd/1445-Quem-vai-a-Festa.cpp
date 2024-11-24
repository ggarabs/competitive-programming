#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

vector <int> graph[MAXN];
bool vis[MAXN];

int convert(string x){
	int lim = x.size()-1, factor = 1, ans = 0;
	for(lim; lim >= 0; lim--, factor *= 10){
		ans += (x[lim]-'0')*factor;
	}
	return ans;
}

int DFS(int x){
	vis[x] = 1;
	int cont = 1;
	for(int i = 0; i < graph[x].size(); i++){
		int ngbr = graph[x][i];
		if(!vis[ngbr]){
			vis[ngbr] = 1;
			cont += DFS(ngbr);	
		}
	}

	return cont;
}

int main(){
	int n;
	while(cin >> n && n){
		for(int i = 0; i < n; i++){
			string aux; cin >> aux;
			string a = "", b = "";

			int cont = 1;
			while(aux[cont] != ',') a += aux[cont++];

			cont++;
			while(aux[cont] != ')') b += aux[cont++];

			graph[convert(a)].push_back(convert(b));
			graph[convert(b)].push_back(convert(a));
		}

		cout << DFS(1) << endl;

		for(int i = 0; i < MAXN; i++) graph[i].clear();
		memset(vis, 0, sizeof(vis));

	}

	return 0;
}
