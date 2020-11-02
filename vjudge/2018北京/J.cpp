#include<bits/stdc++.h>
using namespace std;

typedef long long int128;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

struct Point {
    LL x,y;
    LL vx,vy;
    Point(LL _x=0,LL _y=0,LL _vx=0,LL _vy=0):x(_x),y(_y),vx(_vx),vy(_vy) { }
    Point operator -(Point &o) { return Point(x-o.x,y-o.y); }
    Point operator +(Point &o) { return Point(x+o.x,y+o.y); }
    Point getV() { return Point(vx,vy); }
}a[SZ],b[SZ],sb[SZ];

int128 operator ^(Point &a,Point &o) { return (int128)a.x*o.y-(int128)a.y*o.x; }
int128 operator *(Point &a,Point &o) { return (int128)a.x*o.x+(int128)a.y*o.y; }

int getxx(Point a) {
    if(a.x>0 && a.y>=0) return 1;
    if(a.x<=0 && a.y>0) return 2;
    if(a.x<0 && a.y<=0) return 3;
    if(a.x>=0 && a.y<0) return 4;
}

bool operator <(Point &a,Point &b) {
    if(getxx(a)!=getxx(b)) return getxx(a) < getxx(b);
    return (int128)a.x*b.y>(int128)a.y*b.x;
}

bool isSameAlpha(Point &a,Point &b) {
    if(getxx(a) != getxx(b)) return false;
    return (a^b) == 0;
}

int main() {
  //  freopen("J.in","r",stdin); freopen("2.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) {
            a[i].x = read();
            a[i].y = read();
        }

        LL ans = 0;
        LL sjx = 0,zjsjx = 0,djsjx = 0;
        for(int o = 1;o <= n;o ++) {
            int len = 0;
            for(int i = 1;i <= n;i ++) {
                if(i == o) continue;
                b[++ len] = a[i] - a[o];
                b[len].vx = b[len].x % mod;
                b[len].vy = b[len].y % mod;
                b[++ len] = a[o] - a[i];
            }
            sort(b+1,b+1+len);

            int tot = 0;
            for(int i = 1,j = 1;i <= len;i ++) {
                if(i == len || !isSameAlpha(b[i],b[i+1])) {
                    Point ans = b[j]; j++;
                    while(j<=i) {
                        ans.vx = (ans.vx + b[j].vx) % mod;
                        ans.vy = (ans.vy + b[j].vy) % mod;
                        j ++;
                    }
                    b[++ tot] = ans;
                }
            }
            len = tot;
            for(int i = 1;i <= len;i ++) {
                b[i+len].x = b[i].x;
                b[i+len].y = b[i].y;
                b[i+len].vx = b[i].vx;
                b[i+len].vy = b[i].vy;
            }
            len*=2;
            sb[1] = Point(b[1].vx,b[1].vy);
            for(int i = 2;i <= len;i ++) {
                sb[i].x = (sb[i-1].x + b[i].vx) % mod;
                sb[i].y = (sb[i-1].y + b[i].vy) % mod;
            }

          /*  printf("%d\n",o);
            for(int i = 1;i <= len;i ++) {
                printf("(%3lld,%3lld) (%3lld,%3lld)\n",b[i].x,b[i].y,b[i].vx,b[i].vy);
                //printf("(%lld,%lld)\n",b[i].vx,b[i].vy);
            }*/
           // for(int i = 1;i <= len;i ++) printf("(%lld,%lld)\n",sb[i].x,sb[i].y);

            int r3 = 1,r2 = 1;
            LL t1 = 0,t2 = 0,t3 = 0;
            for(int i = 1;i <= len/2;i ++) {
                Point now = b[i].getV();
            //    if(now.x == 0 && now.y == 0) continue;
                while(r2<=len&&b[i]*b[r2]>0) r2++;
                while(r3+1<=len&&(b[i]^b[r3+1])>0) r3++;
                Point b1 = (sb[r3] - sb[i]);
                Point b2 = (sb[r3] - sb[r2 - 1]);
                (t1 += (now ^ b1) % mod) %= mod;
                (t3 += (now ^ b2) % mod) %= mod;
          //      printf("%d %d %d %d %lld\n",i,r1,r2,r3);
            }
          //  printf("-%d %lld %lld %lld\n",o,t1,t2,t3);
            (sjx += t1) %= mod;
            (zjsjx += t2) %= mod;
            (djsjx += t3) %= mod;
        }
        //printf("%lld %lld %lld\n",sjx,zjsjx,djsjx);
        (ans += sjx * ksm(3,mod-2) % mod - zjsjx - djsjx) %= mod;
        ans += mod; ans %= mod;

        printf("%lld\n",ans);
    }
}

/**
5
5 4
2 4
3 5
3 1

7
0 0
0 1
0 -1
1 0
2 0
-1 0
-2 0

*/
