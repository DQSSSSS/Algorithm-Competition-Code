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

int get_phi(int n) {
    int ans = n;
    for(int i = 2;i * i <= n;i ++){
        if(n%i == 0) {
            ans = ans / i * (i-1);
            while(n%i == 0) n/= i;
        }
    }
    if(n != 1) ans = ans / n * (n-1);
    return ans;
}

LL ksm(LL a,LL b,LL p) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

bool islarge(LL a,LL b,LL p) {
    int ans = 1;
    for(int i = 1;i <= b;i ++) {
        if(ans >= (p + a - 1) / a) return true;
        ans *= a;
    }
    return false;
}

int a[SZ];
vector<int> g;

int dfs(int l,int r,int id) {
    int p = g[id];
    if(p == 1) return 1;
    if(l == r) {
        if(a[l] < p) return a[l];
        return a[l]%p+p;
    }
    int mi = dfs(l+1,r,id+1);
    if(a[l] == 1) return 1;

    int ans = ksm(a[l],mi,p);
   // printf("%d %d %d = %d\n",l,r,p,ans);
    return islarge(a[l],mi,p) ? ans%p+p : ans;
}

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++)a[i] = read();
    while(m != 1) {
        g.push_back(m);
      //  cout << m << endl;
        m = get_phi(m);
    }
    g.push_back(1);
    int q = read();
    while(q --) {
        int l = read(),r = read();
        printf("%d\n",dfs(l,r,0)%g[0]);
    }
}
