#include <bits/stdc++.h>
#define MAXN 57
#define MAXM 1000007

using namespace std;

long long int ans[MAXN];
int pq[MAXM], cont;
vector <long long int> topos;

void solve(long long int ini, int h){
	if(h == 51) return;
	if(topos.size() < h) topos.push_back(ini);
	ini++;

	while(true){
		bool enter = false;
		for(int i = 0; i < (int)topos.size(); i++){
			if(pq[ini+topos[i]] == 1){
				topos[i] = ini;
				enter = true;
				break;
			}
		}
		if(!enter) break;
		ini++;
	}

	ans[topos.size()] = ini-1;

	solve(ini, h+1);
}

int main(){
	for(int i = 1; i*i <= MAXM; i++) pq[i*i] = 1;

	solve(1, 0);
	ans[1] = 1;

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int value;
		cin >> value;
		cout << ans[value] << endl;
	}

	return 0;
}
