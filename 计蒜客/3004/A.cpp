#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

LL GetVal(LL n,LL x,LL y){
    LL a,val;
    if (n-y+1<y && n-y+1<=x && x<=y){
        a=n-y+1;
    } else if (y<n-y+1 && y<=x && x<=n-y+1){
        a=y;
    } else if (x<n-x+1 && x<=y && y<=n-x+1){
        a=x;
    } else{
        a=n-x+1;
    }
    val=(a-1)*4*(n+1)-a*(a-1)*4;
    if (x!=n-a+1){
        val+=n-a*2+1;
        if (y!=a){
            val+=n-a*2+1;
            if (x!=a){
                val+=n-a*2+1;
                val+=x-a+1;
            } else{
                val+=y-a+1;
            }
        } else{
            val+=n-a+1-x+1;
        }
    } else{
        val+=n-a+1-y+1;
    }
    return val;
}

int n,m,q;

LL tree[SZ];
LL ans[SZ];

void add(int x,int d) {
    for(int i = x;i <= n;i += i&-i) tree[i] += d;
}

LL ask(int x) {
    LL ans = 0;
    for(int i = x;i > 0;i -= i&-i) ans += tree[i];
    return ans;
}

struct haha {
    int type,x,y,v,d;
}a[SZ];

bool cmp(haha a,haha b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.type < b.type;
}

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read(),q = read();
        int tot = 0;
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read();
            LL vv = GetVal(n,x,y);
            int val = 0;
            while(vv) val += vv%10,vv/=10;
            a[++tot] = (haha){0,x,y,val,0};
        }
        for(int i = 1;i <= n;i ++) tree[i] = 0;
        for(int i = 1;i <= q;i ++) ans[i] = 0;
        for(int i = 1;i <= q;i ++) {
            int x1 = read(),y1 = read();
            int x2 = read(),y2 = read();
            a[++tot] = (haha){1,x2,y2,i,1};
            a[++tot] = (haha){1,x2,y1-1,i,-1};
            a[++tot] = (haha){1,x1-1,y2,i,-1};
            a[++tot] = (haha){1,x1-1,y1-1,i,1};
        }
        sort(a+1,a+1+tot,cmp);
        for(int i = 1;i <= tot;i ++) {
            if(a[i].type == 0) {
                add(a[i].y,a[i].v);
            }
            else {
                ans[a[i].v] += a[i].d * ask(a[i].y);
            }
        }
        for(int i = 1;i <= q;i ++) printf("%lld\n",ans[i]);
    }
}

