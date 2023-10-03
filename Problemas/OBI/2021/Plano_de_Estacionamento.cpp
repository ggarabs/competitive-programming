#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	set <int> vagas;

	for(int i = 1; i <= n; i++) vagas.insert(i);

	int ans = 0;

	for(int i = 0; i < m; i++){
		int v;
		cin >> v;

		set<int>::iterator pt = vagas.upper_bound(v);
		
		if(pt == vagas.begin()) break;
		pt--;

		vagas.erase(pt);
		ans++;
	}

	cout << ans << endl;

	return 0;
}
