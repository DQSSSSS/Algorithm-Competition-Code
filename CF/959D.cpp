#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 3000010;
const LL INF = 1e17 + 10;

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

int a[SZ],b[SZ],N = 3e6;
bool vis[SZ];

void fz(int x)
{
	if(vis[x]) return ;
	for(int j = x;j <= N;j += x)
		vis[j] = 1;
}

void work(int x)
{
	for(int i = 2;i <= sqrt(x);i ++)
	{
		if(x % i == 0)
		{
			fz(i);
			while(x % i == 0) x /= i;
		}
	}
	if(x != 1) fz(x);
}

int main()
{
	int n = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	int now = 2;
	for(int i = 1,flag = 0;i <= n;i ++)
	{
		if(flag)
		{
			while(now <= N)
			{
			//	cout << i << " " << now << endl;
				if(!vis[now]) { b[i] = now; work(now); break; }
				now ++;
			}
		}
		else
		{
			if(!vis[a[i]]) b[i] = a[i],work(b[i]);
			else
			{
				flag = 1;
				for(int j = a[i] + 1;j <= N;j ++)
					if(!vis[j]) {b[i] = j,work(j); break;}
			}
		}
	}
	for(int i = 1;i <= n;i ++) printf("%d ",b[i]);
	return 0;
}

