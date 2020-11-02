#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 5300;
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

int mp[SZ][SZ];
char tmp[SZ];

int tot,p[SZ],mi[SZ];

void fj(int x) {
    for(int i = 2;i * i <= x;i ++) {
        if(x % i == 0) {
            p[++ tot] = i;
            while(x % i == 0) x /= i,mi[tot] ++;
        }
    }
    if(x != 1) {
        p[++ tot] = x;
        mi[tot] = 1;
    }
}

int n;

bool check(int d) {
    for(int a = 1;a <= n/d;a ++)
        for(int b = 1;b <= n/d;b ++) {
            int c = -1;
            for(int i = 1;i <= d;i ++)
                for(int j = 1;j <= d;j ++) {
                    int x = mp[(a-1)*d+i][(b-1)*d+j];
                    if(c == -1) c = x;
                    else {
                        if(c != x) return false;
                    }
                }
        }
    return true;
}

int main() {
    n = read();
    for(int i = 1;i <= n;i ++) {
        scanf("%s",tmp + 1);
        for(int j = 1;j <= n / 4;j ++) {
            char c = tmp[j];
            int d;
            if(c <= '9') d = c - '0';
            else d = c - 'A' + 10;
            for(int k = 0;k <= 3;k ++)
                if(d >> (3-k) & 1)
                    mp[i][(j-1)*4+k+1] = 1;
        }
    }
   /* for(int i = 1;i <= n;i ++,puts(""))
        for(int j = 1;j <= n;j ++)
            cout << mp[i][j];*/
    fj(n);
    int ans = 1;
    for(int i = 1;i <= tot;i ++) {
        for(int j = 1;j <= mi[i];j ++) {
            if(check(p[i])) {
                n /= p[i];
                for(int a = 1;a <= n;a ++)
                    for(int b = 1;b <= n;b ++)
                        mp[a][b] = mp[a*p[i]][b*p[i]];
                ans *= p[i];
            }
            else break;
        }
    }
    cout << ans << endl;
}
/***
4
F
F
0
0

1111
1111
0000
1
*/
