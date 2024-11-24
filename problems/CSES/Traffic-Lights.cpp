#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

using namespace std;

int main(){ _
    int x, n; cin >> x >> n;

    set <int> lights;
    multiset <int> dist;

    lights.insert(0);
    lights.insert(x);
    dist.insert(x);

    for(int i = 0; i < n; i++){
        int p; cin >> p;

        auto sup = lights.upper_bound(p);
        int sup_v = *sup, inf_v = *(--sup);

        dist.erase(dist.find(sup_v - inf_v));
        lights.insert(p);
        dist.insert(sup_v-p);
        dist.insert(p-inf_v);

        cout << *(--dist.end()) << endl;
    }

    return 0;
}