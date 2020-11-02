#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int find_max(const set<pii> &s) {
	set<pii> :: iterator it = s.end(); it --;
	return it -> first;
}

int find_min(const set<pii> &s) {
	return s.begin() -> first;
}

set<pii> sx,sy,ex,ey;

struct haha {
	pii s,e;
}a[SZ];

int main() {
	int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i].s.first = read();
        a[i].s.second = read();
        a[i].e.first = read();
        a[i].e.second = read();
        sx.insert(make_pair(a[i].s.first,i));
        sy.insert(make_pair(a[i].s.second,i));
        ex.insert(make_pair(a[i].e.first,i));
        ey.insert(make_pair(a[i].e.second,i));
    }
    for(int i = 1;i <= n;i ++) {
        int x1 = a[i].s.first;
        int y1 = a[i].s.second;
        int x2 = a[i].e.first;
        int y2 = a[i].e.second;
        sx.erase(make_pair(x1,i));
        sy.erase(make_pair(y1,i));
        ex.erase(make_pair(x2,i));
        ey.erase(make_pair(y2,i));
        int minx = find_max(sx);
        int miny = find_max(sy);
        int maxx = find_min(ex);
        int maxy = find_min(ey);
        if(minx <= maxx && miny <= maxy) {
        	cout << minx << " " << miny << endl;
        	return 0;
        }
		sx.insert(make_pair(a[i].s.first,i));
        sy.insert(make_pair(a[i].s.second,i));
        ex.insert(make_pair(a[i].e.first,i));
        ey.insert(make_pair(a[i].e.second,i));
    }
    return 0;
}
