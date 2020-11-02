#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
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

struct haha {
	int x,y,id;
}b[SZ];

bool operator <(haha a,haha b) { return a.x > b.x; } 

pii a[SZ];

int sz[SZ],fa[SZ],mx[SZ],ml[SZ],mr[SZ];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int Ans[SZ];

int main() {
	int n = read(),m = read();
	for(int i = 1;i <= n;i ++) {
		int x = read();
		a[i] = make_pair(-x,i);
		ml[i] = mr[i] = fa[i] = i; sz[i] = 1; mx[i] = x;
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= m;i ++) {
		int x = read(),y = read();
		b[i] = (haha){x,y,i};
	}
	sort(b + 1,b + 1 + m);
	int maxsz = 0;
	for(int i = 1,j = 1;i <= m;i ++) {
		while(j <= n && -a[j].first > b[i].x) { 
			int pos = a[j].second;
			if(ml[find(pos)] > 1) {
				int x = find(pos),y = find(ml[find(pos)] - 1);
				if(mx[y] > b[i].x && x != y) {
					fa[x] = y; sz[y] += sz[x]; mx[y] = max(mx[y],mx[x]);
					ml[y] = min(ml[y],ml[x]);
					mr[y] = max(mr[y],mr[x]);
				}
			}
			if(mr[find(pos)] < n) {
				int x = find(pos),y = find(mr[find(pos)] + 1);
				if(mx[y] > b[i].x && x != y) {
					fa[x] = y; sz[y] += sz[x]; mx[y] = max(mx[y],mx[x]);
					ml[y] = min(ml[y],ml[x]);
					mr[y] = max(mr[y],mr[x]);
				}
			}
			maxsz = max(maxsz,sz[find(pos)]);
			j ++;
		}	
		Ans[b[i].id] = maxsz >= b[i].y ? 0 : 1;
	}
	for(int i = 1;i <= m;i ++) printf("%d\n",Ans[i]);
	return 0;
}
