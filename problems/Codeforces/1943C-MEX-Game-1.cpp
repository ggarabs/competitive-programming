#include <bits/stdc++.h>
     
using namespace std;
     
int main(){
    	int t; cin >> t;
    	while(t--){
    		int n; cin >> n;
    		map<int, int> mp;
    		for(int i = 0; i < n; i++){
    			int aux; cin >> aux;
    			mp[aux]++;
    		}
     
    		int cont = 0;
		for(int mex = 0; mex <= n; mex++){
			if(mp[mex] == 0){
				cout << mex << endl;
				break;
			}else if(mp[mex] == 1){
				cont++;
				if(cont == 2){
					cout << mex << endl;
					break;
				}
			}
		}
    	}
	return 0;
}
