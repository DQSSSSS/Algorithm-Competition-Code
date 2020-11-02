#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int n,use[233],ans = 0,num[SZ];
vector<int> g[2333];

bool check() {
	if(num[1] != 1) return false;
	if(num[2] != 2 && num[2] != 3) return false;
	if(num[6] != 2 && num[6] != 3) return false;
    if(num[3] < 4 || num[3] > 6) return false;
    if(num[5] < 7 || num[5] > 8) return false;
	return true;
}

void dfs(int d) {
    if(d == n + 1) {
        if(check()) {
	        ans ++;
	    	for(int i = 1;i <= n;i ++)
	    		cout << num[i] << " "; puts("");
	    }
    	return ;
    }
    for(int i = 1;i <= n;i ++) {
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
    	n = read();
    	for(int i = 1;i <= n;i ++) g[i].clear();
//    	for(int i = 1;i <= n;i ++) b[i] = read();
        for(int i = 1;i < n;i ++) {
        	int x = read(),y = read();
        	g[x].push_back(y);
        	g[y].push_back(x);
        }
        dfs(1);
        printf("%d\n",ans);
    }
}
