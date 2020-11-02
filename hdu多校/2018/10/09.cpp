#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
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

int phi[SZ],a[SZ];

int main(){
/*
	int tot = 0;
    for(int i = 1;i <= 10;i ++)
    	for(int j = 1;j <= i - 1;j ++) {
			a[++ tot] = make_pair(i + j,i - j);
    	}
    sort(a + 1,a + 1 + tot);
    cout << tot << endl;
    for(int i = 1;i <= tot;i ++)
    	cout << a[i].first << " "<< a[i].second << " "<< a[i].first + a[i].second << endl;
    */
    int n = 100;
    for(int i = 1;i <= n;i ++) {
		int ans = 0;
		for(int j = 1;j <= i;j ++)
    		if(__gcd(i,j) == 1)
    			ans ++;
		phi[i] = ans;
    }

	for(int i = 1;i <= n;i ++) {
		int ans = 0;
		for(int j = 1;j <= i - 1;j ++)
    		if(__gcd(2 * i,j) == 1)
    			ans ++;
		a[i] = ans;
    }
    for(int i = 1;i <= n;i ++) printf("%d %3d %3d\n",i,phi[i],a[i]);
}
