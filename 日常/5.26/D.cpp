#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2e5 + 10;
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

int a[SZ],st[SZ][22],n,lg[SZ];

map<int,LL> t;

void get()
{
	for(int i = 1;i <= 2 * n;i ++)
		for(int j = 0;j <= lg[n];j ++)
			st[i][j] = 0;

    for(int i = 1;i <= n;i ++) st[i][0] = a[i];

    for(int j = 1;j <= lg[n];j ++)
		for(int i = 1;i <= n;i ++)
		{
			if(i + (1 << j) - 1 > n) continue;
            st[i][j] = __gcd(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
		}
}

int get_gcd(int l,int r)
{
	int k = lg[r - l + 1];
    return __gcd(st[l][k],st[r - (1 << k) + 1][k]);
}

int Div(int L,int x)
{
    int l = L,r = n + 1;
    while(r - l > 1)
	{
		int mid = l + r >> 1;
        if(get_gcd(L,mid) < x) r = mid;
        else l = mid;
	}
	return l;
}

int main()
{
    int T = read(),cc = 0;
    for(int i = 1;i <= 200000;i ++) lg[i] = log2(i);
    while(T --)
	{
		t.clear();
        n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        get();

        for(int i = 1;i <= n;i ++)
		{
            int x = a[i],r = i - 1;
            while(233)
			{
                int R = Div(i,x);
                t[x] += R - r;
              //  cout << i << " " << x << " " << R << " " << R - r << endl;
                r = R;
                if(r != n) x = get_gcd(i,r + 1);
				else break;
			}
		}
        int q = read();
        printf("Case #%d:\n",++ cc);
        while(q --)
		{
			int l = read(),r = read();
			int x = get_gcd(l,r);
            printf("%d %lld\n",x,t[x]);
		}
	}
	return 0;
}
