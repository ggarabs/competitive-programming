#include <bits/stdc++.h>

using namespace std;

int main(){
    int my_vector[5] = {0, 1, 2, 3, 4};
    do {
        for(int i = 0; i < 5; i++) cout << my_vector[i];
        cout << endl;
    } while(next_permutation(my_vector, my_vector+5));

    return 0;
}