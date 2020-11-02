#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2000 + 10;
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

int lsh[SZ];
int a[SZ];
int L[SZ];
int R[SZ];

int main() {
    int T = read(),cc = 0;
    while(T --) {
        int n = read(),m = read();
        lsh[0] = 0;
        for(int i = 1;i <= m;i ++) {
            L[i] = read();
            R[i] = read();
            lsh[++ lsh[0]] = L[i];
            lsh[++ lsh[0]] = R[i]+1;
        }
        sort(lsh+1,lsh+1+lsh[0]); lsh[0] = unique(lsh+1,lsh+1+lsh[0])-lsh-1;
        for(int i = 1;i <= lsh[0];i ++) a[i] = 0;
        for(int i = 1;i <= m;i ++) {
            L[i] = lower_bound(lsh+1,lsh+1+lsh[0],L[i])-lsh;
            R[i] = lower_bound(lsh+1,lsh+1+lsh[0],R[i]+1)-lsh;
            a[L[i]] ^= 1;
            a[R[i]] ^= 1;
        }
        int ans = 0;
        for(int i = 1;i <= lsh[0];i ++) {
            a[i] ^= a[i-1];
            if(i<lsh[0]&&a[i]) ans += lsh[i+1]-lsh[i];
        }
        //for(int i = 1;i <= lsh[0];i ++) printf("%d ",lsh[i]); puts("");
       // for(int i = 1;i <= lsh[0];i ++) printf("%d ",a[i]); puts("");

        printf("Case #%d: %d\n",++ cc,ans);
    }
}
