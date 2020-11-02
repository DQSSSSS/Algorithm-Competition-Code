#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-14;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct fff {
    int x,y;
    fff(){}
    fff(int _x,int _y) {
        x = _x; y = _y;
        LL d = __gcd(x,y);
        if(d<0) d=-d;
        x /= d; y /= d;
    }
};

int getxx(fff a) {
    if(a.x>0 && a.y>=0) return 1;
    if(a.x<=0 && a.y>0) return 2;
    if(a.x<0 && a.y<=0) return 3;
    if(a.x>=0 && a.y<0) return 4;
}

bool operator <(fff a,fff b) {
    if(getxx(a)!=getxx(b)) return getxx(a) < getxx(b);
    return 1ll*a.x*b.y>1ll*a.y*b.x;
}

LL operator *(fff a,fff b) {
    return 1ll*a.x*b.y-1ll*a.y*b.x;
}

bool operator ==(fff a,fff b) {
    return a.x==b.x && a.y==b.y;
}

struct haha {
    int x,y;
}a[SZ];

LL s[SZ],sj[SZ],c[SZ];

struct hh {
    fff a;
    int v[2];
}b[SZ],bb[SZ];

bool cmp2(hh a,hh b) {
    return a.a<b.a;
}

int main() {
 //   freopen("F.in","r",stdin); freopen("my.out","w",stdout);
    int n = read();
    for(int i = 1;i <= n;i ++) a[i].x = read(),a[i].y = read();
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {

        LL X = a[i].x;
        LL Y = a[i].y;

        int len = 0;
        for(int j = 1;j <= n;j ++) {
            if(j!=i) {
                fff alpha = fff(a[j].x-X,a[j].y-Y);
                b[++ len].a = alpha; b[len].v[0] = 1; b[len].v[1] = 0;
                fff beta = fff(-a[j].x+X,-a[j].y+Y);
                b[++ len].a = beta; b[len].v[0] = 0; b[len].v[1] = 1;
            }
        }

        //for(int j = 1;j <= len;j ++) printf("b1:%d %lld/%lld %d %d\n",j,b[j].a.x,b[j].a.y,b[j].v[0],b[j].v[1]); puts("");
        sort(b+1,b+1+len,cmp2);
        //for(int j = 1;j <= len;j ++) printf("b2:%d %lld/%lld %d %d\n",j,b[j].a.x,b[j].a.y,b[j].v[0],b[j].v[1]); puts("");

        int l = 0;
        for(int j = 1,lst = 1;j <= len;j ++) {
            if(j == len || !(b[j].a == b[j+1].a)) {
                int x = 0,y = 0;
                for( ; lst <= j; lst ++) x += b[lst].v[0],y += b[lst].v[1];
                l ++;
                bb[l].a = b[j].a;
                bb[l].v[0] = x;
                bb[l].v[1] = y;
            }
        }
        for(int j = 1;j <= l;j ++) bb[j+l] = bb[j]; l*=2;
        for(int j = 1;j <= l;j ++) c[j] = c[j-1] + bb[j].v[1];
        for(int j = 1;j <= l;j ++) s[j] = s[j-1] + bb[j].v[0];
        for(int j = 1;j <= l;j ++) sj[j] = sj[j-1] + c[j]*bb[j].v[0];
        LL tmp = 0;
       /* for(int j = 1;j <= l;j ++) printf("%d %lld/%lld %d %d\n",j,bb[j].a.x,bb[j].a.y,bb[j].v[0],bb[j].v[1]); puts("");
        for(int j = 1;j <= l;j ++) printf("%lld ",s[j]); puts("");
        for(int j = 1;j <= l;j ++) printf("%lld ",sj[j]); puts("");*/
        for(int j = 1,k = 1;j <= l/2;j ++) {
            if(!bb[j].v[1]) continue;
            if(k<j) k=j;
            while(k<l && bb[j].a * bb[k+1].a > 0) k ++;
            LL t = (c[k]*(s[k-1]-s[j]) - (sj[k-1]-sj[j])) * bb[j].v[1];
          //  printf("[%d,%d] %lld\n",j,k,t);
            tmp += t;
        }
       // printf("%d %lld\n",i,tmp);
        assert(tmp%3==0);
        ans += tmp;
    }
    assert(ans%3==0);
    cout << ans / 3 << endl;
}

/**
10
-5 -2
5 -1
4 3
-4 -4
-5 -1
-5 -1
-3 1
1 -5
-3 1
3 5

5
0 0
3 4
4 -1
3 -4
*/
