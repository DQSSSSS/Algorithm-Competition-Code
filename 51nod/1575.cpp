#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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

int main() {
    UI ans = 0;
    int n; cin >> n;
    for(int i = 1;i <= n;i ++)
    	for(int j = 1;j <= n;j ++)
    		for(int k = 1;k <= n;k ++)
    			ans += __gcd(i,j)*__gcd(i,k)/__gcd(__gcd(i,j),__gcd(i,k));
    //ans += n * (n + 1) >> 1;
    //ans >>= 1;
   	cout << ans - 246548 * 2<< endl;
   	return 0;
}
