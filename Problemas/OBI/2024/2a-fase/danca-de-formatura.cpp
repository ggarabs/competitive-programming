#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, p; cin >> n >> m >> p;

	vector <int> rows(n+1, 0), columns(m+1, 0);

	for(int i = 1; i <= n; i++) rows[i] = i;
	for(int j = 1; j <= m; j++) columns[j] = j;

	for(int i = 0; i < p; i++){
		char o; cin >> o;
		int x, y; cin >> x >> y;
		if(o == 'C') swap(columns[x], columns[y]);
		else swap(rows[x], rows[y]);
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << m*(rows[i]-1) + columns[j] << " ";
		}
		cout << endl;
	}

	return 0;
}
