#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 9;

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

int a[SZ]

int main()
{
	int n = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	sort(a + 1,a + 1 + n);
	if(n & 1) cout << a[n / 2 + 1] << endl;
	else cout << a[n / 2] << endl;
	return 0;
}
