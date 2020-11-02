#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 10000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int pri[SZ],tot;
bool vis[SZ];

void shai(int n) {
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
           		break;
            }
            else {
            }
		}
    }
}

bool isPrime(int x) {
	if(x <= 1) return false;
	for(int i = 1;pri[i] * pri[i] <= x;i ++)
		if(x % pri[i] == 0)
			return false;
	return true;
}

LL ans[SZ];

void dfs(LL now,LL pos,LL n) {
	if(n == 1) {
		ans[++ ans[0]] = now;
		return ;
	}
	if(n >= pri[pos] + 1 && isPrime(n - 1))
		ans[++ ans[0]] = (n - 1) * now;
//	cout << now << " " << pos << " " << n << endl;

	int d = sqrt(n);
    for(int i = pos;pri[i] <= d;i ++) {
		LL p = pri[i],tmp = 1 + p,pk = p;
        while(tmp <= n) {
            if(n % tmp == 0) dfs(now * pk,i + 1,n / tmp);
            pk *= p; tmp += pk;
        }
    }
}

int main() {
	shai(1e6);
	int n;
	while(~scanf("%d",&n)) {
		ans[0] = 0;
		dfs(1,1,n);
		sort(ans + 1,ans + 1 + ans[0]);
		printf("%d\n",ans[0]);
		for(int i = 1;i <= ans[0];i ++)
			printf("%lld%c",ans[i],i == ans[0] ? '\n' : ' ');
	}
    return 0;
}
