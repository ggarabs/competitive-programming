#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int minv(int a, int b){
    return a > b ? b : a;
}

class MinStack {
public:
    stack<pair<int, int>> s;

    void push(int elem){
        int new_min = s.empty() ? elem : minv(elem, s.top().second);

        s.push({elem, new_min});
		return;
    }

    void pop(){
        if(!s.empty()) s.pop();
        else printf("EMPTY\n");
    }

    int minimum(){
        if(s.empty()){
			printf("EMPTY\n");
			return -1;
		}
        return s.top().second;
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	MinStack aux;

	int n; scanf("%d", &n);

	for(int i = 0; i < n; i++){
		char op[4]; scanf("%s", op);
		if(strcmp(op, "PUSH") == 0){
			int num; scanf("%d", &num);
			aux.push(num);
		}else if(strcmp(op, "MIN") == 0){
			int ans = aux.minimum();
			if(ans == -1) continue;
			else printf("%d\n", ans);
		}else aux.pop();
	}

	return 0;
}
