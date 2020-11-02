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

int n,m;
LL a[SZ];

LL check(LL mid) {
    LL ans = 0;
    for(int i = (n+1)/2;i <= n;i ++) {
        ans += max(0ll,mid-a[i]);
    }
    return ans;
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    sort(a+1,a+1+n);
    LL l = 0,r = 1e12;
    while(r-l>1) {
        LL mid = l + r >> 1;
        if(check(mid) > m) r = mid;
        else l = mid;
    }
    cout << l << endl;
}
