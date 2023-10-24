#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	bool ini = true;
	while(cin >> n){
		getchar();
		if(n == 0) break;
		if(!ini) cout << endl;
		ini = false;
		vector <string> text, new_text;
		for(int i = 0; i < n; i++){
			string sentence;
			getline(cin, sentence);
			text.push_back(sentence+' ');
		}
		for(int i = 0; i < n; i++){
			string aux = "", atual = "";
			for(int j = 0; j < text[i].size(); j++){
				if(text[i][j] != ' ') atual += text[i][j];
				else{
					if(aux != "" && atual != "") aux += ' ';
					aux += atual;
					atual = "";
				}
			}
			new_text.push_back(aux);
		}
		int tam = (int)new_text[0].size();
		for(int i = 1; i < n; i++) tam = max(tam, (int)new_text[i].size());
		for(int i = 0; i < n; i++){
			for(int j = 0; j < tam - new_text[i].size(); j++) cout << " ";
			cout << new_text[i] << endl;
		}
	}
	return 0;
}
