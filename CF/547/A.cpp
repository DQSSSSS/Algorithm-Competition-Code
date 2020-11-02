#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
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

int use[SZ],m;
int use1[SZ],use2[SZ];

pii work(LL h,LL a,LL x,LL y) {
    for(int i = 0;i < m;i ++) use[i] = 0;
    LL X = (1ll * x * h + y) % m;
    LL ans2 = 1;
    while(X != h) {
        X = (1ll * x * X + y) % m,ans2 ++;
    }
    for(int i = 0;i < m;i ++) use[i] = 0;
    LL ans = 0;
    while(1) {
        use[h] = 1;
        ans ++;
        h = (1ll * x * h % m + y) % m;
        if(h == a) return make_pair(ans%ans2,ans2);
        if(use[h]) return make_pair(-1,ans2);
    }
}

void exgcd(LL A,LL B,LL &x,LL &y) {
    if(B == 0) {
        x = 1; y = 0; return ;
    }
    exgcd(B,A%B,x,y);
    LL t = x; x = y; y = t - A / B * y;
}

int main() {
    m = read();
    LL h1 = read(),a1 = read(),x1 = read(),y1 = read();
    LL h2 = read(),a2 = read(),x2 = read(),y2 = read();
    LL ans = 0;
    while(!(h1==a1&&h2==a2) && (!use1[h1] || !use2[h2])) {
        ans ++;
        use1[h1] = 1; use2[h2] = 1;
        h1 = (x1 * h1 + y1) % m;
        h2 = (x2 * h2 + y2) % m;
    }
   /* cout << !(h1==a1&&h2==a2) << endl;
    cout << (!use1[h1] || !use2[h2]) << endl;
    cout << ans << endl;
    cout << h1 << " " << a1 << endl;
    cout << h2 << " " << a2 << endl;*/
    if(h1 == a1 && h2 == a2) cout << ans << endl;
    else {
        pii p1 = work(h1,a1,x1,y1);
        pii p2 = work(h2,a2,x2,y2);
        if(p1.first == -1 || p2.first == -1) puts("-1");
        else {
            LL A = p1.second,B = p2.second;
            LL X = p1.first,Y = p2.first;
         //   cout << A<< " " << X << " " << B << " "<< Y << endl;
            if(X == Y) cout << X + ans << endl;
            else {
                if(Y<X) swap(X,Y),swap(A,B);
                LL d = Y-X;
                if(d % __gcd(A,B)) puts("-1");
                else {
                    LL x,y;
                    exgcd(A,B,x,y);
                    x *= d / __gcd(A,B);
                    y *= d / __gcd(A,B);
               //     cout << A << " "<< x << " "<< B << " " << y << endl;
                    x%=B/__gcd(A,B);
                    if(x < 0) x += B/__gcd(A,B);
                //    cout << x << endl;
                    cout << A * x + X + ans << endl;
                }
            }
        }

    }
}
/**
5
4 2
1 1
0 3
2 3

999999
5654 9643
2 53
1635 2234
16465 164497
*/
