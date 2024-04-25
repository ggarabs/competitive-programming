#include <bits/stdc++.h>

using namespace std;

int main(){
	string name, decision;
	set<string> names_ac, names_rf; int max_value = 0; string habay_friend = "";
	while(cin >> name && name != "FIM"){
		cin >> decision;
		if(decision == "YES"){
			names_ac.insert(name);
			if(name.size() > max_value){
				max_value = name.size();
				habay_friend = name;
			}
		}else names_rf.insert(name);
	}

	for(set<string>::iterator pt = names_ac.begin(); pt != names_ac.end(); pt++) cout << *pt << endl;
	for(set<string>::iterator pt = names_rf.begin(); pt != names_rf.end(); pt++) cout << *pt << endl;

	cout << endl << "Amigo do Habay:" << endl << habay_friend << endl;

	return 0;
}
