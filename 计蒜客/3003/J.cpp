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
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int f[SZ];
int a[SZ];

int main(){
    int T = read();
    while(T --) {
        int n = read();
        int S = 0;
        for(int i = 1;i <= n;i ++) a[i] = read(),S += a[i];
        sort(a+1,a+1+n);
        reverse(a+1,a+1+n);
        for(int i = 0;i <= S;i ++) f[i] = 0;
        f[0] = 1;
        int ans = 0;
        for(int i = 1;i <= n;i ++) {
            int t = a[i];
            //printf("[%d,%d]\n",(S-2*t+1)/2,(S-t)/2);
            for(int j = max(0,(S-2*t+1)/2);j <= min(S,(S-t)/2);j ++)
                (ans += f[j]) %= mod;
            //cout << ans << endl;
            for(int j = S;j >= t;j --) {
                (f[j] += f[j-t]) %= mod;
            }
        }
        printf("%d\n",ans);
    }
}
