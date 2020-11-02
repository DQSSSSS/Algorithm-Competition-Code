#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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

deque<LL> q[110];
LL sumi[110];

int main() {
    int n = read(),m = read(),l = read();
    LL sum = m;
    for(int i = 1;i <= m;i ++) q[i].push_back(1),sumi[i] = 1;

    for(int k = 1;k <= n;k ++) {
        int x = read();
        if(x == -1) {
            for(int i = 1;i <= m;i ++) {
                if(q[i].size() == l) {
                    (sumi[i] -= q[i].front()) %= mod;
                    (sum -= q[i].front()) %= mod;
                    q[i].pop_front();
                }
            }
            for(int i = 1;i <= m;i ++) {
                q[i].push_back((sum - sumi[i]) % mod);
                //cout << sum - sumi[i] << endl;
            }
            for(int i = 1;i <= m;i ++) {
                (sum += q[i].back()) %= mod;
                (sumi[i] += q[i].back()) %= mod;
            }
        }
        else {
            if(q[x].size() == l) {
                (sumi[x] -= q[x].front()) %= mod;
                (sum -= q[x].front()) %= mod;
                q[x].pop_front();
            }
            for(int i = 1;i <= m;i ++) {
                if(x == i) {
                    q[i].push_back(0);
                }
                else {
                    while(q[i].size())
                        (sum -= q[i].front()) %= mod,q[i].pop_front();
                    q[i].push_back(sumi[x]);
                    sumi[i] = sumi[x]; sum += sumi[x];
                }
            }
        }
    }
    LL ans = 0;
    for(int i = 1;i <= m;i ++) {
        while(q[i].size() > 1) {
            (ans += q[i].front()) %= mod;
            //cout << q[i].front() << " ";
            q[i].pop_front();
        }
    }
    ans += mod; ans %= mod;
    printf("%lld\n",ans);
    return 0;
}
/**
3 3 2
-1 1 -1
*/
