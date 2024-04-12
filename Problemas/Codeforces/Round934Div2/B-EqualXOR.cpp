#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, k, aux; cin >> n >> k;

		vector <int> mark(n+1, 0);

		for(int i = 0; i < n; i++){
			cin >> aux;
			mark[aux]++;
		}

		for(int i = 0; i < n; i++) cin >> aux;
		vector <int> r, l;
		for(int i = 1; i <= n; i++){
			if(mark[i] == 2 && r.size() < 2*k){
				r.push_back(i);
				r.push_back(i);
			}
			if(mark[i] == 0 && l.size() < 2*k){
				l.push_back(i);
				l.push_back(i);
			}
		}
		int i = 1;
		while(i <= n && r.size() < 2*k){
			if(mark[i] == 1){
				r.push_back(i);
				l.push_back(i);
			}
			i++;
		}
		for(int i = 0; i < r.size(); i++) cout << r[i] << " ";
		cout << endl;
		for(int i = 0; i < l.size(); i++) cout << l[i] << " ";
		cout << endl;
	}
}
