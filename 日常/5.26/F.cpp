#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e7 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

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

int pri[SZ],phi[SZ];
bool vis[SZ];

int main()
{
	int tot = 0,maxn = 10000000;
    phi[1] = 1;
    for(LL i = 2;i <= maxn;i ++)
	{
        if(!vis[i]) pri[++ tot] = i,phi[i] = i - 1;
        for(LL j = 1,m;j <= tot && (m = i * pri[j]) <= maxn;j ++)
		{
            vis[m] = 1;
            if(i % pri[j] == 0) { phi[m] = phi[i] * pri[j]; break; }
			else phi[m] = phi[i] * phi[pri[j]];
		}
	}
	LL n,m,p;
    while(~scanf("%lld%lld%lld",&n,&m,&p))
	{
		LL k = 0;
        for(int i = 1;i <= m;i ++)
			k += phi[i * n];
        while(p != 1) cout << p << " ",p = phi[p];
        cout << k << endl;
	}
	return 0;
}

