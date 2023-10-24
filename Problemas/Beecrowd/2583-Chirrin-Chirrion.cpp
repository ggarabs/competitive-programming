#include <bits/stdc++.h>

using namespace std;

int main(){
	int c;
	cin >> c;

	for(int i = 0; i < c; i++){
		int n;
		cin >> n;
		set <string> obj;
		for(int j = 0; j < n; j++){
			string item, person;
			cin >> item >> person;
			if(person == "chirrin") obj.insert(item);
			else if(person == "chirrion" && obj.find(item) != obj.end()) obj.erase(item);
		}
		set<string>::iterator ptr = obj.begin();
		cout << "TOTAL" << endl;
		while(ptr != obj.end()){
			cout << *ptr << endl;
			ptr++;
		}
	}
	return 0;
}
