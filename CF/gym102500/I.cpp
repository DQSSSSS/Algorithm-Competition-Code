#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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

int a[SZ],b[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) b[i] = a[i] = read();
    sort(b+1,b+1+n);
    int s = n+1,t = 0;
    for(int i = 1;i <= n;i ++) {
        if(a[i] != b[i]) {
            s = min(s,i);
            t = max(t,i);
        }
    }
    if(t == 0) return puts("1 1"),0;
    for(int i = s,j = t;i <= t;i ++,j --) {
        if(a[i] != b[j]) {
            return puts("impossible"),0;
        }
    }
    printf("%d %d\n",s,t);
}
