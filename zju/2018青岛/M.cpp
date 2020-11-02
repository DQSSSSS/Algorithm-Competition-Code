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

int mp[] = {1,0,0,0,1,0,1,0,2,1};

LL f(LL x) {
    LL ans = 0;
    if(x==0) return 1;
    while(x) ans += mp[x%10],x /= 10;
    return ans;
}

int main() {
    int T = read();
    while(T --) {
        LL x = read(),k = read();
        LL now = x,id = -1;
        for(int i = 1;i <= k;i ++) {
            now = f(now);
            if(now == 0) {
                id = k-i;
                break;
            }
        }
        LL ans;
        if(id == -1) ans = now;
        else {
            ans = id & 1;
        }
        printf("%lld\n",ans);
    }
}
