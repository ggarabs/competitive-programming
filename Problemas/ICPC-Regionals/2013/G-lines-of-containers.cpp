#include <bits/stdc++.h>
#define MAXN 307

using namespace std;

int container[MAXN][MAXN];

int main(){
	int l, c;
	cin >> l >> c;

	for(int i = 0; i < l; i++) for(int j = 0; j < c; j++) cin >> container[i][j];

	for(int i = 0; i < l; i++){
		int v = container[i][0]/c;
		if(container[i][0]%c == 0) v--;
		for(int j = 0; j < c; j++){
			int atual = container[i][j]/c;
			if(container[i][j]%c == 0) atual--;
			if(atual != v){
				cout << '*' << endl;
				return 0;
			}
		}
	}

	for(int i = 0; i < c; i++)

	int aux[MAXN], v[MAXN];

	for(int i = 0; i < c; i++){
		aux[i] = container[0][i]%c;
		if(aux[i] == 0) aux[i] += c;
		v[aux[i]] = i+1;
	}

	int swaps = 0;

	for(int i = 0; i < c; i++){
		cout << aux[i] << " " << v[aux[i]] << endl;
		if(aux[i] != i+1){
			cout << "entrei" << endl;
			swap(aux[i], aux[v[i+1]-1]);
			swap(v[aux[i]], v[i+1]);
			swaps++;
		}
	}	
	
	cout << swaps << endl;

	for(int i = 0; i < l; i++){
		aux[i] = container[i][0]/c;
		if(container[i][0] % c == 0) aux[i]--;
		v[aux[i]] = i;
	}

	for(int i = 0; i < l; i++){
		cout << aux[i] << " " << v[aux[i]] << endl;
		if(aux[i] != v[aux[i]]){
			swap(aux[i], aux[v[aux[i]]]);
			swap(v[i], v[aux[i]]);
			swaps++;
		}
	}

	cout << swaps << endl;

	return 0;
}
