#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double LD;
typedef pair<LL,LL> pii;
const int SZ = 700010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct point {
	LL pos,ji,ou,d;
	point() {}
	point(LL pos,LL ji,LL ou,LL d) :pos(pos),ji(ji),ou(ou),d(d) {}
	
}p[SZ];

bool cmp(point a,point b) { return a.pos < b.pos; }

int n,m;
LL ca[SZ],ta[SZ],cb[SZ],tb[SZ];

int main() {
	int T = read();
	while(T --) {
		int n = read();
		for(int i = 1;i <= n;i ++) ca[i] = read(),ta[i] = read();
		int m = read();
		for(int i = 1;i <= m;i ++) cb[i] = read(),tb[i] = read();
		LL now = 0; ///a-b
		int sz = 0;
		p[++ sz] = (point){0,1,1,1};
		p[++ sz] = (point){1,1,1,-1};
		for(int i = 1,j = 1;i <= n && j <= m;) {
			LL t = min(ta[i],tb[j]);
			LL l = now,r = now;
			if(ca[i] == cb[j]) {
				int id = now % 2 ? 1 : 0;
				p[++ sz] = (point){now,id,!id,t};
				p[++ sz] = (point){now + 1,id,!id,-t};
			}
			else {
				if(ca[i] == 0) {
					if(cb[j] == 1) l -= t,now -= t,r --;
					else r += t,now += t,l ++;
					int id = l % 2 ? 1 : 0;
					p[++ sz] = (point){l,id,!id,1};
					p[++ sz] = (point){l + 1,!id,id,1};
					p[++ sz] = (point){r + 1,1,1,-1};
				}
				else if(cb[j] == 0) {
					if(ca[i] == 1) r += t,now += t,l ++;
					else l -= t,now -= t,r --;
					int id = l % 2 ? 1 : 0;
					p[++ sz] = (point){l,id,!id,1};
					p[++ sz] = (point){l + 1,!id,id,1};
					p[++ sz] = (point){r + 1,1,1,-1};
				}
				else {
					if(ca[i] == 1) r += t + t,now += t + t,l += 2;
					else l -= t + t,now -= t + t,r -= 2;
					int id = l % 2 ? 1 : 0;
					p[++ sz] = (point){l,id,!id,1};
					p[++ sz] = (point){r + 1,id,!id,-1};
				}
			}
			if(!(ta[i] -= t)) i ++;
			if(!(tb[j] -= t)) j ++;
		}
		sort(p + 1,p + 1 + sz,cmp);
		LL ans = 0,ji = 0,ou = 0;
		for(int i = 1,j = 1;i <= sz;i = j) {
			for(j = i;j <= sz && p[j].pos == p[i].pos;j ++) {
				ji += p[j].d * p[j].ji;
				ou += p[j].d * p[j].ou;
			}
			ans = max(ans,max(ji,ou));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
