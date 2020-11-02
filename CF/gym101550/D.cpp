#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

LL f[SZ],g[SZ],a[SZ];

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        scanf("%lld",&a[i]);
    }
    int B = 1e5;
    for(int j = 0;j <= B;j ++) f[j] = -1e18;
    f[0] = 100;
    for(int i = 1;i <= n;i ++) {
        for(int j = 0;j <= B;j ++) g[j] = f[j];
        LL w = a[i];
        for(int j = 1;j <= B;j ++) {
            if(f[j-1] >= w) f[j] = max(f[j],f[j-1]-w);
        }
        for(int j = B-1;j >= 0;j --) {
            g[j] = max(g[j],g[j+1]+w);
        }
       // for(int j = 0;j <= B;j ++) printf("%10lld",g[j]); puts("");
       // for(int j = 0;j <= B;j ++) printf("%10lld",f[j]); puts("");
        for(int j = 0;j <= B;j ++) f[j] = max(f[j],g[j]);
    }
    //LL ans = 0;
    //for(int j = 0;j <= 1e5;j ++) ans = max(ans,f[j]);
    cout << f[0] << endl;
}
