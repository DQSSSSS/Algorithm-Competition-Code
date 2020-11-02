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
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

struct haha
{
	LL a,b;
}l[SZ];

bool cmp(haha a,haha b) { if(a.a != b.a) return a.a < b.a; return a.b < b.b; }

int main()
{
	int n = read();
    for(int i = 1;i <= n;i ++)
	{
        LL x = read(),d = sqrt(x);
        l[i].b = x;
        l[i].a = min(abs(x - d * d),abs(x - (d + 1) * (d + 1)));
	}
    sort(l + 1,l + 1 + n,cmp);
    LL ans = 0;
    for(int i = 1;i <= n / 2;i ++) ans += l[i].a;
    for(int i = n / 2 + 1;i <= n;i ++)
	{
		if(!l[i].a)
		{
			if(l[i].b) ans ++;
			else ans += 2;
		}
	}
    printf("%I64d\n",ans);
	return 0;
}





