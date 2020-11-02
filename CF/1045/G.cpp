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

int len,n;

struct node {
	int l,r;
	int sz;
}tree[20000000];

int Tcnt = 0,rt[SZ];

void insert(int l,int r,int lst,int &now,int x,int d) {
	now = ++ Tcnt;
	tree[now] = tree[lst];
	tree[now].sz += d;
	if(l == r) return ;
	int mid = l + r >> 1;
	if(x <= mid) insert(l,mid,tree[lst].l,tree[now].l,x,d);
	else insert(mid + 1,r,tree[lst].r,tree[now].r,x,d);
}

void Insert(int l,int r,int now,int x,int d) {
	tree[now].sz += d;
	if(l == r) return ;
	int mid = l + r >> 1;
	if(x <= mid) Insert(l,mid,tree[now].l,x,d);
	else Insert(mid + 1,r,tree[now].r,x,d);
}

void add(int pos,int x,int d) {
	if(d == 1)
		for(int i = pos;i <= n;i += i & -i)
			insert(1,len,rt[i],rt[i],x,d);
	else
		for(int i = pos;i <= n;i += i & -i)
			Insert(1,len,rt[i],x,d);
}

int tmpl[SZ],tmpr[SZ];

int ask_ans(int l,int r,int x) {
	l --; tmpl[0] = tmpr[0] = 0;
	for(int i = l;i > 0;i -= i & -i) tmpl[++ tmpl[0]] = rt[i];
	for(int i = r;i > 0;i -= i & -i) tmpr[++ tmpr[0]] = rt[i];
	int ans = 0;
	int L = 1,R = len;
	while(L != R) {
		int mid = L + R >> 1;
		/*int lsz = 0,rsz = 0;
		for(int i = 1;i <= tmpl[0];i ++) lsz += tree[tmpl[i]].sz;
		for(int i = 1;i <= tmpr[0];i ++) rsz += tree[tmpr[i]].sz;
		cout << L << " " << R << " " << lsz << " " << rsz << endl;*/
		if(x <= mid) {
			for(int i = 1;i <= tmpl[0];i ++) tmpl[i] = tree[tmpl[i]].l;
			for(int i = 1;i <= tmpr[0];i ++) tmpr[i] = tree[tmpr[i]].l;
			R = mid;
		}
		else {
			for(int i = 1;i <= tmpl[0];i ++) ans -= tree[tree[tmpl[i]].l].sz,tmpl[i] = tree[tmpl[i]].r;
			for(int i = 1;i <= tmpr[0];i ++) ans += tree[tree[tmpr[i]].l].sz,tmpr[i] = tree[tmpr[i]].r;
			L = mid + 1;
		}
	}
	for(int i = 1;i <= tmpl[0];i ++) ans -= tree[tmpl[i]].sz;
	for(int i = 1;i <= tmpr[0];i ++) ans += tree[tmpr[i]].sz;
	//cout << ans << endl;
	return ans;
}


int lsh[SZ * 3];

struct haha {
	int x,r,q,ql,qr;
}a[SZ];

bool cmp(haha a,haha b) { return a.x < b.x; }
bool operator <(haha a,int b) { return a.x < b; }

struct Heap { int val,id; };
bool operator <(Heap a,Heap b) { return a.val > b.val; }
priority_queue<Heap> q;

int main() {
	//freopen("G.in","r",stdin);
	n = read();
	int k = read();
	for(int i = 1;i <= n;i ++) {
		a[i].x = read();
		a[i].r = read();
		a[i].q = read();
		lsh[++ lsh[0]] = a[i].ql = a[i].q - k - 1;
		lsh[++ lsh[0]] = a[i].qr = a[i].q + k;
		lsh[++ lsh[0]] = a[i].q;
	}
	sort(lsh + 1,lsh + 1 + lsh[0]);
	len = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
	for(int i = 1;i <= n;i ++) {
		a[i].q = lower_bound(lsh + 1,lsh + 1 + len,a[i].q) - lsh;
		a[i].qr = lower_bound(lsh + 1,lsh + 1 + len,a[i].qr) - lsh;
		a[i].ql = lower_bound(lsh + 1,lsh + 1 + len,a[i].ql) - lsh;
	}
	sort(a + 1,a + 1 + n,cmp);
	LL ans = 0;
	
	//for(int i = 1;i <= n;i ++) cout << a[i].x << " " << a[i].r << " " << a[i].q << " " << a[i].ql << " " << a[i].qr << endl;
	for(int i = 1;i <= n;i ++) {
		while(q.size() && q.top().val < a[i].x) {
			int id = q.top().id;// cout << id << " " << a[id].q << endl;
			add(id,a[id].q,-1); q.pop();
		}
		int l = lower_bound(a + 1,a + 1 + i,a[i].x - a[i].r) - a;
		ans += ask_ans(l,i - 1,a[i].qr) - ask_ans(l,i - 1,a[i].ql);
	//	cout << i << " " << l << " " << i - 1 << endl;
		add(i,a[i].q,1);
		q.push((Heap){a[i].x + a[i].r,i});
	}
	cout << ans << endl;
	return 0;
}
