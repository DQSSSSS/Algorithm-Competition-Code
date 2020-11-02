#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;
typedef long long LL;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag = 1; a = getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a = getchar(); }
    if(flag) n=-n;
    return n;
}

int a[SZ],n;
LL m,b[SZ];

bool check(LL mid) {
    for(int i = 1;i <= n;i ++) b[i] = (mid+a[i]-1)/a[i];
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        b[i] = max(b[i],0ll);
        if(i==n&&b[i]==0) break;
        b[i+1] -= max(0ll,b[i]-1);
        ans += max(1ll,2 * b[i] - 1);
        //9cout << max(1ll,2*b[i]-1) << endl;
        if(max(1ll,2 * b[i] - 1) > m) return false;
        if(ans > m) return false;
    }
//    cout << ans << endl;
    return true;
}

int main() {
    int T = read();
    while(T --) {
        n = read();
        m = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
       // check(2); while(1);
        LL l = 0,r = 1e18;
        while(r-l>1) {
            LL mid = l + r >> 1;
            if(check(mid)) l = mid;
            else r = mid;
        }
        printf("%lld\n",l);
    }
}

/**
2
1 8
3
3 9
10 10 1
*/
