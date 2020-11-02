#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<double,double> pii;
const int SZ = 1000010;
const double INF = 1e18;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};
const double eps = 1e-6;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m;

struct haha
{
	int l,r;
	double a,b;
}p[SZ];

bool cmp(haha a,haha b) { return a.r < b.r; }

double w[SZ],f[SZ];

/*
double bits[SZ];

double ask_min(int x)
{
	double ans = INF;
	for(int i = x;i > 0;i -= i & -i)
		ans = min(ans,bits[i]);
	return ans;
}

void add(int x,double d)
{
	for(int i = x;i <= m;i += i & -i)
		bits[i] = min(bits[i],d);
}

*/
struct segment
{
	int l,r;
	double Min;
}tree[SZ << 2];

void update(int p) { tree[p].Min = min(tree[p << 1].Min,tree[p << 1 | 1].Min); }

void build(int p,int l,int r)
{
	tree[p].l = l; tree[p].r = r;
	if(l == r) { tree[p].Min = INF; return ; }
	int mid = l + r >> 1;
	build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
	update(p);
}

double ask_min(int p,int l,int r)
{
	if(l <= tree[p].l && tree[p].r <= r)
		return tree[p].Min;
	int mid = tree[p].l + tree[p].r >> 1;
	double ans = INF;
	if(l <= mid) ans = min(ans,ask_min(p << 1,l,r));
	if(mid < r) ans = min(ans,ask_min(p << 1 | 1,l,r));
	return ans;
}

void change(int p,int x,double d)
{
	if(tree[p].l == tree[p].r)
		{ tree[p].Min = min(tree[p].Min,d); return ; }
	int mid = tree[p].l + tree[p].r >> 1;
	if(x <= mid) change(p << 1,x,d);
	else change(p << 1 | 1,x,d);
	update(p);
}


double check(double k)
{
	for(int i = 1;i <= n;i ++) w[i] = p[i].a - k * p[i].b;
	//for(int i = 1;i <= n;i ++) cout << w[i] << " "; puts("");
	for(int i = 1;i <= m;i ++) f[i] = INF;
	f[1] = 0;// add(m,0);
	build(1,1,m); change(1,1,0);
	double tmp = INF;
	for(int i = 1;i <= n;i ++)
	{
		int r = p[i].r,l = p[i].l;
		//for(int j = l - 1;j < r;j ++) f[r] = min(f[r],f[j] + w[i]);
		
		if(p[i - 1].r != p[i].r) tmp = INF;
		tmp = min(tmp,ask_min(1,l - 1,r - 1) + w[i]); 
		if(p[i].r != p[i + 1].r) f[r] = tmp,change(1,r,f[r]);
		
		
		/**
		if(p[i - 1].r != p[i].r) tmp = INF;
		tmp = min(tmp,ask_min(m - l + 2) + w[i]); 
		if(p[i].r != p[i + 1].r) f[r] = tmp,add(m - r + 1,f[r]);
		**/
	}
//	for(int i = 1;i <= m;i ++) cout << f[i] << " "; puts("");
	return f[m];
}

double div()
{
	double l = 0,r = 1e9;
	for(int i = 1;i <= 60;i ++)
	{
		double mid = (l + r) / 2.0;
		if(check(mid) > 0) l = mid;
		else r = mid;
	}
	return r;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("std.txt","w",stdout);
	int T = read();
	while(T --)
	{
		n = read(),m = read() + 1;
		for(int i = 1;i <= n;i ++)
		{
			p[i].l = read() + 1,p[i].r = read() + 1,p[i].a = read(),p[i].b = read();
		}
		p[0] = p[n + 1] = (haha){0,0,0,0};
		sort(p + 1,p + 1 + n,cmp);
		//cout << check(27.5) <<endl;
		printf("%.3f\n",div());
	}
	return 0;
}
