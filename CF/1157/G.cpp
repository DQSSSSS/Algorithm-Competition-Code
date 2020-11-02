#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 8e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int r[210],c[210],n,m;
int a[210][210];
int b[210][210];

bool check() {
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            b[i][j] = a[i][j] ^ c[j];
        }
    }

    for(int i = 1,f = 0;i <= n;i ++) {
        int one = 0,zero = 0;
        for(int j = 1;j <= m;j ++) {
            if(b[i][j] == 0) zero ++;
            else one ++;
        }
        bool allone = one == m;
        bool allzero = zero == m;
        if(f == 0) {
            if(allone) r[i] = 1;
            else if(allzero) r[i] = 0;
            else {
                f = 1;
                int lstone,lstzero;
                for(int j = 1;j <= m;j ++) {
                    if(b[i][j] == 1) lstone = j;
                    if(b[i][j] == 0) lstzero = j;
                }
                if(lstone == one) r[i] = 1;
                else if(lstzero == zero) r[i] = 0;
                else return false;
            }
        }
        else {
            if(allone) r[i] = 0;
            else if(allzero) r[i] = 1;
            else return false;
        }
    }
    return true;
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            a[i][j] = read();
        }
    }

    for(int i = 1;i <= m;i ++) {
        if(a[1][i] == 1) c[i] = 1;
        else c[i] = 0;
    }
    if(check()) {
        puts("YES");
        for(int i = 1;i <= n;i ++) printf("%d",r[i]); puts("");
        for(int i = 1;i <= m;i ++) printf("%d",c[i]); puts("");
        return 0;
    }

    for(int i = 1;i <= m;i ++) {
        if(a[n][i] == 1) c[i] = 1;
        else c[i] = 0;
    }
    if(check()) {
        puts("YES");
        for(int i = 1;i <= n;i ++) printf("%d",r[i]); puts("");
        for(int i = 1;i <= m;i ++) printf("%d",c[i]); puts("");
        return 0;
    }

    puts("NO");
}
