#include <bits/stdc++.h>

using namespace std;

int main(){
	int c;
	cin >> c;

	for(int i = 0; i < c; i++){
		string words[3];
		for(int j = 0; j < 3; j++) cin >> words[j];

		vector <int> ind;

		for(int j = 0; j < words[2].size(); j++){
			if(words[2][j] == '_') ind.push_back(j);
		}

		if(words[0][ind[0]] != words[1][ind[0]] && words[0][ind[1]] != words[1][ind[1]] && (words[0][ind[1]] == words[1][ind[0]] || words[1][ind[1]] == words[0][ind[0]])) cout << 'Y' << endl;
		else cout << 'N' << endl;
	}

	return 0;
}
