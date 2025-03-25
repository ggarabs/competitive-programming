#include <bits/stdc++.h>

using namespace std;

int mergeSort(vector <int> &aux){
    if((int)aux.size() <= 1) return 0;
    int ans = 0;

    vector <int> v1, v2;
    int meio = (int)aux.size()/2;

    for(int i = 0; i < meio; i++) v1.push_back(aux[i]);
    for(int i = meio; i < aux.size(); i++) v2.push_back(aux[i]);

    ans += mergeSort(v1);
    ans += mergeSort(v2);

    int p1 = 0, p2 = 0, ind = 0;

    while(p1 < v1.size() && p2 < v2.size()){
        if(v1[p1] <= v2[p2]){
            aux[ind] = v1[p1];
            p1++;
        }else{
            aux[ind] = v2[p2];
            p2++;
            ans += v1.size()-p1;
        }
        ind++;
    }

    while(p1 < v1.size()){
        aux[ind] = v1[p1];
        p1++;
        ind++;
    }

    while(p2 < v2.size()){
        aux[ind] = v2[p2];
        p2++;
        ind++;
    }

    return ans;
}