#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 +a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

LL a[SZ];

void add(vector<int> &a,int x,int d)
{
	int n = a.size() - 1;
	for(int i = x;i <= n;i += i & -i)
		a[i] += d;
}

int ask_presum(vector<int> a,int x)
{
	int ans = 0;
	for(int i = x;i > 0;i -= i & -i)
		ans += a[i];
	return ans;
}

int ask(vector<int> a,int x)
{
	return ask_presum(a,x) - ask_presum(a,x - 1);
}


struct segment
{
	int l,r;
	LL sum;
	vector<int> num,cnt;
}tree[SZ * 4];

void update(int p)
{
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void Merge(int p)
{
	int l = 1,r = 1,id = 0;
	segment &L = tree[p << 1],&R = tree[p << 1 | 1],&now = tree[p];
	now.num.resize(L.num.size() + R.num.size());
	vector<int> :: iterator it = set_union(L.num.begin(),L.num.end(),R.num.begin(),R.num.end(),now.num.begin());
	now.num.resize(it - now.num.begin());
	now.cnt.resize(now.num.size());
/*	
	cout << "size :" << now.num.size() << endl;
	for(int i = 0;i < now.num.size();i ++) cout << now.num[i] << " "; puts("");
	cout << "Lsize :" << L.num.size() << endl;
	for(int i = 0;i < L.num.size();i ++) cout << L.num[i] << " "; puts("");
	cout << "Rsize :" << R.num.size() << endl;
	for(int i = 0;i < R.num.size();i ++) cout << R.num[i] << " "; puts("");
*/
	
	
	for(int i = 1,j = 1;i < L.num.size();i ++)
	{
		while(j < now.num.size() && now.num[j] < L.num[i]) j ++;
		if(j >= now.num.size()) break;
		if(now.num[j] == L.num[i]) add(now.cnt,j,ask(L.cnt,i));
	}
	for(int i = 1,j = 1;i < R.num.size();i ++)
	{
		while(j < now.num.size() && now.num[j] < R.num[i]) j ++;
		if(j >= now.num.size()) break;
		if(now.num[j] == R.num[i]) add(now.cnt,j,ask(R.cnt,i));
	}
	/*while(l < L.num.size() || r < R.num.size())
	{
		if(l >= L.num.size() || R.num[r] <= L.num[l])
		{
			if(R.num[r] == now.num[id]) continue;
			else now.num.push_back(R.num[r]),id ++;
			r ++;
		}
		else
		{
			if(L.num[l] == now.num[id]) continue;
			else now.num.push_back(L.num[l]),id ++;
			l ++;
		}
	}*/
	/*
	puts("");
	for(int i = 0;i < tree[p].num.size();i ++) cout << tree[p].num[i] << " "; puts("");
	for(int i = 0;i < tree[p].num.size();i ++) cout << ask(tree[p].cnt,i) << " "; puts("");
	puts("");*/
}

void build(int p,int l,int r)
{
	tree[p].l = l; tree[p].r = r;
	tree[p].num.push_back(1), tree[p].cnt.push_back(0);
	if(l == r)
	{
		tree[p].sum = a[l];
		int x = a[l],len = 0;
		for(int i = 2;i <= sqrt(x);i ++)
		{
			if(x % i == 0) tree[p].num.push_back(i),len ++;
			while(x % i == 0) x /= i;
		}
		if(x != 1) tree[p].num.push_back(x),len ++;
		tree[p].cnt = vector<int> (len + 1,0);

		x = a[l];
		for(int i = 2,j = 0;i <= sqrt(x);i ++)
			if(x % i == 0)
			{
				j ++;
				int ans = 0;
				while(x % i == 0) x /= i,ans ++;
				add(tree[p].cnt,j,ans);
			}
		if(x != 1) add(tree[p].cnt,len,1);
		
	/*	cout << "id : " << l << "   len : " << len << endl;
		cout << tree[p].num.size() << endl;
		for(int i = 0;i < tree[p].num.size();i ++) cout << tree[p].num[i] << " "; puts("");
		for(int i = 0;i < tree[p].num.size();i ++) cout << ask(tree[p].cnt,i) << " "; puts("");
		puts("");
*/
		return ;
	}
	int mid = l + r >> 1;
	build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
	update(p);
	Merge(p);
	
/*	cout << "----------------------\nbuild : "<<endl;
	cout << l << " "<< r << endl;
	for(int i = 0;i < tree[p].num.size();i ++) cout << tree[p].num[i] << " "; puts("");
	for(int i = 0;i < tree[p].num.size();i ++) cout << ask(tree[p].cnt,i) << " "; puts("");
	puts("-----------------------");
	*/
}

int ask_num(int p,int d)
{
	vector<int> &g = tree[p].num;
	vector<int> :: iterator x = lower_bound(g.begin(),g.end(),d);
	if(*x != d) return 0;
	return ask(tree[p].cnt,x - g.begin());
}

int num[SZ],cnt[SZ],len;

bool iscan(int p,int d)
{
	int xx = d == 0 ? 1 : tree[p].r - tree[p].l + 1;
	for(int i = 1;i <= len;i ++)
		if(ask_num(p,num[i]) < cnt[i] * xx) return false;
	return true;
}

int Div(int p,int l,int r,int d)
{
	if(!iscan(p,0)) return 0;
	cout << tree[p].l << " " << tree[p].r << endl;
	if(l <= tree[p].l && tree[p].r <= r && iscan(p,1))
	{
		tree[p].sum /= d;
		int xx = tree[p].r - tree[p].l + 1;
		vector<int> &g = tree[p].num;
		for(int i = 1;i <= len;i ++)
		{
			int x = lower_bound(g.begin(),g.end(),d) - g.begin();
			add(tree[p].cnt,x,-xx * cnt[i]);
		}
		return xx;
	}
	int mid = tree[p].l + tree[p].r >> 1,ans = 0;
	if(l <= mid) ans += Div(p << 1,l,r,d);
	if(mid < r) ans += Div(p << 1 | 1,l,r,d);
	
	update(p);
	vector<int> &g = tree[p].num;
	for(int i = 1;i <= len;i ++)
	{
		int x = lower_bound(g.begin(),g.end(),d) - g.begin();
		add(tree[p].cnt,x,-ans * cnt[i]);
	}
}

LL ask_sum(int p,int l,int r)
{
	if(l <= tree[p].l && tree[p].r <= r)
		return tree[p].sum;
	int mid = tree[p].l + tree[p].r >> 1;
	LL ans = 0;
	if(l <= mid) ans += ask_sum(p << 1,l,r);
	if(mid < r) ans += ask_sum(p << 1 | 1,l,r);
	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("my.txt","w",stdout);
	int n = read(),m = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	//puts("");
	build(1,1,n);
	//puts("");
	while(m --)
	{
		int opt = read(),l = read(),r = read(),d;
		if(opt == 1)
		{
			d = read();
			if(d == 1) continue;
			/*
			for(int i = l;i <= r;i ++) if(a[i] % d == 0) a[i] /= d;
			*/
			
			len = 0;
			int x = d;
			for(int i = 2;i <= sqrt(x);i ++)
			{
				if(x % i == 0) num[++ len] = i,cnt[len] = 0; 
				while(x % i == 0)
					x /= i,cnt[len] ++;
			}
			if(x != 1) num[++ len] = x,cnt[len] = 1;
		/*
			cout << len << endl;
			for(int i = 1;i <= len;i ++) cout << num[i] << " " << cnt[i] << endl;
			puts("");
			*/
			Div(1,l,r,d);
		}
		else
		{
		/*	LL ans = 0;
			for(int i = l;i <= r;i ++) ans += a[i];
			cout << ans << endl;
		*/
			printf("%lld\n",ask_sum(1,l,r));
		}
	}
	return 0;
}
