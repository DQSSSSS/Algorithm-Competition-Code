#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e5 + 10;

int nxt[SZ];
void getnxt(char s[]) {
	int n = strlen(s);
	nxt[0] = nxt[1] = 0;
	for(int i = 1;i < n;i ++) {
		int j = nxt[i];
		while(j && s[i] != s[j]) j = nxt[j];
		nxt[i + 1] = s[i] == s[j] ? j + 1 : 0;
	}
}

bool issubstring(char s[],char t[]) {
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
	int T,cc = 0;
	scanf("%d",&T);
	while(T --) {
		int n;
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++) {
			scanf("%s",s[i]);
		}
		int l = 1,r = 2,ans = -1;
		while(r <= n) {
			if(l == r) r ++;
			else if(issubstring(s[l],s[r])) l ++;
			else ans = r,r ++;
		}
		printf("Case #%d: %d\n",++ cc,ans);
	}
	return 0;
}
