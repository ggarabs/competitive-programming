#include <bits/stdc++.h>

using namespace std;

struct task{
	int chegada, duracao;
};

bool foo(task a, task b){
	if(a.chegada == b.chegada) return a.duracao > b.duracao;
	return a.chegada < b.chegada;
}

int main(){
	int n;
	while(cin >> n){
		vector <task> tasks(n);
		for(int i = 0; i < n; i++) cin >> tasks[i].chegada >> tasks[i].duracao;

		sort(tasks.begin(), tasks.end(), foo);

		int time = 1;
		for(int i = 0; i < n; i++){
			if(time < tasks[i].chegada) time = tasks[i].chegada;
			time += tasks[i].duracao;
		}

		cout << time << endl;

	}
	return 0;
}
