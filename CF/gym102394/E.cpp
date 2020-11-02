#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL tim[SZ],f[SZ];
int rd[SZ],lsh[SZ];
vector<int> g[SZ];
vector<int> num[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) {
            g[i].clear(),rd[i] = 0,f[i] = 0;
            num[i].clear();
        }
        lsh[0] = 0;
        for(int i = 1;i <= n;i ++) {
            int o = read();
            if(o == 1) {
                int k = read();
                while(k --) {
                    int x;
                    num[i].push_back(x = read());
                    lsh[++ lsh[0]] = x;
                }
            }
            else {
                int x,y;
                g[i].push_back(x=read());
                g[i].push_back(y=read());
                rd[x] ++;
                rd[y] ++;
            }
        }

        sort(lsh+1,lsh+1+lsh[0]); lsh[0] = unique(lsh+1,lsh+1+lsh[0])-lsh-1;
        for(int i = 1;i <= lsh[0];i ++) tim[i] = 0;

        queue<int> q;
        for(int i = 1;i <= n;i ++) if(!rd[i]) q.push(i);
        f[n] = 1;
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int v : g[u]) {
                f[v] += f[u];
          //      cout << v << " <- " << u << endl;
                if(!-- rd[v]) {
                    q.push(v);
                }
            }
        }
        for(int i = 1;i <= n;i ++) {
            for(int x : num[i]) {
                int y = lower_bound(lsh+1,lsh+1+lsh[0],x)-lsh;
                tim[y] += f[i];
            }
        }
        LL sum = 0,mx = 0;
        //for(int i = 1;i <= n;i ++) cout << f[i] << " "; puts("");
        //for(int i = 1;i <= lsh[0];i ++) cout << tim[i] << " "; puts("");
        for(int i = 1;i <= lsh[0];i ++) {
            sum += tim[i];
            mx = max(mx,tim[i]);
        }
        printf("%lld\n",min(sum,2*sum-2*mx));
        //printf("sum:%lld mx:%lld\n",sum,mx);
    }
}
/*
233
7
1 1 1
1 1 2
2 1 2
2 2 3
2 3 4
2 4 4
2 5 6

5
1 1 1
1 1 2
2 1 2
2 1 3
2 2 3
*/
