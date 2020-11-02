#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2000010;

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

LL a[SZ],bits[SZ];
int n,m;

void add(int x,LL d)
{
	for(int i = x;i <= n;i += i & -i)
		bits[i] += d;
}

LL ask(int x)
{
	LL ans = 0;
	for(int i = x;i > 0;i -= i & -i)
		ans += bits[i];
	return ans;
}

vector<LL> num[SZ];
int aa[SZ],bb[SZ];

int main()
{
	//cout << *it <<endl;
	//freopen("in.txt","r",stdin);
	//freopen("my.txt","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i ++)
	{
		a[i] = read();
		add(i,a[i]);
		LL x = a[i];
		//cout << i << endl;
		for(int j = 1;j <= sqrt(x);j ++)
			if(x % j == 0)
			{
				num[j].push_back(i);//out << j << " ";
				if(j != sqrt(x))
					num[x / j].push_back(i);//cout << x / j << " ";
			}
		//puts("");
	}
	num[1].clear();
	while(m --)
	{
		int opt = read(),l = read(),r = read(),d;
		if(opt == 1)
		{
			d = read();
			if(d == 1) continue;
			int x = lower_bound(num[d].begin(),num[d].end(),l) - num[d].begin();
		
			//for(int i = 0;i < num[d].size();i ++) cout << num[d][i] << " " << i << endl; puts("");
			//cout << x << endl;
			int len = 0;
			for(int i = x;i < num[d].size() && num[d][i] <= r;i ++)
			{
				//cout << num[d][i] << " ";// << i << endl;
				int id = num[d][i],x = a[id];
				add(id,-a[id]); a[id] /= d; add(id,a[id]);
				for(int j = 1;j <= sqrt(x);j ++)
					if(x % j == 0)
					{
						if(a[id] % j)
						{
							aa[++ len] = id; bb[len] = j;
						//	it = lower_bound(num[j].begin(),num[j].end(),id);
						//	if(it != num[j].end() && *it == id) tmp[++]
						}
						if(a[id] % (x / j))
						{
							aa[++ len] = id; bb[len] = x / j;
						//	it = lower_bound(num[x / j].begin(),num[x / j].end(),id);
						//	if(it != num[x / j].end() && *it == id) num[x / j].erase(it);
						}
					}
			}
			for(int i = 1;i <= len;i ++)
			{
				vector<LL> :: iterator it = lower_bound(num[bb[i]].begin(),num[bb[i]].end(),aa[i]);
				if(it == num[bb[i]].end()) continue;
				if(*it == aa[i]) num[bb[i]].erase(it);
			}
		}
		else
			printf("%lld\n",ask(r) - ask(l - 1));
		/*puts("");
		
		puts("---------------");
		printf("|  ");for(int i = 1;i <= n;i ++) cout << ask(i) - ask(i - 1) << " "; puts("");
		printf("|  ");for(int i = 1;i <= n;i ++) cout << log2(ask(i) - ask(i - 1)) << " "; puts("");
		puts("---------------");*/
	}
	return 0;
}

