#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

int n,m;
char a[SZ];

bool check1() {
    for(int c = '0';c <= '1';c ++) {
        int minn = INF,maxn = 0;
        for(int i = 1;i <= n;i ++) {
            if(a[i] == c) {
                minn = min(minn,i);
                maxn = max(maxn,i);
            }
        }
        if(maxn - minn + 1 <= m) return true;
    }
    return false;
}

int rmx[2][SZ],rmn[2][SZ];
int lmx[2][SZ],lmn[2][SZ];

bool check2() {
    for(int c = '0';c <= '1';c ++) {
        int x = c-'0';
        rmx[x][n+1] = 0; rmn[x][n+1] = n+1;
        for(int i = n;i >= 1;i --) {
            if(a[i] == c) rmx[x][i] = max(rmx[x][i+1],i),rmn[x][i] = i;
            else rmx[x][i] = rmx[x][i+1],rmn[x][i] = rmn[x][i+1];
        }

        lmx[x][0] = 0; lmn[x][0] = n+1;
        for(int i = 1;i <= n;i ++) {
            if(a[i] == c) lmn[x][i] = min(lmn[x][i-1],i),lmx[x][i] = i;
            else lmn[x][i] = lmn[x][i-1],lmx[x][i] = lmx[x][i-1];
        }
    }

   // for(int i = 1;i <= n;i ++) printf("%d ",maxn[i]); puts("");

    for(int c = 0;c < 2;c ++) {
        for(int i = 1;i + m - 1 <= n;i ++) {
            int r = max(i+m-1,rmx[c][i+m]);
            int l = min(i,lmn[c][i-1]);
            if(r-l+1 <= m) continue;

            r = max(rmx[c^1][i+m],lmx[c^1][i-1]);
            l = min(rmn[c^1][i+m],lmn[c^1][i-1]);
            if(r-l+1 <= m) continue;
            return false;
        }
    }
    return true;
}

int main() {
    n = read(),m = read();
    scanf("%s",a+1);
    if(check1()) puts("tokitsukaze");
    else if(check2()) puts("quailty");
    else puts("once again");
}
