#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 2000010;
const LL INF = 1000000010;
const LL mod = 1000000007;

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

LL pri[] = {2,3,5,7,11,13,17,19,23,29,31,37};

int D(LL n)
{
    int ans = 0;
    for(int i = 1;i <= sqrt(n);i ++)
        if(n % i == 0) ans += ((LL)i * i == n) ? 1 : 2;
    return ans;
}

LL n,ans = 0,t = 0;
int use[20];

void dfs(int d,LL now)
{
    if(now > n || (d > 0 && use[d] > use[d - 1])) return ;
    int tmp = D(now);
    if(now <= n && (tmp > t || (tmp == t && now < ans))) t = tmp,ans = now;
    //for(int i = 0;i <= 10;i ++) printf("%d ",use[i]); puts("");
    use[d] ++;
    dfs(d,now * pri[d]);
    use[d] --;
    use[d + 1] ++;
    dfs(d + 1,now * pri[d + 1]);
    use[d + 1] --;
}

int main()
{
    n = read();
    dfs(0,1);
//    cout << D(ans) << endl;
    printf("%lld",ans);
    return 0;
}

/*
2^4*3^2*5

2^3*3*5*7

*/
