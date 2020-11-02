#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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

int p,r;
LL f[SZ];

LL dfs(int n) {
    if(f[n] != -1) return f[n];
    LL ans = 1e18;
    for(int i = 2,j;i <= n;i = j + 1) {
        j = n / (n / i);
        LL t = dfs((n+j-1)/j)+1ll*(j-1)*p+r;
        ans = min(ans,t);
    }
    return ::f[n] = ans;
}

int main() {
    int n = read();
    r = read(),p = read();
    memset(f,-1,sizeof f);
    f[1] = 0; f[0] = 0;
    cout << dfs(n) << endl;
}
/**
1000 1000000000 3
1000000 1000000000 1000000000
*/
