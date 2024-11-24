#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f, MAXN = 100007;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct point{
    int ind, x, y;
    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    point operator+(const point &o) { return point(x + o.x, y + o.y); }
    point operator-(const point &o) { return point(x - o.x, y - o.y); }
    bool operator<(const point &o) const{
	return (x == o.x && y < o.y) || x < o.x;
    }
    bool operator==(const point &o) const{
	return x == o.x && y == o.y;
    }
    long long dot(const point &o) { return 1ll * x * o.x + 1ll * y * o.y; }
    long long cross(const point &o) { return 1ll * x * o.y - 1ll * y * o.x; }
};

vector<point> hull, lower, upper;
int n;
point polygon[MAXN];

void makeconv(){
    sort(polygon, polygon+n);
    int it1 = 0, it2 = 0;
    for (int i = 0; i < n; i++){
        while (it1 >= 2 && (upper[it1-1]-upper[it1-2]).cross(polygon[i]-upper[it1-2]) > 0){
            upper.pop_back();
            it1--;
        }
        upper.push_back(polygon[i]);
        it1++;
        while (it2 >= 2 && (lower[it2-1]-lower[it2-2]).cross(polygon[i]-lower[it2-2]) < 0){
            lower.pop_back();
            it2--;
        }
        lower.push_back(polygon[i]);
        it2++;
    }
    for (int i = it1-2; i >= 0; i--) hull.push_back(upper[i]);
    for (int i = 1; i < it2; i++) hull.push_back(lower[i]);
}


int main(){ _
	while(cin >> n && n){
		for(int i = 0; i < n; i++) cin >> polygon[i].x >> polygon[i].y;

		makeconv();

		set <point> pts;
		vector <point> ans;

		for(int i = 0; i < hull.size(); i++){
			if(pts.find(hull[i])==pts.end()){
				ans.pb(hull[i]);
				pts.insert(hull[i]);
			}
		}

		cout << ans.size() << endl;
		for(point p : ans) cout << p.x << " " << p.y << endl;

		hull.clear(); lower.clear(); upper.clear(); ans.clear();

	}

	exit(0);
}
