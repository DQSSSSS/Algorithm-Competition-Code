#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3e5 + 10;
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

pii a[SZ];
int f[SZ];

int main() {
    int n = read(),w = read();
    for(int i = 1;i <= n;i ++) {
        a[i].first = read(); a[i].second = i;
    }
    sort(a + 1,a + 1 + n);
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        int tmp = 1;
        for(int j = 1;j < i;j ++) {
            if(a[j].first == a[i].first) continue;
            if(a[i].second - w <= a[j].second && a[j].second <= a[i].second + w)
                tmp = max(tmp,f[j] + 1);
        }
        f[i] = tmp;
        ans = max(ans,tmp);
    }
    printf("%d",ans - 1);
    return 0;
}
/**
2000010000 2000000000
*/

