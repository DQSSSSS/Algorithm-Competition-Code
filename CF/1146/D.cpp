#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL A[SZ];

int main() {
    LL m = read(),a = read(),b = read();

    memset(A,63,sizeof A);
    LL d = __gcd(a,b);
    LL now = 0;
    A[0] = 0;
    for(LL t = a/d-1,maxx = 0; t >= 1 ;) {
        LL noww = now;
        while(noww > b) {
            noww -= b;
            A[noww] = min(A[noww],maxx);
            t --;
            if(t == 0) break;
        }
        now %= b;
        LL k = (b-now+a-1) / a;
        now += k * a;
        maxx = max(maxx,now);
    }

    LL ans = 0;
    for(int i = 0;i < a;i ++) {
        if(i % d == 0) {
            if(A[i] > m) continue;
            LL k = (A[i] - i) / a + 1;
            LL tmp1 = k * (m - A[i] + 1);
            LL n = (m-i-k*a) / a,tmp2 = 0;
            if(i+k*a <= m) tmp2 = (n+1) * (m+1-i-k*a) - n * (n+1) / 2  * a;
            ans += tmp1 + tmp2;
        //    printf("%d %lld %lld %lld\n",i,tmp1,tmp2,n);
        }
    }

    cout << ans << endl;
}
