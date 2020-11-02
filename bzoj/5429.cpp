#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1000000010;
const int mod = 998244353;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int a[SZ],b[SZ],f[SZ];

int main() {
	int n = read(),k = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	int ans = 0;
	f[1] = 1;
	for(int i = 1;i <= k;i ++)
		for(int j = 1;j <= n;j ++)
			f[log[i] + log[a[j]]] += f[log[i]];
	cout << ans << endl;
	return 0;
}
