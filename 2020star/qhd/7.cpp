#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
const int M = 20;
ll u[M + 5], v[M + 5], d[M + 5];

int main() {
    srand(time(NULL));
    for(int i = 1; i <= M; i++) { u[i] = rand(); v[i] = rand(); }
    int T, cas = 1; scanf("%d", &T);
    while(T--) {
        int q; scanf("%d", &q);
        ll ans = 0;
        while(q--) {
            int op, x, y, w; scanf("%d%d%d", &op, &x, &y);
            if(op == 1) {
                for(int i = 1; i <= M; i++) {
                    ll t = u[i] * x + v[i] * y;
                    d[i] = __gcd(d[i], t);
                }
            } else {
                scanf("%d", &w);
                bool flag = true;
                for(int i = 1; i <= M; i++) {
                    ll t = u[i] * x + v[i] * y;
                    if(t % d[i]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) ans += w;
            }
        }
        printf("Case #%d: %lld\n", cas++, ans);
    }
    return 0;
}
