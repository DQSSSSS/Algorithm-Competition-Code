#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

int a[SZ];

int main(){
	int n = read(),k = read();
	for(int i = 1;i <= n;i ++) {
		a[i] = read();
	}
	int maxl = 0,ans = 0;
	for(int i = 1,l = 1;i <= n;i ++) {
		if(i != 1 && a[i] == a[i - 1]) l = i;
		ans = max(ans,i - l + 1);
	}
	printf("%d\n",ans);
	return 0;
}
