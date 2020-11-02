#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 2000010;
const int INF = 1e9 + 10;
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

LL ksm(LL a,LL b,LL mod) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int getG(int p) {
    if(p == 2) return 1;
    vector<int> getGtmp;
    int x = p - 1;
    for(int i = 2;i <= x;i ++) if(x % i == 0) getGtmp.push_back(i);
    for(int k = 2;;k ++)
        for(int i = 0;i < getGtmp.size();i ++) {
            if(ksm(k,getGtmp[i],p) == 1) {
                if(getGtmp[i] == x)
                    return k;
                else break;
            }
        }
}

int main() {
    int T = read();
    while(T --) {
        int n = read();
        int g = getG(n+1);
        for(int i = 1;i <= n;i ++) {
            printf("%d %d\n",i,ksm(g,i-1,n+1));
        }
    }
}
