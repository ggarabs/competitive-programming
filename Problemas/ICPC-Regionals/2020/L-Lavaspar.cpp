#include <bits/stdc++.h>
#define MAXL 47
#define MAXP 17

using namespace std;

char matrix[MAXL][MAXL];
set <int> mark[MAXL][MAXL];

bool match(string test, int x, int y, int mode){
	map <char, int> table;
	map <char, int> aux;

	for(int i = 0; i < test.size(); i++){
		if(table.find(test[i]) != table.end()) table[test[i]]++;
		else table[test[i]] = 1;
		aux[test[i]] = 0;
	}

	for(int i = 0; i < test.size(); i++){
		char c;
		if(mode == 0) c = matrix[x][y+i];
		else if(mode == 1) c = matrix[x+i][y];
		else if(mode == 2) c = matrix[x+i][y+i];
		else c = matrix[x+i][y-i];

		if(table.find(c) != table.end()) aux[c]++;
		else return false;
	}

	for(char c: test) if(aux[c] != table[c]) return false;

	return true;
}

void complete(int x, int y, int size, int mode, int ind){
	for(int i = 0; i < size; i++){
		if(mode == 0) mark[x][y+i].insert(ind);
		else if(mode == 1) mark[x+i][y].insert(ind);
		else if(mode == 2) mark[x+i][y+i].insert(ind);
		else mark[x+i][y-i].insert(ind);
	}
}

int main(){
	int l, c; cin >> l >> c;

	for(int i = 0; i < l; i++) for(int j = 0; j < c; j++) cin >> matrix[i][j];

	int p; cin >> p;

	vector <string> words(p);

	for(int i = 0; i < p; i++) cin >> words[i];

	for(int i = 0; i < p; i++){
		int len = (int)words[i].size();

		for(int j = 0; j < l; j++){
			for(int k = 0; k <= c-len; k++){
				if(match(words[i], j, k, 0)) complete(j, k, len, 0, i);
			}
		}

		for(int j = 0; j <= l-len; j++){
			for(int k = 0; k < c; k++){
				if(match(words[i], j, k, 1)) complete(j, k, len, 1, i);
			}
		}

		for(int j = 0; j <= l-len; j++){
			for(int k = 0; k <= c-len; k++){
				if(match(words[i], j, k, 2)) complete(j, k, len, 2, i);
			}
		}

		for(int j = 0; j <= l-len; j++){
			for(int k = len-1; k < c; k++){
				if(match(words[i], j, k, 3)) complete(j, k, len, 3, i);
			}
		}
	}

	int ans = 0;

	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			if(mark[i][j].size() > 1) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
