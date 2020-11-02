#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

LL read() {
    LL n;
    scanf("%lld",&n);
    return n;
}

int fa[SZ],sz[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
    int T = read();
    while(T --) {
        int n = read(),q = read();
        for(int i = 1;i <= n;i ++) fa[i] = i,sz[i] = 1;
        LL ltk = n,rst = 0;
        while(q --) {
            int opt = read();
            if(opt == 1) {
                int x = find(read());
                int y = find(read());
                if(x != y) {
                    rst += 1ll * sz[x] * sz[y] - 1;
                    ltk --;
                    fa[x] = y;
                    sz[y] += sz[x];
                }
                else
                    rst --;
            }
            else {
                LL k = read();
                cout << ltk << " -- " << rst << endl;
                int minans = max(1ll,ltk-k);
                int maxans = max(1ll,ltk-(k-rst));
                printf("%d %d\n",minans,maxans);
            }
        }
    }
}
