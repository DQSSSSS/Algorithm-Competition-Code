#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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

int nxt[SZ];

void getnxt(char s[]) {
	nxt[0] = nxt[1] = 0;
	int n = strlen(s);
	for(int i = 1;i < n;i ++) {
		int j = nxt[i];
		while(j && s[j] != s[i]) j = nxt[j];
		nxt[i + 1] = s[j] == s[i] ? j + 1 : 0;
	}
}

bool issub(char s[],char t[]) {
	getnxt(s);
	int n = strlen(t),m = strlen(s);
	for(int i = 0,j = 0;i < n;i ++) {
		while(j && s[j] != t[i]) j = nxt[j];
		if(s[j] == t[i]) j ++;
		if(j == m) return true;
	}
	return false;
}

char s[510][2010];

int main() {
	int T = read(),cc = 0;
	while(T --){
		int n = read();
		for(int i = 1;i <= n;i ++) {
			scanf("%s",s[i]);
		}
		int ans = -1,l = 1,r = 2;
		while(r <= n) {
			if(l == r) r ++;
			else if(issub(s[l],s[r])) l ++;
			else ans = r,r ++;
		}
	//	cout << l << " " << r << endl;
		printf("Case #%d: %d\n",++ cc,ans);
	}
	return 0;
}
