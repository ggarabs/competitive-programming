#include <bits/stdc++.h>

using namespace std;

bool uppercase(char x){
	return x >= 'A' && x <= 'Z';
}

bool lowercase(char x){
	return x >= 'a' && x <= 'z';
}

bool number(char x){
	return x >= '0' && x <= '9';
}

bool invalid(char x){
	return !lowercase(x) && !uppercase(x) && !number(x);
}

int main(){
	string senha;
	while(getline(cin, senha)){
		bool hasLower = false, hasUpper = false, hasNumber = false, invalidChar = false;
		for(int i = 0; i < senha.size(); i++){
			if(invalid(senha[i])){
				invalidChar = true;
				break;
			}
			if(uppercase(senha[i])) hasUpper = true;
			if(lowercase(senha[i])) hasLower = true;
			if(number(senha[i])) hasNumber = true;
		}
		if(invalidChar || !hasLower || !hasUpper || !hasNumber || senha.size() < 6 || senha.size() > 32) cout << "Senha invalida." << endl;
		else cout << "Senha valida." << endl;
	}
	return 0;
}
