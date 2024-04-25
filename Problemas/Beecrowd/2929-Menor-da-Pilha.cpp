#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, v; cin >> n;
	stack <int> bag; map <int, int> values;
	string op;
	map<int, int>::iterator pt = values.end();

	for(int i = 0; i < n; i++){
		cin >> op;
		if(op == "PUSH"){
			cin >> v;
			bag.push(v); 
			if(values.find(v) != values.end()) values[v]++;
			else values[v] = 1;

			if(values.size() == 1 || (pt != values.end() && v < pt->first)) pt = values.begin();
		}else if(op == "POP"){
			if(!bag.empty() && --values[bag.top()] == 0) while(pt != values.end() && pt->second == 0) pt++;
			if(!bag.empty()) bag.pop();
		}else if(!values.empty()) cout << pt->first << endl;
	}
}
