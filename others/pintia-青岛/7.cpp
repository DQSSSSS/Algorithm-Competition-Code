#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
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

int n,len;

LL bits[SZ];

LL Ask(int x) {
	LL ans = 0;
	for(int i = x;i > 0;i -= i & -i) ans += bits[i];
	return ans;
}

void Add(int x,int d) {
	for(int i = x;i <= len;i += i & -i) bits[i] += d;
}

LL get_ans(const LL a[],int l,int r) {
	LL ans = 0;
	for(int i = r;i >= l;i --) {
		ans += Ask(a[i] - 1);
		Add(a[i],1);
	}
	for(int i = r;i >= l;i --) Add(a[i],-1);
	return ans;
}

struct seg {
	int l,r;
	int sz;
}tree[8000010];

int rt[SZ],Tcnt = 0;

void insert(int l,int r,int lst,int &now,int x) {
	now = ++ Tcnt;
	tree[now] = tree[lst]; tree[now].sz ++;
	if(l == r) return ;
	int mid = l + r >> 1;
	if(x <= mid) insert(l,mid,tree[lst].l,tree[now].l,x);
	else insert(mid + 1,r,tree[lst].r,tree[now].r,x);
}

LL ask_bigger(int l,int r,int x) {
	if(l > r) return 0;
	int rl = rt[l - 1],rr = rt[r],L = 1,R = len;
	LL ans = 0;
	while(L != R) {
		int mid = L + R >> 1;
		if(tree[rr].sz - tree[rl].sz == 0) break;		
		if(x <= mid)
			ans += tree[tree[rr].r].sz - tree[tree[rl].r].sz,
			rl = tree[rl].l,rr = tree[rr].l,R = mid;
		else
			rl = tree[rl].r,rr = tree[rr].r,L = mid + 1;
	}
	return ans;
}

LL ask_smaller(int l,int r,int x) {
	if(l > r) return 0;
	int rl = rt[l - 1],rr = rt[r],L = 1,R = len;
	LL ans = 0;
	while(L != R) {
		int mid = L + R >> 1;
		if(tree[rr].sz - tree[rl].sz == 0) break;
		if(x <= mid)
			rl = tree[rl].l,rr = tree[rr].l,R = mid;
		else
			ans += tree[tree[rr].l].sz - tree[tree[rl].l].sz,
			rl = tree[rl].r,rr = tree[rr].r,L = mid + 1;
	}
	return ans;
}

LL Ans[SZ],a[SZ];
multiset<LL> s;

LL del(int x,int l,int r) {
//	cout << x << " " << l << " " << r << endl;
	LL nowans = Ans[l],val = a[x];
	s.erase(s.find(-nowans));
	nowans -= ask_bigger(l,x - 1,val);
	nowans -= ask_smaller(x + 1,r,val);
	int lenl = x - l,lenr = r - x;
	if(lenl < lenr) {
		LL d = 0;
		for(int i = l;i < x;i ++)
			d += ask_smaller(x + 1,r,a[i]);
		nowans -= d;
		Ans[l] = get_ans(a,l,x - 1);
		Ans[x + 1] = nowans - Ans[l];
	}
	else {
		LL d = 0;
		for(int i = x + 1;i <= r;i ++)
			d += ask_bigger(l,x - 1,a[i]);
		nowans -= d;
		Ans[x + 1] = get_ans(a,x + 1,r);
		Ans[l] = nowans - Ans[x + 1];
	}
	s.insert(-Ans[x + 1]); s.insert(-Ans[l]);
	return -*s.begin();
}

set<int> Set;

int lsh[SZ];

void init() {
	Tcnt = 0;
	lsh[0] = 0;
	Set.clear(); s.clear();
}

int main() {
	//freopen("7.in","r",stdin);
	//freopen("7.out","w",stdout);
	int T = read();
	while(T --) {
		n = read();
		init();
		for(int i = 1;i <= n;i ++) {
			lsh[++ lsh[0]] = a[i] = read();
		}
		sort(lsh + 1,lsh + 1 + lsh[0]);
		len = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
		for(int i = 1;i <= n;i ++) {
			a[i] = lower_bound(lsh + 1,lsh + 1 + len,a[i]) - lsh;
			insert(1,len,rt[i - 1],rt[i],a[i]);
		}
		LL lstans = get_ans(a,1,n);
		Ans[1] = lstans;
		s.insert(-lstans);
		Set.insert(0);
		Set.insert(n + 1);
		for(int i = 1;i <= n;i ++) {
			LL x = read();			
			printf("%lld%c",lstans,i == n ? '\n' : ' ');
			if(lstans == 0) continue;
			x ^= lstans;
			set<int> :: iterator it = Set.lower_bound(x); 
			int r = *it; it --;
			int l = *it;
		//	cout << l << " " << r << endl;
			lstans = del(x,l + 1,r - 1);
			Set.insert(x);
		}
	}
	return 0;
}
