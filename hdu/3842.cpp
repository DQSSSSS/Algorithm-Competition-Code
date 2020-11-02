#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
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

int cc = 0;

struct haha {
	int d,p,r,g;
	LL f;
	LL F() { return f - (LL)g * d - g - p + r; }
	//void print() { printf("%lld %lld %lld %lld %lld\n",d,p,r,g,f); }
	bool operator !=(haha o) { return o.d != d || o.p != p || o.r != r || o.g != g || o.f != f; }
}a[SZ],tmp[SZ],tmp2[SZ];
bool cmp(haha a,haha b) { return a.d < b.d; }
bool cmp2(haha a,haha b) { return a.g == b.g ? a.F() < b.F() : a.g < b.g; }

bool check(int a,int b,int c) {
	LL xa = ::a[b].F() - ::a[a].F();
	LL ya = ::a[b].g - ::a[a].g;
	LL xb = ::a[c].F() - ::a[a].F();
	LL yb = ::a[c].g - ::a[a].g;
	return (double)ya * xb - (double)yb * xa < 0;
}

double xl(int x,int y) {
	return 1.0 * (a[x].F() - a[y].F()) / (a[x].g - a[y].g);
}

int q[SZ];

void cdq(int l,int r) {
	if(l == r) return ;
	int mid = l + r >> 1;
	cdq(l,mid);
	int t = 1,w = 0;
	for(int i = l;i <= mid;i ++) {
		if(a[i].f >= a[i].p) {
			while(t < w && !check(q[w - 1],q[w],i)) w --;
			q[++ w] = i;
		}
	}
	for(int i = mid + 1;i <= r;i ++) {
		while(t < w && a[q[t]].F() + (LL)a[i].d * a[q[t]].g < a[q[t + 1]].F() + (LL)a[i].d * a[q[t + 1]].g) t ++;
		int id = q[t];
		a[i].f = max(a[i].f,a[id].F() + (LL)a[id].g * a[i].d);
	}
	cdq(mid + 1,r);
	/*int pl = l,pr = mid + 1,p = l;
	while(pl <= mid || pr <= r) {
		if(pr > r || (pl <= mid && cmp2(a[pl],a[pr])))
			tmp[p ++] = a[pl ++];
		else
			tmp[p ++] = a[pr ++]; 
	}
	for(int i = l;i <= r;i ++) a[i] = tmp[i];*/
	sort(a + l,a + r + 1,cmp2);
}

int n;

int main() {
	//freopen("works.in","r",stdin);
	//freopen("my.out","w",stdout);
	int c,d;
	while(~scanf("%d%d%d",&n,&c,&d) && (n || c || d)) {
		n += 2;
		a[1] = (haha){0,0,0,0,c}; a[n] = (haha){d + 1,0,0,0,c};	
		for(int i = 2;i < n;i ++) {
			//a[i].d = read(),a[i].p = read(),a[i].r = read(),a[i].g = read();
			scanf("%d%d%d%d",&a[i].d,&a[i].p,&a[i].r,&a[i].g);
			a[i].f = c;
		}
		sort(a + 1,a + n + 1,cmp);
		cdq(1,n);	
		LL ans = 0;
		for(int i = 1;i <= n;i ++) ans = max(ans,a[i].f);
		printf("Case %d: %lld\n",++ cc,ans);
	}
	return 0;
}
/***
1 0 0 0 10
1 9 1 2 10
2 10 9 1 10
3 2 1 2 10
4 11 7 4 10
6 12 1 3 13
8 20 5 4 17
21 0 0 0 44
*/
