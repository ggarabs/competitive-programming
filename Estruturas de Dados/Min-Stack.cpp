#include <bits/stdc++.h>

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
    }

    void pop(){
        int erased;
        if(!s.empty()){
            erased = s.top().first;
            s.pop();
        }else cout << "EMPTY" << endl;
    }

    int minimum(){
        if(s.empty()) cout << "EMPTY" << endl;
        return s.top().second;
    }
};