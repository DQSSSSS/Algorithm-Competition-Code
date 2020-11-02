#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e5 + 10;
const int INF = 1e9 + 10;
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

int f[110][110];

int main() {
    int n = read(),v = read();
    memset(f,63,sizeof f);
    f[0][1] = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 0;j <= v;j ++) {
            if(j < v) f[i][j] = min(f[i][j],f[i-1][j+1]);
            if(j) f[i][j] = min(f[i][j],f[i][j-1]+i);
        }
    cout << f[n][0] << endl;
}
