#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2e5 + 10;
const int INF = 1e9 + 10;
const LL mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

void print(int x)
{
    for(int i = 15;i >= 0;i --)
		printf("%d",x >> i & 1);
}

LL f[22][100010],n,m;
vector<int> g[SZ];

void dfs(int now,int d,int n,int nx)
{
	if(d == n)
	{
		g[now].push_back(nx);
		//print(now); cout << " "; print(nx); puts("");
        return ;
	}
	//cout << d << endl;
    //print(now); cout << " "; print(nx); puts("");
    if(now & (1 << d)) dfs(now,d + 1,n,nx);
    else
	{
        dfs(now,d + 1,n,nx | (1 << d));
        if(d + 1 < n && !(now & (1 << (d + 1))))
            dfs(now,d + 2,n,nx);
	}
}

LL dp(int n,int m)
{
	memset(f,0,sizeof(f));
    f[0][(1 << m) - 1] = 1;
    for(int i = 0;i < (1 << m);i ++) g[i].clear();
    for(int i = 0;i < (1 << m);i ++)
    {
		dfs(i,0,m,0);
       /* sort(g[i].begin(),g[i].end());
        int k = unique(g[i].begin(),g[i].end()) - g[i].begin();
        g[i].erase(g[i].begin() + k,g[i].end());*/
    }
    for(int i = 1;i <= n;i ++)
    {
		cout << i <<endl;
		for(int j = 0;j < (1 << m);j ++)
            for(int k = 0;k < g[j].size();k ++)
			{
				int v = g[j][k];
                //if(i != n && v == 0) continue;
		     cout << j << " -> " << v << endl;
                (f[i][v] += f[i - 1][j]) %= mod;
			}
    }
	for(int i = 1;i <= n;i ++,puts(""))
        for(int j = 0;j < (1 << m);j ++)
			cout << f[i][j] << " ";
	return f[n][(1 << m) - 1];
}

LL dp2(int n,int m)
{
	return 0;
}

int main()
{
//	dfs(0,0,6,0);
    while(cin >> n >> m)
	{
       /* LL ans = (dp(n,m) + dp(m,n) - dp2(n,m)) % mod;
        ans += mod; ans %= mod;*/
        cout << dp(n,m) << endl;
	}
	return 0;
}




