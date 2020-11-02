#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2500010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
const double PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int f[1010][1050],len,a[1010];

vector<int> g[SZ];

void fwt(int *a,int opt) {
	for(int i = 1;i < len;i <<= 1) {
        for(int j = 0,p = i << 1;j < len;j += p) {
            for(int k = 0;k < i;k ++) {
                LL x = a[j + k],y = a[i + j + k];
                a[j + k] = (x + y) % mod;
                a[i + j + k] = (x - y) % mod;
            	if(opt == -1)
                    a[j + k] = 1ll * a[j + k] * 500000004 % mod,
                    a[i + j + k] = 1ll * a[i + j + k] * 500000004 % mod;
            }
        }
	}
}

int t1[1050],t2[1050];

void multiply(int *a,int *b) {
	for(int i = 0;i < len;i ++) t1[i] = a[i],t2[i] = b[i];
    fwt(t1,1); fwt(t2,1);
	for(int i = 0;i < len;i ++) t1[i] = 1ll * t1[i] * t2[i] % mod;
    fwt(t1,-1);
    for(int i = 0;i < len;i ++) a[i] = ((LL)a[i] + t1[i]) % mod;
}

void print(int *a) {
	for(int i = 0;i < len;i ++) cout << a[i] << " "; //puts("");
}

void dfs(int u,int fa) {
	for(int i = 0;i < len;i ++) f[u][i] = 0;
    f[u][a[u]] = 1; //f[u][0] ++;
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == fa) continue;
        dfs(v,u);
        //cout << "u  : "; print(f[u]); puts("");
        //cout << "v  : "; print(f[v]); puts("");
        multiply(f[u],f[v]);
    	//cout << "ed : "; print(f[u]); puts("");
    }
}

int main() {
    int T = read();
    while(T --) {
    	int n = read(),m = read();
        len = 1; while(len < m) len *= 2;
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i < n;i ++) {
			int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1,0);
        /*for(int i = 1;i <= n;i ++,puts(""))
        	for(int j = 0;j < len;j ++)
                cout << f[i][j] << " ";*/
        for(int j = 0;j < m;j ++) {
			LL sum = 0;
			for(int i = 1;i <= n;i ++)
				(sum += f[i][j]) %= mod;
            sum += mod; sum %= mod;
            printf("%lld%c",sum,j == m - 1 ? '\n' : ' ');
		}
    }
    return 0;
}
