#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e5 + 10;
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

struct haha {
    int h,c,p;
}a[SZ];

bool cmp(haha a,haha b) {
    //if(a.h != b.h) return a.h < b.h;

    return a.h < b.h;
}

LL c[SZ],b[SZ];

int main() {
    int n;
    while(~scanf("%d",&n)) {
        for(int i = 1;i <= n;i ++) a[i].h = read(),a[i].c = read(),a[i].p = read();
        sort(a+1,a+1+n,cmp);
        b[n+1] = 0;
        for(int i = n;i >= 1;i --) b[i] = b[i+1] + 1ll * a[i].p * a[i].c;
        for(int i = 200;i >= 1;i --) c[i] = 0;

        LL ans = 2e18,sum = 0;
       // for(int i = 1;i <= n;i ++) cout << b[i] << " "; puts("");
        for(int i = 1,lst = 1;i <= n;i ++) {
            if(i == n || a[i+1].h != a[i].h) {
                LL now = 0;
                for(int j = lst;j <= i;j ++) now += a[j].p;
                LL tmp = 0;
                LL goal = max(sum - (now - 1),0ll);
                for(int j = 1;j <= 200;j ++) {
                    if(!goal) break;
                    LL d = min(c[j],goal);
                    tmp += d * j;
                    goal -= d;
                }
             //   printf("%lld %lld\n",goal,tmp+b[i+1]);
                ans = min(ans,tmp+b[i+1]);
                for(int j = lst;j <= i;j ++) {
                    sum += a[j].p;
                    c[a[j].c] += a[j].p;
                }
                lst = i + 1;
            }
        }
        printf("%lld\n",ans);
    }
}
