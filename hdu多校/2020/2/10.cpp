#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const LL mod = 1e17;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct hah {
    LL t,a,b,c,d;
}a[SZ];

int use[SZ],mark[SZ];

LL calc(int n,int k) {
    LL sum[4] = {100,100,100,100};
    for(int i = 1;i <= n;i ++) {
        if(mark[i]) {
            sum[0] += a[i].a;
            sum[1] += a[i].b;
            sum[2] += a[i].c;
            sum[3] += a[i].d;
        }
    }
    return sum[0] * sum[1] * sum[2] * sum[3];
}

int main(){
    int T = read();
    while(T --) {
        int n = read(),k = read();
        for(int i = 1;i <= n;i ++) {
            a[i].t = read();
            a[i].a = read();
            a[i].b = read();
            a[i].c = read();
            a[i].d = read();
        }
        for(int i = 1;i <= k;i ++) use[i] = 0;
        for(int i = 1;i <= n;i ++) mark[i] = 0;

        for(int i = 1;i <= n;i ++) {
            if(use[a[i].t] == 0) {
                use[a[i].t] = i;
                mark[i] = 1;
             }
        }

        while(1){
            LL ans = calc(n,k);
            bool flag = 0;
            for(int i = 1;i <= n;i ++) {
                if(mark[i] == 0) {
                    int old = use[a[i].t];
                    mark[i] = 1;
                    mark[old] = 0;
                    LL tmp = calc(n,k);
                    if(tmp > ans) {
                        flag = 1;
                        use[a[i].t] = i;
                    }
                    else {
                        mark[old] = 1;
                        mark[i] = 0;
                    }
                 }
            }
            if(!flag) break;
        }
        printf("%lld\n",calc(n,k));
    }
}
/*
233
4 2
1 49 49 0 0
1 100 0 0 0
2 49 49 0 0
2 0 100 0 0
*/
