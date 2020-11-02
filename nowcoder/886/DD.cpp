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

int n,k,a[SZ],b[SZ];

int check(int mid) {
    multiset<int> s;
    for(int i = 1;i <= n;i ++) s.insert(a[i]);
    int t = 1,now = 0;
    while(s.size()) {
        auto it = s.upper_bound(mid-now);
        if(it == s.begin()) t ++,now = 0;
        else {
            it --;
            now += *it;
            s.erase(it);
        }
        if(t>k) return INF;
    }
    return t;
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        n = read(),k = read();
        int sum = 0,maxn = 0,ans;
        for(int i = 1;i <= n;i ++) a[i] = read(),sum += a[i],maxn = max(maxn,a[i]);
        for(int i = sum / k;;i ++) {
            if(check(i) <= k) { ans = i; break; }
        }
        printf("Case #%d: %d\n",++ cc,ans);
    }
}

