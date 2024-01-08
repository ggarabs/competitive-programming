#include <bits/stdc++.h>
#define MAXN 300007

using namespace std;

struct point{
    int x, y;
    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    point operator+(const point &o){ return point(x+o.x, y+o.y); }
    point operator-(const point &o){ return point(x-o.x, y-o.y); }
    bool operator<(const point &o){
        if(x == o.x) return y < o.y;
        return x < o.x;
    }
    long long dot(const point &o){ return 1ll*x*o.x + 1ll*y*o.y; }
    long long cross(const point &o){ return 1ll*x*o.y - 1ll*y*o.x; }
};

point pts[MAXN];
int n;

vector <point> conv;

void makeconv(){
    sort(pts, pts+n);
    int it = 0;
    for(int i = 0; i < n; i++){
        while(it >= 2 && (conv[it-1]-conv[it-2]).cross(pts[i]-conv[it-2]) >= 0){
            conv.pop_back();
            it--;
        }
        conv.push_back(pts[i]);
        it++;
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

    makeconv();

    cout << conv.size()-1 << endl;

    return 0;
}