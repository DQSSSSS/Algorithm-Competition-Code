#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

struct frac {
    LL x,y;
    frac() {frac(0,1);}
    frac(LL xx,LL yy=1) {
        //assert(yy);
        LL d = __gcd(xx,yy);
        xx /= d; yy /= d;
        if(yy<0) xx *=-1,yy *= -1;
        x = xx; y = yy;
    }
    void print(){
        printf("%lld/%lld\n",x,y);
    }
};

frac operator +(frac a,frac b) {
    return frac(a.x*b.y+b.x*a.y,a.y*b.y);
}

frac operator -(frac a,frac b) {
    return frac(a.x*b.y-b.x*a.y,a.y*b.y);
}

frac operator *(frac a,frac b) {
    return frac(a.x*b.x,a.y*b.y);
}

frac operator /(frac a,frac b) {
    return frac(a.x*b.y,a.y*b.x);
}

bool operator <=(frac a,frac b) {
    return a.x*b.y <= b.x*a.y;
}

bool operator ==(frac a,frac b) {
    return a.x*b.y == b.x*a.y;
}

struct haha {
    LL a,b;
}a[SZ];

bool cmp(haha a,haha b) {
    return a.b*b.a < b.b*a.a;
}

mt19937 rd(time(0));

int randlr(int l,int r) {
    return rd()%(r-l+1)+l;
}

void getdata() {
    int T = 5;
    printf("%d\n",T);
    while(T --) {
        int n = 1e5,C = randlr(1,1e9);
        printf("%d %d\n",n,C);
        for(int i = 1;i <= n;i ++) {
            printf("%d %d\n",randlr(1,1000),randlr(-1000,1000));
        }
    }
}

frac ans[SZ];
int len;

int main() {
   // freopen("04.in","w",stdout); getdata(); return 0;
    freopen("04.in","r",stdin);
    freopen("04.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read();
        frac C = frac(read(),1);
        for(int i = 1;i <= n;i ++) {
            a[i].a = read(),a[i].b = -read();
        }
        sort(a+1,a+1+n,cmp);
        frac now = frac(-INF,1),nowC = frac(0,1);
        frac q = frac(0,1),h = frac(0,1);
        for(int i = 1;i <= n;i ++) h = h + frac(a[i].a,1);
       // for(int i = 1;i <= n;i ++) printf("%lld %lld\n",a[i].a,a[i].b);
        for(int i = 1;i <= n;i ++) {
            nowC = nowC + a[i].a * (frac(a[i].b,a[i].a) - now);
        }
        len = 0;
        bool flag = 0;
        for(int i = 1;i <= n + 1;i ++) {
            if(i <= n) {
                if((q-h).x == 0) {
                    if(nowC == C) {
                        flag = 1;
                        break;
                    }
                    else {
                        nowC = nowC + (frac(a[i].b,a[i].a) - now) * (q-h);
                        now = frac(a[i].b,a[i].a);
                        q = q + frac(a[i].a,1);
                        h = h - frac(a[i].a,1);
                        continue;
                    }
                }
              /*  cout << i << endl;
                now.print();
                C.print(); nowC.print();
                q.print(); h.print();*/
                frac d = (C - nowC) / (q-h);
          //      d.print();

                if(d.x > 0 && now+d <= frac(a[i].b,a[i].a)) {
                    ans[++ len] = now+d;
                }
                nowC = nowC + (frac(a[i].b,a[i].a) - now) * (q-h);
                now = frac(a[i].b,a[i].a);
                q = q + frac(a[i].a,1);
                h = h - frac(a[i].a,1);
            }
            else {
                frac d = (C - nowC) / (q-h);
                if(d.x > 0) {
                    ans[++ len] = now+d;
                }
            }
        }
        if(flag) puts("-1");
        else {
            if(len == 0) { puts("0"); continue; }
            printf("%d ",len);
            for(int i = 0;i < len;i ++) {
                printf("%lld/%lld%c",ans[i+1].x,ans[i+1].y,i+1==len?'\n':' ');
            }
        }
    }
}
