#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e5 + 10;

struct point {
	int x,y;
}a[SZ];

bool operator <(point a,point b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }

map<point,int> mp;
int n;
bool qj[110][110];

bool check() {
	for(int i = 1;i <= n;i ++) {
		for(int j = i + 1;j <= n;j ++){
			if(!qj[i][j]) continue;
			int dx = a[j].x - a[i].x;
			int dy = a[j].y - a[i].y;
			int id1 = mp[(point){a[i].x-dy,a[i].y+dx}];
			int id2 = mp[(point){a[j].x-dy,a[j].y+dx}];
			if(id1 && id2 && qj[i][id1] && qj[id1][id2] && qj[id2][j]) {
				return true;
			}
		}
	}
	return false;
}

struct haha {
	int x,y,id;
}b[SZ];

int cmp_id;

bool cmp(haha a,haha b) {
	LL adx = a.x - ::a[cmp_id].x;
	LL ady = a.y - ::a[cmp_id].y;
	LL bdx = b.x - ::a[cmp_id].x;
	LL bdy = b.y - ::a[cmp_id].y;
	if(adx * bdy != ady * bdx) return adx * bdy < ady * bdx;
	return adx * adx + ady * ady < bdx * bdx + bdy * bdy;
}

bool check_xl(haha a,haha b) {
	LL adx = a.x - ::a[cmp_id].x;
	LL ady = a.y - ::a[cmp_id].y;
	LL bdx = b.x - ::a[cmp_id].x;
	LL bdy = b.y - ::a[cmp_id].y;
	return adx * bdy == ady * bdx;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		mp.clear();
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++) {
			scanf("%d%d",&a[i].x,&a[i].y);
			mp[a[i]] = i;
		}
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n;j ++)
				qj[i][j] = 0;
		if(n != 4) { puts("NO"); continue; }
		for(int i = 1;i <= n;i ++) {
			int cnt = 0;
			for(int j = 1;j <= n;j ++)
				if(i != j) b[++ cnt] = (haha){a[j].x,a[j].y,j};
			cmp_id = i;
			sort(b + 1,b + 1 + cnt,cmp);
			for(int j = 1;j <= cnt;j ++) {
				if(j == 1 || !check_xl(b[j],b[j-1])) {
					qj[i][b[j].id] = qj[b[j].id][i] = 1;
				}
			}
		}
		puts(check() ? "YES" : "NO");
	}
	return 0;
}
