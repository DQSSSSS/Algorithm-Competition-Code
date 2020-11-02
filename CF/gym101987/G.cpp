#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4e5 + 10;
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

struct haha {
    LL s,w[3],d;
    int id;
}a[233];

bool cmp(haha a,haha b) {
    return a.d * b.s * b.s * b.s < b.d * a.s * a.s * a.s;
}

#define Min(x,y) ((x)<(y)?(x):(y))
#define Max(x,y) ((x)>(y)?(x):(y))

double work2(double s,double wa,double wb,double wc) {
    double ans = 0,eps = 1e-4;
    for(double x = 0;x <= s;x += eps) {
        if(Min(x+wa,s-wb)>x)
            ans += (Min(x+wa,s-wb)-x)*wb*eps;
        double a = Min(x+wa,s);
        double b = Max(x,s-wb);
        if(a>b)
            ans += (a-b)*s*eps,ans -= 0.5*(a*a-b*b)*eps;
    }
    /*for(double x = 0;x <= s;x += eps) {
        for(double y = x;y < Min(x+wa,s);y += eps) {
            if(Min(y+wb,s)>y)
                ans += (Min(y+wb,s)-y)*eps;
           // cout << y << " " << Min(x+wa,s) << endl;
        }
    }*/
    return ans;
}

LL pf(LL x) { return x * x; }
LL lf(LL x) { return x * x * x; }

LL work(LL s,LL wa,LL wb,LL wc) {
    LL tmp = 6*(s - wa - wb) * wa * wb;
    tmp += 6*wa * (s - wb) * wb;
    tmp -= 6*wb * (pf(s-wb) - pf(s-wa-wb)) / 2;

    LL ans = 0;
    if(wa >= wb) {
        LL ans2 = 0;
        ans += 6*(pf(s-wa) - pf(s-wa-wb)) / 2;
        ans += 6*(wa + wb - s) * wb;
        ans += 6*wb * (wa - wb);
        ans += 6*s * wb;
        ans -= 6*(pf(s) - pf(s-wb)) / 2;

        ans2 -= 6*(lf(s) - lf(s-wb)) / 6;
        ans2 += 6*pf(s-wb) * wb / 2;
        ans2 -= 6*(pf(s)-pf(s-wb)) * (wa-wb) / 2;
        ans2 -= 6*pf(s) * wb / 2;
        ans2 += 6*(lf(s) - lf(s-wb)) / 6;

        ans *= s;
        ans += ans2;
    }
    else {
        LL ans2 = 0;
        ans += 6*(pf(s-wb+wa) - pf(s-wb)) / 2;
        ans += 6*(wb - s) * wa;
        ans += 6*(wb - wa) * wa;
        ans += 6*s * wa;
        ans -= 6*(pf(s) - pf(s-wa)) / 2;

        ans2 -= 6*(lf(s-wb+wa) - lf(s-wb)) / 6;
        ans2 += 6*pf(s-wb) * wa / 2;
        ans2 -= 6*(pf(s-wa) - pf(s-wb)) * wa / 2;
        ans2 -= 6*(wb - wa) * pf(wa) / 2;
        ans2 -= 6*wa * pf(s) / 2;
        ans2 += 6*(lf(s) - lf(s-wa)) / 6;

        ans *= s;
        ans += ans2;
    }
    return tmp + ans;
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i].s = read();
        for(int j = 0;j < 3;j ++)
            a[i].w[j] = read();
        for(int x = 0;x < 3;x ++)
            for(int y = 0;y < 3;y ++)
                for(int z = 0;z < 3;z ++) {
                    if(x == y) continue;
                    if(z == y) continue;
                    if(z == x) continue;
                    a[i].d += work(a[i].s,a[i].w[x],a[i].w[y],a[i].w[z]);
                }
        a[i].id = i;
    }
    sort(a + 1,a + 1 + n,cmp);
    for(int i = 1;i <= n;i ++)
        printf("%d ",a[i].id);
    return 0;
}
