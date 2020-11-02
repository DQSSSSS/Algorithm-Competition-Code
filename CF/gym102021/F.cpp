#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

map<int,int> mp;

int a[SZ],f[SZ];

int main() {
    int n = read();
    int one = -1;
    for(int i = 1;i <= n;i ++) {
        int x = read();
        if(x == 1) {
            if(one == -1) one = i;
            else return printf("%d %d\n",i,one),0;
        }
        mp[x] = i;
    }
    f[0] = 1; f[1] = 1;
    for(int i = 2;f[i-1] <= 1e6;i ++) {
        f[i] = f[i-1] + f[i-2];
        if(mp.count(f[i-1]) && mp.count(f[i]))
            return printf("%d %d\n",mp[f[i-1]],mp[f[i]]),0;
    }
    puts("impossible");
}

