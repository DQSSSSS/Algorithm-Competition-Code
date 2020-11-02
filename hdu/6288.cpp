#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1000010;
const LL INF = 1000000010;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};

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

int a,b;
ULL k;

bool can(ULL a,ULL b)
{
	ULL mod = 1e9 + 7;
    ULL s1 = (a % mod) * (b % mod) % mod;
    ULL s2 = a * b % mod;
	return s1 == s2;
}

ULL check(ULL n)
{
    ULL ans = 1,nn = n;
    for(int i = 1;i <= a;i ++)
	{
        if(!can(ans,n)) return 2e18;
		ans = ans * n;
	}
    ULL t = 0,f = 0;
    while(n) f += n & 1,n >>= 1,t ++;
    if(f == 1) t --;
	for(int i = 1;i <= b;i ++)
	{
		if(!can(ans,t)) return 2e18;
		ans = ans * t;
	}
	return ans;
}

ULL Div()
{
    ULL l = 2,r = (ULL)1e18 + 1;
    while(r - l > 1)
	{
		ULL mid = l + r >> 1;
        if(check(mid) <= k) l = mid;
        else r = mid;
	}
	return l;
}

int main()
{
    int T = read();
    while(T --)
	{
        scanf("%d%d%llu",&a,&b,&k);
        ULL ans = 0;
        printf("%llu\n",ans = Div());
        //cout << ksm(ans,a) <<" "<< ksm(get(ans),b) << " ";
        //cout << ksm(ans + 1,a) <<" "<< ksm(get(ans + 1),b) << endl;
	}
	return 0;
}

/*
233
1 0 1000000000000000000


*/


