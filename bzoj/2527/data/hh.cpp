#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 600010;
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

LL bits[SZ];
int m;

void Add(int x,LL d) {
	for(int i = x;i <= m;i += i & -i) bits[i] += d;
}

ULL Ask(int x) {
	ULL ans = 0;
	for(int i = x;i > 0;i -= i & -i) ans += bits[i];
	return ans;
}

vector<int> g[SZ];

struct haha {
	int l,r;
	LL d;
	int id;
}a[SZ];
	
void add_rain(int id,LL c) {
	Add(a[id].l,c * a[id].d);
	Add(a[id].r + 1,-c * a[id].d);
}

ULL ask_sta(int id) {
	ULL ans = 0;
	for(int i = 0;i < g[id].size();i ++) {
		ans += Ask(g[id][i]);
	}
	return ans;
}

struct sta {
	ULL k;
	int id;
}b[SZ],bl[SZ],br[SZ];

int Ans[SZ],tot;

void solve(int vl,int vr,int l,int r) {
	if(vl > vr || l > r) return;
	if(vr - vl <= 1) {
		for(int i = l;i <= r;i ++)
			Ans[b[i].id] = vr > tot ? -1 : a[vr].id;
		return ;
	}
	int vm = vl + vr >> 1;
	for(int i = vl + 1;i <= vm;i ++) add_rain(i,1);
	int pl = 0,pr = 0;
	for(int i = l;i <= r;i ++) {
		LL d = ask_sta(b[i].id);
		if(b[i].k > d) b[i].k -= d,br[++ pr] = b[i];
		else bl[++ pl] = b[i];
	}
	for(int i = vl + 1;i <= vm;i ++) add_rain(i,-1);
	for(int i = 1;i <= pl;i ++) b[l + i - 1] = bl[i];
	for(int i = 1;i <= pr;i ++) b[l + pl + i - 1] = br[i];
	solve(vl,vm,l,l+pl-1); solve(vm,vr,l+pl,r);
}

int main() {
	//cout << (ULL)1e19 << endl; while(1);
	freopen("16.in","r",stdin);
	freopen("3527.out","w",stdout);
	int n = read(); m = read();
	for(int i = 1;i <= m;i ++) {
		int x = read();
		g[x].push_back(i);
	}
	for(int i = 1;i <= n;i ++) b[i].k = read(),b[i].id = i,Ans[i] = -1;
	int q = read();
	tot = 0;
	for(int i = 1;i <= q;i ++) {
		int l = read(),r = read();
		LL d = read();
		if(l <= r) a[++ tot] = (haha){l,r,d,i};
		else a[++ tot] = (haha){l,m,d,i},a[++ tot] = (haha){1,r,d,i};
	}
	solve(0,tot + 1,1,n);
	for(int i = 1;i <= n;i ++) {
		if(Ans[i] == -1) puts("NIE");
		else printf("%d\n",Ans[i]);
	}
	//if(!system("fc 33.out 233.out")) while(1);	
	return 0;
}

