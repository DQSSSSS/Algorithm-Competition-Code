#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 10007;
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

int S(LL x) {
	int ans = 0;
	while(x) ans += x % 10,x /= 10;
	return ans;
}

int main() {
	LL n = read();
	LL t = 1,b = 0;
	while(t <= n) t *= 10,b ++;
	//cout << t << " " << b << endl;
	int ans2 = (b-1)*9 + S(n-t/10+1);
	cout << ans2 << endl;
	return 0;
}
