#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	
	while(cin >> n && n){
		string nome, univ;
		unordered_map <string, int> ans;
		vector<string> aux;
		for(int i = 0; i < n; i++){
			cin >> nome >> univ;
			if(ans.find(univ) == ans.end()){
				ans[univ] = 1;
				aux.push_back(univ);
			}else ans[univ]++;
		}
		for(string s : aux) cout << s << " " << ans[s] << endl;
	}

	return 0;
}
