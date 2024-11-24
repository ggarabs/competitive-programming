#include <bits/stdc++.h>

using namespace std;

int main(){
	queue <string> direction[4];
	map<int, int> hash;
	hash[-1] = 0; hash[-3] = 1;
	hash[-2] = 2; hash[-4] = 3;
	int sent[4] = {-1, -3, -2, -4};

	int t; cin >> t;
	int cont = 0;

	while(t != 0){
		string voo;
		while(cin >> voo && voo[0] == 'A'){
			direction[hash[t]].push(voo);
			cont++;
		}
		if(voo == "0") break;
		t = (-1)*(voo[1] - '0');
	}

	while(cont){
		for(int i = 0; i < 4; i++){
			if(!direction[hash[sent[i]]].empty()){
				cout << direction[hash[sent[i]]].front();
				if(cont != 1) cout << " ";
				direction[hash[sent[i]]].pop();
				cont--;
			}
		}
	}

	return 0;
}
