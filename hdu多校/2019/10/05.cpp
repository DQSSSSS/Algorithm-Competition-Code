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

LL b[SZ];
pll a[SZ];

LL work(pll a[],int n) {
    sort(a+1,a+1+n);
    b[n] = a[n].second;
    for(int i = n-1;i >= 1;i --) b[i] = max(b[i+1],a[i].second);
    LL ans = 2e18,minb = 2e18;
    multiset<LL> s;
    for(int i = 1;i <= n;i ++) {
        LL A = a[i].first,k = b[i+1];
        if(i == n) {
            auto it = s.lower_bound(A);
            if(it != s.end()) {
                LL B = *it;
                ans = min(ans,abs(A-B));
            }
            if(it != s.begin()) {
                it --;
                LL B = *it;
                ans = min(ans,abs(A-B));
            }
        }
        else {
            ans = min(ans,abs(A-k));
            auto it = s.lower_bound(A);
            if(it != s.end()) {
                LL B = max(*it,k);
                ans = min(ans,abs(A-B));
            }
            if(it != s.begin()) {
                it --;
                LL B = max(*it,k);
                ans = min(ans,abs(A-B));
            }
        }
        s.insert(a[i].second);
    }
    return ans;
}

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) {
            a[i].first = read();
            a[i].second = read();
        }
        LL ans = work(a,n);
        printf("%lld\n",ans);
    }
}

/**
233
4
1 100
1 3
1 4
5 2
*/
