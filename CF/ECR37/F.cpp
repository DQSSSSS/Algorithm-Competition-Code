#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') { n = n *10 +a - '0'; a = getchar(); }
	if(flag) n = -n;
	return n;
}

int n,m,a[SZ],d[SZ],cnt[SZ];
int pri[SZ];
bool vis[SZ];

void shai()
{
    d[1] = 1;
    for(int i = 2,tot = 0;i <= 1e6;i ++)
    {
        if(!vis[i]) pri[++ tot] = i,d[i] = 2,cnt[i] = 1;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= 1e6;j ++)
        {
            vis[m] = 1;
            if(i % pri[j] == 0) { cnt[m] = cnt[i] + 1; d[m] = d[i]/(cnt[i] + 1) * (cnt[m] + 1); break; }
            else { cnt[m] = 1; d[m] = d[i] << 1;  }
        }
    }
}


struct seg
{
	int l,r;
	LL sum,Max,t;
}tree[SZ * 4];

void update(int p)
{
	tree[p].sum = tree[p <<1].sum + tree[p <<1 |1].sum;
	tree[p].Max = max(tree[p <<1].Max,tree[p <<1 |1].Max);
}

void build(int p,int l,int r)
{
	tree[p].l = l; tree[p].r = r;
	if(l == r)
	{	
		tree[p].sum = tree[p].Max = a[l];
		tree[p].t = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(p << 1,l,mid); build(p <<1 |1,mid +1,r);
	update(p);
}

void change(int p,int l,int r)
{
	if(tree[p].Max <= 2) return ;
	if(tree[p].l == tree[p].r)
	{
		tree[p].sum = tree[p].Max = d[tree[p].sum];
		return ;
	}
	int mid = tree[p].l + tree[p].r >> 1;
	if(l <= mid) change(p << 1,l,r);
	if(mid < r) change(p << 1 | 1,l,r);
	update(p);
}

LL ask(int p,int l,int r)
{
	if(l <= tree[p].l && tree[p].r <= r)
	{
		return tree[p].sum;
	}
	int mid = tree[p].l + tree[p].r >> 1;
	LL ans = 0;
	if(l <= mid) ans += ask(p << 1,l,r);
	if(mid < r) ans += ask(p << 1 | 1,l,r);
	return ans;
}

int main()
{
	shai();
	n = read(),m = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	build(1,1,n);
	//for(int i = 1;i <= 50;i ++) cout << i << " " << d[i] << endl;
	for(int i = 1;i <= m;i ++)
	{
		int opt = read(),x = read(),y = read();
		if(opt == 1) change(1,x,y);
		else printf("%I64d\n",ask(1,x,y));
	//	for(int j = 1;j <= n;j ++) cout << ask(1,j,j) << " "; puts("");
	}
	return 0;
}
