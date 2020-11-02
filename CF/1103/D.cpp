#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000100;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int n,m,M;
LL k,p[22];
pii a[SZ];
vector<int> ok[SZ];

LL num[12010];
vector<pii> b[12010];
priority_queue<pii> q[2100];
LL f[12][2100];

int main() {
    n = read(),k = read();
    LL gcd = 0;
    for(int i = 1;i <= n;i ++) a[i].first = read(),gcd = __gcd(gcd,a[i].first);
    for(int i = 1;i <= n;i ++) a[i].second = read();

    if(gcd == 1) { return puts("0"),0; }

    for(LL i = 2;i * i <= gcd;i ++) {
        if(gcd % i == 0) {
            p[m ++] = i;
            while(gcd % i == 0) gcd /= i;
        }
    }
    if(gcd != 1) p[m ++] = gcd;

    for(int i = 1;i <= n;i ++) {
        LL x = a[i].first;
        for(int j = 0;j < m;j ++) {
            while(x % p[j] == 0) x /= p[j];
        }
        a[i].first /= x;
    }

    sort(a + 1,a + 1 + n);
    for(int i = 1,lst = 1;i <= n;i ++) {
        if(i == n || a[i].first != a[i + 1].first) {
            num[++ M] = a[i].first;
            for(int j = lst;j <= min(i,lst + m - 1);j ++)
                b[M].push_back(make_pair(a[j].second,j));
            lst = i + 1;
        }
    }

    for(int i = 1;i <= M;i ++) {
        LL c[22] = {0};
        LL x = num[i];
        for(int j = 0;j < m;j ++) {
            c[j] = 1;
            while(x % p[j] == 0) x /= p[j],c[j] *= p[j];
        }
        LL tmp[2100] = {0};
        tmp[0] = 1;
        for(int S = 1;S < (1<<m);S ++) {
            int p = __builtin_ctz(S);
            tmp[S] = tmp[S ^ (1<<p)] * c[p];
            if(tmp[S] <= k) {
                for(pii cost : b[i])
                    q[S].push(make_pair(cost.first,cost.second));
                while(q[S].size() > m) q[S].pop();
            }
        }
    }

    for(int i = 1;i < (1<<m);i ++) {
        while(q[i].size()) {
            pii u = q[i].top(); q[i].pop();
            ok[u.second].push_back(i);
        }
    }

    for(int i = 0;i <= m;i ++)
        for(int j = 0;j < (1<<m);j ++)
            f[i][j] = 1e17;
    f[0][0] = 0;

    for(int i = 1;i <= n;i ++) {
        if(ok[i].empty()) continue;
        for(int j = m;j >= 1;j --) {
            for(int S : ok[i]) {
                int bu = (1<<m)-1 - S;
                for(int S1 = bu;;S1 = (S1 - 1) & bu) {
                    f[j][S^S1] = min(f[j][S^S1],f[j-1][S1] + a[i].second);
                    if(S1 == 0) break;
                }
            }
        }
    }

    LL ans = 1e17;
    for(int i = 1;i <= m;i ++)
        ans = min(ans,i*f[i][(1<<m)-1]);
    if(ans == 1e17) puts("-1");
    else cout << ans << endl;
    return 0;
}
/**
 1    39
 2   469
 3  2369
 4  6734
 5 10808
 6 11598
 7  7815
 8  3462
 9   895
10   110
11     4
*/
