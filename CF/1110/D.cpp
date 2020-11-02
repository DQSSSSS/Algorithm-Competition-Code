#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000100;
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

const int B = 2;
int f[2][B+1][B+1],a[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        int x = read();
        a[x] ++;
    }
    for(int i = 0;i <= B;i ++)
        for(int j = 0;j <= B;j ++)
            f[0][i][j] = -INF;
    f[0][0][0] = 0;
    for(int i = 1;i <= m;i ++) {
        int x = a[i];
        for(int a = 0;a <= B;a ++)
            for(int b = 0;b <= B;b ++)
                f[i&1][a][b] = -INF;
        for(int a = 0;a <= B;a ++) {
            for(int b = 0;b <= B;b ++) {
                for(int c = 0;c <= B;c ++) {
                    if(a+b+c<=x) {
                        f[i&1][b][c] = max(f[i&1][b][c],f[i&1^1][a][b] + c + (x-a-b-c)/3);
                    }
                }
            }
        }
    }
    cout << f[m&1][0][0] << endl;
    return 0;
}
