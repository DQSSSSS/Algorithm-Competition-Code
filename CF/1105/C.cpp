#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
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

LL f[SZ][3],t[3];

int main() {
    int n = read(),l = read(),r = read();
    while(l <= r && l % 3 != 0) t[l%3]++,l++;
    while(l <= r && r % 3 != 2) t[r%3]++,r--;
    if(l <= r) {
        int k = r - l + 1; k /= 3;
        for(int i = 0;i < 3;i ++) t[i] += k;
    }
    f[0][0] = 1;
    for(int i = 1;i <= n;i ++) {
        for(int j = 0;j < 3;j ++) {
            for(int k = 0;k < 3;k ++) {
                (f[i][(j+k)%3] += f[i-1][j] * t[k] % mod) %= mod;
            }
        }
    }
    cout << f[n][0] << endl;
}
