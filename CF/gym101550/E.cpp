#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

int get_phi(int n) {
    int ans = n;
    for(int i = 2;i * i <= n;i ++) {
        if(n % i == 0) {
            ans = ans / i * (i-1);
            while(n%i==0) n /= i;
        }
    }
    if(n != 1) ans = ans / n * (n-1);
    return ans;
}

LL mul(LL a,LL b,LL p) {
    return a*b<p ? a*b : a*b%p+p;
}

LL ksm(LL a,LL b,LL p) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = mul(ans,a,p);
        a = mul(a,a,p);
        b >>= 1;
    }
    return ans;
}

int dfs(int n,int p) {
    if(n == 1) return n % p;
    if(p == 1) return 1;
    int pp = get_phi(p);
    int t =  dfs(n-1,pp);
    int ans = ksm(n,t,p);
    //printf("%d %d %d\n",n,p,ans);
    return ans;
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    cout << dfs(n,m) % m << endl;
}
