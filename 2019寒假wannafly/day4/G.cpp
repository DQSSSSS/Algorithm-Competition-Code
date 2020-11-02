#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 800100;
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

LL ans;
int num[222],use[222];

void dfs(int d,int n) {
    if(d == n + 1) {
        int flag = 0,*a = num;
        for(int i = 2;i <= n;i ++)
            if((i % 2 == 1 && a[i-1]>a[i]) || (i % 2 == 0 && a[i-1]<a[i]))
                flag = 1;
        if(!flag) {
            ans ++;
            //for(int i = 1;i <= n;i ++) cout << a[i] << " "; puts("");
        }
        return ;
    }
    for(int i = 1;i <= n;i ++) {
        if(!use[i]) {
            use[i] = 1;
            num[d] = i;
            dfs(d+1,n);
            use[i] = 0;
        }
    }
}

int f[1010][1010];

LL baoli(int n) {
    ans = 0;
    dfs(1,n);
    return ans;
}

LL work(int n) {
    LL ans = 0;
    for(int i = 1;i <= n;i ++)
        (ans += f[n][i]) %= mod;
    return ans;
}

int main() {
    int n = 100;
    f[1][1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(i & 1) { ///ji
            for(int j = 2;j <= i;j ++)
                for(int k = 1;k < j;k ++)
                    (f[i][j] += 1ll * f[i-1][k] % mod) %= mod;
        }
        else { ///ou
            for(int j = 1;j < i;j ++) {
                for(int k = j+1;k < i;k ++) {
                    (f[i][j] += 1ll * f[i-1][k] % mod) %= mod;
                }
                f[i][j] += f[i-1][i-1];
            }
        }
    }
    for(int i = 1;i <= 5;i ++,puts(""))
        for(int j = 1;j <= i;j ++)
            cout << f[i][j] << " ";
    int N;
    //while(~scanf("%d",&N))
    //    cout << baoli(N) << " " << work(N) << endl;
    for(int i = 1;i <= 10;i ++) cout <<baoli(i) << endl;
    return 0;
}
