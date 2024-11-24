#include <bits/stdc++.h>

using namespace std;

bool subseq(string a, string b){
	for(int i = 0, j = 0; i < a.size(); i++){
		if(a[i] == b[j]) j++;
		if(j == b.size()) return true;
	}
	return false;
}

int main(){
	string t, p; cin >> t >> p;
	vector<int> index(t.size(), 0);
	for(int i = 0; i < index.size(); i++) cin >> index[i];

	int ini = 0, fim = index.size()-1;
	while(ini <= fim){
		int mid = (ini+fim)/2;
		vector<bool> aux(t.size(), 0);
		for(int i = 0; i <= mid; i++) aux[index[i]-1] = 1;
		string new_str = "";
		for(int i = 0; i < t.size(); i++) if(!aux[i]) new_str += t[i];

		if(!subseq(new_str, p)) fim = mid-1;
		else ini = mid+1; 
	}

	cout << fim+1 << endl;

	return 0;
}
