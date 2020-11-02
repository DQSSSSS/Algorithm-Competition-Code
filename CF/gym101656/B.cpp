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

int tree[SZ],n,a[SZ];

void add(int x,int d) {
    for(int i = x;i <= n;i += i & -i) tree[i] += d;
}

LL ask(int x) {
    LL ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[i];
    return ans;
}

char s[SZ];

int main() {
    while(scanf("%d",&n) && n) {
        int tot = 0;
        map<string,int> mp;
        for(int i = 1;i <= n;i ++) {
            scanf("%s",s);
            string name = s;
            mp[name] = i;
        }

        for(int i = 1;i <= n;i ++) {
            scanf("%s",s);
            string name = s;
            a[mp[name]] = i;
        }
        for(int i = 1;i <= n;i ++) tree[i] = 0;
        LL ans = 0;
        for(int i = 1;i <= n;i ++) {
            ans += i-1-ask(a[i]);
            add(a[i],1);
        }
        printf("%lld\n",ans);
    }
}
