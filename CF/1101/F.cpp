#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
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

struct haha {
    int l,r,b,k;
}a[SZ];

bool cmp(haha a,haha b) { return a.l < b.l; }

int b[SZ],w[SZ];
int f[410][410];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) b[i] = read();

    for(int i = 1;i <= m;i ++) {
        a[i].l = read();
        a[i].r = read();
        a[i].b = read();
        a[i].k = read();
    }

    sort(a+1,a+1+m,cmp);

    int j = 1;
    LL ans = 0;
    for(int l = 1;l <= n;l ++) {
        for(int i = l;i <= n;i ++) w[i-l+1] = b[i];
        int len = n-l+1;
        for(int i = 1;i <= len;i ++) f[i][1] = w[i] - w[1];
        for(int k = 2;k < len;k ++) {
            int p = 1;
            for(int i = 2;i <= len;i ++) {
                while(p+1 < i && max(f[p][k-1],w[i]-w[p]) >
                        max(f[p+1][k-1],w[i]-w[p+1])) p ++;
                f[i][k] = max(f[p][k-1],w[i]-w[p]);
            }
        }


        while(a[j].l < l) j ++;
        while(j <= m && a[j].l == l) {
            int len = a[j].r - a[j].l + 1;
            int k = min(a[j].r - a[j].l,a[j].k+1);
       //     printf("%d %d %d %d\n",l,len,k,f[len][k]);
            ans = max(ans,1ll * f[len][k] * a[j].b);
            j ++;
        }
    }
    cout << ans << endl;
}
