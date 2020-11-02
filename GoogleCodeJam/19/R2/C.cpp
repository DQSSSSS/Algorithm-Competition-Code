#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL lcm(LL a,LL b) {
    return a/__gcd(a,b)*b;
}

struct haha {
    LL x,y;
    haha(LL a,LL b=1) { x=a,y=b; LL d=__gcd(x,y); x/=d; y/=d; if(y<0) y=-y,x=-x; }
    void print() { printf("%lld/%lld ",x,y); }
};

bool operator <(haha o,haha a) { return o.x*a.y<o.y*a.x; }
bool operator >(haha o,haha a) { return a < o; }
bool operator ==(haha a,haha b) { return a.x==b.x&&a.y==b.y; }
haha operator /(LL o,haha a) { return haha(o*a.y,a.x); }
haha operator -(haha a,haha b) { return haha(a.x*b.y-a.y*b.x,a.y*b.y); }
bool operator >=(haha o,haha a) { return o>a||o==a; }

inline void simplify(LL &a,LL &b){
    LL g=__gcd(a,b); a/=g; b/=g;
}

pll solve(LL p1,LL q1,LL p2,LL q2){
    simplify(p1,q1); simplify(p2,q2);
    LL a=p1/q1+1,b=(LL)ceil((double)p2/q2)-1;
    if(a<=b) return pll(a,1);
    if(p1==0) return pll(1,(LL)(q2/p2)+1);
    if(p1<=q1&&p2<=q2){
        pll r=solve(q2,p2,q1,p1);
        swap(r.first,r.second);
        return r;
    }
    LL t=p1/q1;
    pll r=solve(p1%q1,q1,p2-t*q2,q2);
    r.first+=r.second*t;
    return r;
}

int X[SZ],Y[SZ];

int main() {
    int T = read(),cc = 0;
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) Y[i] = read(),X[i] = read();
        haha L(-2e9-10,1),R(2e9+10,1);
        bool flag = 0;
        for(int i = 1;i <= n;i ++) {
            for(int j = i + 1;j <= n;j ++) {
                if(X[j] < X[i] && Y[j] > Y[i]) {
                    L = max(L,haha(Y[j]-Y[i],X[j]-X[i]));
                }
                if(X[j] > X[i] && Y[j] < Y[i]) {
                    R = min(R,haha(Y[j]-Y[i],X[j]-X[i]));
                }
                if(X[j] <= X[i] && Y[j] <= Y[i]) flag = 1;
            }
        }

        swap(L,R); L.x*=-1; R.x*=-1;
        if(L < 0) L = 0;

        if(flag || L>=R) printf("Case #%d: IMPOSSIBLE\n",++ cc);
        else {

            //L.print(); R.print(); puts("");

            pll ans = solve(L.x,L.y,R.x,R.y);
            printf("Case #%d: %lld %lld\n",++ cc,ans.second,ans.first);
        }
//        printf("Case #%d: %d\n",++ cc,ans);
    }
    return 0;
}
/**
233
5
1 1
2 1
3 1
1 2
2 2

*/

