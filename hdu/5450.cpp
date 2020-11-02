#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 10007;
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

int mi[22];

int get(int S,int pos) {
    return S / mi[pos - 1] % 3;
}

void add(int &a,int b) {
    a += b;
    if(a >= 1e9) a %= mod;
}

int f[110][200010],c[22],to[5],a[5];
bool b[110];

int main() {
    mi[0] = 1;
    for(int i = 1;i <= 12;i ++) mi[i] = mi[i - 1] * 3;
    int T = read(),cc = 0;
    while(T --) {
        int n = read(),p = read();
        int maxs = 1;
        for(int i = 1;i <= p + 2;i ++) maxs *= 3;
        for(int i = 1;i <= n;i ++) {
            b[i] = 0;
            for(int j = 0;j <= maxs;j ++) f[i][j] = 0;
        }
        int q = read();
        while(q --) b[read()] = 1;
        
        
        to[1] = 1; to[2] = p; to[3] = p + 2;
        f[0][maxs - 1] = 1;
        for(int i = 1;i <= n;i ++) {
            for(int S = 0;S < maxs;S ++) {
                int nx = S * 3 % maxs;
                
                if(b[i]) {
                    nx += 2;
                    if(get(S,p + 2) == 2)
                        add(f[i][nx],f[i - 1][S]);
                    continue;
                }
                
                a[1] = get(S,to[1]);
                a[2] = get(S,to[2]);
                a[3] = get(S,to[3]);
                
                if(a[3] == 2) 
                    add(f[i][nx],f[i - 1][S]);
                
                for(int j = 1;j <= 3;j ++) {
                    if(a[j] < 2) {
                        if(to[j] != p + 2) {
                            if(a[3] == 2)
                                add(f[i][nx + 1 + mi[to[j]]],f[i - 1][S]);
                        }
                        else if(to[j] == p + 2 && a[3] == 1) {
                            add(f[i][nx + 1],f[i - 1][S]);
                        }
                    }
                }
                
                for(int j = 1;j <= 2;j ++) {
                    for(int k = j + 1;k <= 3;k ++) {
                        if(a[j] < 2 && a[k] < 2) {
                            if(to[k] != p + 2) {
                                if(a[3] == 2)
                                    add(f[i][nx + 2 + mi[to[j]] + mi[to[k]]],f[i - 1][S]);                                
                            }
                            else {
                                if(a[3] == 1)
                                    add(f[i][nx + 2 + mi[to[j]]],f[i - 1][S]);
                            }
                        }
                    }
                }
                
            }
        }
        
        printf("Case #%d: %d\n",++ cc,f[n][maxs - 1] % mod);
    }
    return 0;
}
