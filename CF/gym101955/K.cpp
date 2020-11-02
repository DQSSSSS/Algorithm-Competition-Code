#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

int main(){
    int T = read(),cc = 0;
    while(T --) {
        LL n = read(),m = read(),k = read();
        LL s;
        if(k == 1) s = m-1;
        else {
            s = (k-1) % (n-m+1);
            for(LL i = n-m+2,t;i <= n;) {
                t = min(n-i+1,(i-s-1)/k);
                if(t == 0) {
                    s = (s+k) % i;
                    i ++;
                }
                else {
                    s = (s+k*t)%i;
                    i += t;
                }
            }
        }
        printf("Case #%d: %lld\n",++ cc,s + 1);
    }
}

/**
233
1000000000000000000 1000000000000000000 1
*/
