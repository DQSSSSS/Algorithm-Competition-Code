#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL sum2(LL n) {
    return (n*(n+1))/2;
}

pair<LL,pll> mysol(LL a,LL b) {
    LL n = 1;
    LL flag = 0;
    if(a < b) swap(a,b),flag = 1;
    if(a >= b) {
        LL d = a - b;
        if(d >= n) {
            LL L = n,R = 1.5e9;
            while(R-L>1) {
                LL mid = L + R >> 1;
                if(sum2(mid) - sum2(n - 1) <= d) L = mid;
                else R = mid;
            }
            a -= sum2(L) - sum2(n - 1);
            n = L + 1;
        }
    }
  //  printf("0 : %lld %lld %lld\n",n,a,b);

    if(flag) {
        swap(a,b);
        if(b > a && b >= n) b -= n,n ++;
    }
   // printf("1 : %lld %lld %lld\n",n,a,b);
    if(a >= n || b >= n) {
        LL L = 0,R = min((LL)2e9,2*min(a,b) / n + 10);
        while(R-L>1) {
            LL mid = L + R >> 1;
            LL zt = (mid+1) / 2,yt = mid - zt;
            LL zuo = zt * n + (zt-1)*zt;
            LL you = yt * n + yt*yt;
            //cout << L << " " << R << endl;
            if(a < zuo || b < you) R = mid;
            else L = mid;
        }
        LL zt = (L+1) / 2,yt = L - zt;
        LL zuo = zt * n + (zt-1)*zt;
        LL you = yt * n + yt*yt;
        a -= zuo;
        b -= you;
        n += L;
       // cout << L << endl;
    }
    n --;
    return make_pair(n,make_pair(a,b));
}

pair<LL,pll> baoli(LL a,LL b) {
    LL n;
    for(n = 1;a >= n || b >= n;n ++) {
        if(a >= b) a -= n;
        else b -= n;
    }
    return make_pair(n-1,make_pair(a,b));
}

void work() {
//void work(LL a,LL b) {
    LL a = read(),b = read();
//    auto A = baoli(a,b);
    auto B = mysol(a,b);
    //puts("-------------");
   // printf("%lld %lld %lld\n",A.first,A.second.first,A.second.second);
    printf("%lld %lld %lld\n",(long long)B.first,(long long)B.second.first,(long long)B.second.second);
    /*if(A != B) {
        cout << a << " " << b << endl;
        exit(0);
    }*/
}

int main(){
   // work(1,3); return 0;
   /* for(LL a = 1e12;a <= 1e12+10;a ++) {
        for(LL b = 1e13;b <= 1e13+10;b ++) {
            work(a,b);
        }
    }*/
    int T = read();
    int cc = 0;
    while(T --) {
        printf("Case #%d: ",++ cc);
        work();
    }
    return 0;
}
/*
1000000000000000000 1000000000000000000
1000000000000 10000000000000
513906256080 513906373935
*/
