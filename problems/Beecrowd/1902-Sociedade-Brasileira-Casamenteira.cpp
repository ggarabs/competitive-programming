#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int main(){
	map <string, int> person;
	vector <string> names;
	vector<int> graph(MAXN, 0);
	vector<int> vis(MAXN, 0);

	string nome1, nome2;
	int count = 1;
	while(cin >> nome1 >> nome2){
		if(person.count(nome1) == 0){
			person[nome1] = count++;
			names.push_back(nome1);
		}
		if(person.count(nome2) == 0){
			person[nome2] = count++;
			names.push_back(nome2);
		}
		graph[person[nome1]] = person[nome2];
	}

	int ans = 0;

	for(int i = 1; i <= names.size(); i++){
		int ind = person[names[i-1]];
		if(vis[ind] == 0){
			while(ind){
				if(vis[ind] == i){
					ans++;
					break;
				}else if(vis[ind] < i && vis[ind] > 0) break;
				vis[ind] = i;
				ind = graph[ind];
			}
		}
	}

	cout << ans << endl;	

	return 0;
}
