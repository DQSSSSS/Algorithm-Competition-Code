#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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

int n = 10;
int a[233],b[233];
int f[233][233];

void dfs(int d) {
	if(d == n / 2 + 1) {
		int m = n / 2;
		for(int i = 1;i <= m;i ++) {
			for(int j = 1;j <= m;j ++) {

			}
		}
	}

}


int main() {
	for(int i = 1;i <= n;i += 2) a[i / 2 + 1] = i;
	for(int i = 2;i <= n;i += 2) a[i / 2] = i;
	dfs(1);
}
