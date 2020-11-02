#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

int n;
LL l;

struct haha
{
	int x,t,id;
}a[SZ];

bool cmp(haha a,haha b) { return a.x > b.x; }

priority_queue<haha> q,ansq;

bool operator <(haha a,haha b) { return a.t < b.t; }

LL work()
{
	LL now = 0,ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(now + a[i].t <= l && a[i].x >= q.size() + 1)
		{
			q.push(a[i]); now += a[i].t;
		}
		else
		{
			if(a[i].x >= q.size() && q.size())
			{
				haha x = q.top(); q.pop();
				if(now - x.t + a[i].t <= l) now = now - x.t + a[i].t,q.push(a[i]);
				else q.push(x);
			}
		}
		ans = max(ans,(LL)q.size());
	}
	return ans;
}

int main()
{
	n = read();
	l = read();
	for(int i = 1;i <= n;i ++) a[i].x = read(),a[i].t = read(),a[i].id = i;
	sort(a + 1,a + 1 + n,cmp);
	LL ans = work();
	while(q.size()) q.pop();
	LL now = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(now + a[i].t <= l && a[i].x >= q.size() + 1)
		{
			q.push(a[i]); now += a[i].t;
		}
		else
		{
			if(a[i].x >= q.size() && q.size())
			{
				haha x = q.top(); q.pop();
				if(now - x.t + a[i].t <= l) now = now - x.t + a[i].t,q.push(a[i]);
				else q.push(x);
			}
		}
		if(ans == q.size())
		{
			cout << ans << endl;
			cout << q.size() << endl;
			while(q.size()) cout << q.top().id << " ",q.pop();
			return 0;
		}
	}
	
	return 0;
}


