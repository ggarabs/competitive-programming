#include <bits/stdc++.h>

using namespace std;

pair <int, int> node[27];
string prefixo, infixo;
map <char, int> mp;

void posfixo(int x){
	if(x == 0) return;
	posfixo(node[x].first);
	posfixo(node[x].second);
	cout << infixo[x-1];
}

int main(){
	while(cin >> prefixo >> infixo){
		for(int i = 1; i <= infixo.size(); i++) mp[infixo[i-1]] = i;

		for(int i = 1; i <= 26; i++) node[i].first = node[i].second = 0;

		char root = prefixo[0];

		for(int i = 1; i < prefixo.size(); i++){
			char ins = prefixo[i];

			char curr = root;

			while(true){
				if(mp[ins] > mp[curr]){
					if(node[mp[curr]].second == 0){
						node[mp[curr]].second = mp[ins];
						break;
					}else curr = infixo[node[mp[curr]].second-1];	
				}else{
					if(node[mp[curr]].first == 0){
						node[mp[curr]].first = mp[ins];
						break;
					}else curr = infixo[node[mp[curr]].first-1];
				}
			}
		}

		posfixo(mp[prefixo[0]]);

		cout << endl;
	}

	return 0;
}
