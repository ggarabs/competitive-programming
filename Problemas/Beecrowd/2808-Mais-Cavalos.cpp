#include <bits/stdc++.h>

using namespace std;

int main(){
	string pos[2];
	
	for(int i = 0; i < 2; i++) cin >> pos[i];

	for(int i = 0; i < 2; i++) pos[i][0] = pos[i][0] - 'a' + '1';

	int var_x[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int var_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

	for(int i = 0; i < 8; i++){
		char new_x = pos[0][0] + var_x[i], new_y = pos[0][1] + var_y[i];
		if(new_x < '1' || new_x > '8' || new_y < '1' || new_y > '8') continue;
		if(new_x == pos[1][0] && new_y == pos[1][1]){
			cout << "VALIDO" << endl;
			return 0;
		}
	}

	cout << "INVALIDO" << endl;

	return 0;
}
