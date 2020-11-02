#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
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

int n,k;

LL a[SZ],sum[SZ];
pli f[SZ];

LL w(LL l,LL r) {
    if(l == r) return 0;
    if(l + 1 == r) return a[r] - a[l];
    LL mid = l + r >> 1,x = a[mid];
    return sum[r] - sum[mid] - (r-mid) * x +
        (mid - l) * x - (sum[mid-1] - sum[l-1]);
}

LL ans;

deque<int> q;

int check(LL mid) {
    f[0] = make_pair(0,0);
    for(int i = 1;i <= n;i ++) {
        while(j < i-1 && (f[j+1].first+w(j+2,i) < f[j].first+w(j+1,i) || (f[j+1].first+w(j+2,i) == f[j].first+w(j+1,i) && f[j+1].second <= f[j].second) )) j ++;
        f[i] = make_pair(f[j].first+w(j+1,i)+mid,f[j].second+1);
    }
    return f[n].second;
}

int main() {
    n = read(),k = read();
    for(int i = 1;i <= n;i ++) a[i] = read(),sum[i] = sum[i-1] + a[i];
    ans = 1e18;
    LL l = -1,r = 3e14;
    while(r - l > 1) {
        LL mid = l + r >> 1;
        if(check(mid) <= k) r = mid;
        else l = mid;
    }
    check(r);
    cout << f[n].first - f[n].second * r << endl;
    return 0;
}
