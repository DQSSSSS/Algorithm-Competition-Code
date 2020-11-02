#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

bool cmp(int a,int b) { return a > b; }
LD C[SZ][SZ],f[SZ][SZ];
vector<int> g[SZ],a;
int d[SZ],b[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int k = read();
        while(k --) {
        	int x = read();
        	g[i].push_back(x);
            a.push_back(x);
        }
    }
    sort(a.begin(),a.end(),cmp);
    int minx = a[n - 1];
    for(int i = 1;i <= m;i ++)
        for(int j = 0;j < g[i].size();j ++) {
            int x = g[i][j];
            if(x > minx) d[i] ++;
            if(x == minx) b[i] = 1;
        }
    int goalt = n,sumx = 0;
    for(int i = 0;i <a.size();i ++)
    	if(a[i] > minx) goalt --;
    	else if(a[i] == minx) sumx ++;
    C[0][0] = 1;
    for(int i = 1;i <= 1000;i ++) {
    	C[i][0] = 1;
    	for(int j = 0;j <= i;j ++)
    		C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    f[0][0] = 1;
    for(int i = 1;i <= m;i ++) {
		int sz = g[i].size();
    	for(int j = 0;j <= goalt;j ++) {
			if(b[i]) f[i][j] = f[i - 1][j] / C[sz][d[i]] + (j == 0 ? 0 : f[i - 1][j - 1] / C[sz][d[i] + 1]);
			else f[i][j] = f[i - 1][j] / C[sz][d[i]];
		}
    }
    double ans = f[m][goalt] / C[sumx][goalt];
    printf("%.13f\n",ans);
    return 0;
}
