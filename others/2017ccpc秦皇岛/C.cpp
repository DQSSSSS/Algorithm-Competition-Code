#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1100010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

string s;
int ans;
bool use[11],vis[11];
int L[11],R[11],num[11];
int dy[11],lstpos[11];

int get(char c) {
	if(c == 'g') return 0;
	if(c == 'a') return 1;
	if(c == 'o') return 2;
}

void dfs(int d) {
	if(d == 3) {
		int tmp = 0;
		for(int i = 0;i < 9;i ++) vis[i] = 0;
		//for(int i = 0;i < 3;i ++) cout << num[i] << " "; puts("");
		for(int i = 0;i < 3;i ++){
			int c = num[i],t = 0;
			for(int j = L[c];j <= R[c];j ++) {
				if(vis[j]) continue;
				if(c == get(s[j])) vis[j] = 1;
				else t ++;
			}
			if(t == 0) tmp ++;
			//cout << t << endl;
		}
		ans = max(ans,tmp);
		//system("pause");
		return ;
	}
	if(ans == 3) return ;
	for(int i = 0;i < 3;i ++) {
		if(!use[i]) {
			use[i] = 1;
			num[d] = i;
			dfs(d + 1);
			use[i] = 0;
		}
	}
}

int main() {
	int T = read();
	while(T --) {
		cin >> s; ans = 0;
		for(int i = 0;i < 3;i ++) L[i] = 9,R[i] = -1;
		for(int i = 0;i < 9;i ++) {
			int x = get(s[i]);
			L[x] = min(L[x],i);
			R[x] = max(R[x],i);
		}
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}
