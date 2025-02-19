#include <bits/stdc++.h>
#define MAXN 307

using namespace std;

int container[MAXN][MAXN];

int main(){
	int l, c;
	cin >> l >> c;

	for(int i = 0; i < l; i++) for(int j = 0; j < c; j++) cin >> container[i][j];

	for(int i = 0; i < l; i++){
		int id_line = container[i][0]/c;
		if(container[i][0] % c == 0) id_line--;

		for(int j = 1; j < c; j++){
			int id = container[i][j]/c;
			if(container[i][j] % c == 0) id--;

			if(id_line != id){
				cout << "*" << endl;
				return 0;
			}
		}
	}

	for(int i = 0; i < c; i++){
		for(int j = 1; j < l; j++){
			if((container[0][i] % c) != (container[j][i] % c)){
				cout << "*" << endl;
				return 0;
			}
		}
	}

	int swaps = 0;

	vector <pair<int, int>> first_line(c, {0, 0});
	for(int i = 0; i < c; i++) first_line[i] = {container[0][i], i};
	sort(first_line.begin(), first_line.end());

	for(int i = 0; i < c; i++){
		for(int i = 0; i < c; i++){
			int pos = first_line[i].second;
			if(pos != i){
				swap(first_line[i].second, first_line[pos].second);
				swaps++;
			}
		}
	}

	vector <pair<int, int>> first_column(l, {0, 0});
	for(int i = 0; i < l; i++) first_column[i] = {container[i][0], i};
	sort(first_column.begin(), first_column.end());

	for(int i = 0; i < l; i++){
		for(int i = 0; i < l; i++){
			int pos = first_column[i].second;
			if(pos != i){
				swap(first_column[i].second, first_column[pos].second);
				swaps++;
			}
		}	
	}

	cout << swaps << endl;

	return 0;
}
