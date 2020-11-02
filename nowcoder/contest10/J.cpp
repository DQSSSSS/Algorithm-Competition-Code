#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 2000010;
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

vector<int> g[33];
char ans[SZ];
int len = 0;

void add(char s[]) {
	int n = strlen(s),i,pos = 1;
    for(i = 0;i < n;i ++) {
        int c = s[i] - 'a';
        int now = lower_bound(g[c].begin(),g[c].end(),pos) - g[c].begin();
        if(now == g[c].size()) break;
        //for(int j = 0;j < 2;j ++,puts(""))
        //	for(int k = 0;k < g[j].size();k ++)
        //		cout << g[j][k] << " ";
        pos = g[c][now] + 1;
    }
    while(i < n) {
    	int c = s[i] - 'a';
    	ans[++ len] = s[i];
        g[c].push_back(len);
        i ++;
    }
}

void init() {
	len = 0;
	memset(ans,0,sizeof(ans));
	for(int i = 0;i < 26;i ++) g[i].clear();
}

char s[SZ];

int main() {
	int T = read();
	while(T --) {
		init();
		int n = read();
		for(int i = 1;i <= n;i ++) {
			scanf("%s",s);
			add(s);
		}
		printf("%s\n",ans + 1);
	}
	return 0;
}
