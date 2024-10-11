#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector <int> copos(3, 0);
	char copo; cin >> copo;
	copos[copo-'A']++;
	
	for(int i = 0; i < n; i++){
		int op; cin >> op;
		if(op == 1) swap(copos[0], copos[1]);
		else if(op == 2) swap(copos[1], copos[2]);
		else swap(copos[0], copos[2]);
	}

	for(int i = 0; i < 3; i++) if(copos[i]) cout << (char)('A'+i) << endl;

	return 0;
}
