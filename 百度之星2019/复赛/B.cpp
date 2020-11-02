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

LL a,b,c,d;
char ans[SZ];

bool check() {
    if(a == b) {
        ans[0] = '\0';
        if(b == c && c == d) return true;
        return false;
    }
    if(c == d) return false;
    if((a<b)^(c<d)) return false;
    LL d1 = abs(b-a),d2 = abs(d-c);
   // cout << d1 << " " << d2 << endl;
    int len = 0;
    for(LL i = 1,t = 0;;i *= 2,t ++) {
        if(d1>d2/i) return false;
        if(d1*i==d2) {
            len = t;
            break;
        }
    }
   // cout << len << endl;
    LL dd = b - a;
    if((d-b)%dd) return false;
    if((a-c)%dd) return false;
    LL t1 = (d-b) / dd;
    LL t2 = (a-c) / dd;
    if(t1<0||t2<0) return false;
    if(t1&t2) return false;
   // cout << len << endl;
    for(LL i = 0;i < len;i ++) {
        if(t1>>i&1) ans[i] = 'A';
        else ans[i] = 'B';
    }
    ans[len] = '\0';
    return true;
}

mt19937 rd(time(0));

LL randlr(LL l,LL r) {
    LL x = (rd());
    LL y = (rd());
    LL t = (x<<32)|y;
    if(t < 0) t = -t;
    return t%(r-l+1)+l;
}

LL B = 1e18;

int main() {
    int T = read();
    while(T --) {
        a = read(),b = read(),c = read(),d = read();
       // a = randlr(-B,B); b = randlr(-B,B); c = randlr(-B,B); d = randlr(-B,B);
        //printf("%lld %lld %lld %lld\n",a,b,c,d);
        if(check()) {
            puts("Yes");
            printf("%s\n",ans);
        }
        else puts("No");
    }
}
/**
233
0
1
-1000000000000000000
1000000000000000000

-999999997820460236 -999999998954177309 -999999997479429132 -999999998560515858
*/
