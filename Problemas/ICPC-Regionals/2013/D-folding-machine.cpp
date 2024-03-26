#include <bits/stdc++.h>

using namespace std;

int n, m;

vector <int> modify(vector <int> origin, int bar){
	int p1 = bar, p2 = bar+1;
	vector <int> aux;
	while(p1 >= 0 && p2 < origin.size()){
		aux.push_back(origin[p1]+origin[p2]);
		p1--;
		p2++;
	}
	for(; p2 < origin.size(); p2++) aux.push_back(origin[p2]);
	for(; p1 >= 0; p1--) aux.push_back(origin[p1]);
	return aux;
}

bool solve(vector <int> origin, vector <int> target){
	bool ans = false;
	if(origin.size() < target.size()) return false;
	if(origin.size() == target.size()){
		bool aux = true;
		for(int i = 0; i < origin.size(); i++){
			if(origin[i] != target[i]) aux = false;
		}
		if(aux) return true;
		aux = true;
		for(int i = origin.size()-1; i >= 0; i--){
			if(origin[i] != target[origin.size()-1-i]) aux = false;
		}
		return aux;
	}

	for(int i = 0; i < origin.size()-1; i++){
		vector <int> aux = modify(origin, i);
		ans |= solve(aux, target);
	}

	return ans;
}

int main(){
	cin >> n;

	vector <int> origin, target;

	for(int i = 0; i < n; i++){
		int v; cin >> v;
		origin.push_back(v);
	}

	cin >> m;

	for(int i = 0; i < m; i++){
		int v; cin >> v;
		target.push_back(v);
	}

	cout << (solve(origin, target) ? 'S' : 'N') << endl;

	return 0;

}
