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

char s[SZ];

int t[SZ];

int main() {
	int n = read();
	scanf("%s",s);
	for(int i = 0;i < n;i ++) t[s[i] - 'a'] ++;
	int a = 0,d = 0;
	for(int i = 0;i < 26;i ++) {
		if(t[i] >= 2)
			a = 1;
		if(t[i]) d ++;
	}
	if(d == 1) { puts("Yes"); return 0; }
	if(!a) cout << "No" << endl;
    else cout << "Yes" << endl;
	return 0;
}
