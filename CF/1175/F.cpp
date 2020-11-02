#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
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

int a[SZ];
ULL b[SZ],c[SZ],num[SZ];
int n;

LL work() {
    LL ans = 0;
    for(int i = 1;i <= n;i ++) num[i] = num[i-1] ^ b[a[i]];
    for(int i = 1;i <= n;i ++) {
        if(a[i] == 1) {
            int j,maxn = 0;
            for(j = i + 1;j <= n && a[j] != 1;j ++) {
                maxn = max(maxn,a[j]);
                if(j-maxn >= 0 && (num[j] ^ num[j-maxn]) == c[maxn]) {
                    ans ++;
                //    printf("%d %d\n",j-maxn+1,j);
                }
            }
            i = j-1;
        }
    }
    return ans;
}

mt19937 rd(time(0));

int main() {
    n = read();
    for(int i = 1;i <= n;i ++) b[i] = (ULL)rd() << 32 | rd();
    for(int i = 1;i <= n;i ++) c[i] = b[i] ^ c[i-1];
    for(int i = 1;i <= n;i ++) a[i] = read();
    LL ans = work();
    reverse(a+1,a+1+n);
    ans += work();
    for(int i = 1;i <= n;i ++) if(a[i] == 1) ans ++;
    cout << ans << endl;
}
