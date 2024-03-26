#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

struct point{
    int ind, x, y;
    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    point operator+(const point &o) { return point(x + o.x, y + o.y); }
    point operator-(const point &o) { return point(x - o.x, y - o.y); }
    bool operator<(const point &o) {
        if (x == o.x) return y < o.y;
        return x < o.x;
    }
    long long dot(const point &o) { return 1ll * x * o.x + 1ll * y * o.y; }
    long long cross(const point &o) { return 1ll * x * o.y - 1ll * y * o.x; }
};

point pts[MAXN];
vector<point> hull, lower, upper;
int n;

void makeconv(){
    sort(pts, pts+n);
    int it1 = 0, it2 = 0;
    for (int i = 0; i < n; i++){
        while (it1 >= 2 && (upper[it1-1]-upper[it1-2]).cross(pts[i]-upper[it1-2]) > 0){
            upper.pop_back();
            it1--;
        }
        upper.push_back(pts[i]);
        it1++;
        while (it2 >= 2 && (lower[it2-1]-lower[it2-2]).cross(pts[i]-lower[it2-2]) < 0){
            lower.pop_back();
            it2--;
        }
        lower.push_back(pts[i]);
        it2++;
    }
    for (int i = 0; i < it1 - 1; i++) hull.push_back(upper[i]);
    for (int i = it2 - 1; i > 0; i--) hull.push_back(lower[i]);
}

bool comp(point a, point b){
    return a.ind < b.ind;
}

int main(){
    cin >> n;

    for (int i = 0; i < n; i++){
        pts[i].ind = i+1;
        cin >> pts[i].x >> pts[i].y;
    }

    makeconv();

    sort(hull.begin(), hull.end(), comp);

    set <int> vtx;

    for(int i = 0; i < hull.size(); i++) if(vtx.find(hull[i].ind) == vtx.end()) vtx.insert(hull[i].ind);

    for(set<int>::iterator ptr = vtx.begin(); ptr != vtx.end(); ptr++) cout << *ptr << " ";
    cout << endl;

    return 0;
}