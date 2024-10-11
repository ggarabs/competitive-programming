#include <bits/stdc++.h>

using namespace std;

int rafael(int x, int y){
	return 9*pow(x,2) + pow(y,2);
}

int beto(int x, int y){
	return 2*pow(x,2) + 25*pow(y,2);
}

int carlos(int x, int y){
	return -100*x + pow(y,3);
}

int main(){
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;

		if(beto(x,y) > carlos(x,y) && beto(x,y) > rafael(x,y)){
			cout << "Beto ganhou" << endl;
		}else if(carlos(x,y) > beto(x,y) && carlos(x,y) > rafael(x,y)){
			cout << "Carlos ganhou" << endl;
		}else cout << "Rafael ganhou" << endl;
	}

	return 0;
}
