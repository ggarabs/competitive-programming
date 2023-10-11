#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;

	for(int i = 1; i <= t; i++){
		int n, cap;
		cin >> n;

		for(int j = 0; j < n; j++){
			int aux;
			cin >> aux;
			if(j <= n/2) cap = aux;
		}

		cout << "Case " << i << ": " << cap << endl;
	}
	return 0;
}
