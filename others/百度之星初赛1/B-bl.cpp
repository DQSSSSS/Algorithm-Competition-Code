#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 150010;
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

deque<int> g[SZ];
int n,q;

int main() {
	freopen("B.txt","r",stdin);
	freopen("std.txt","w",stdout);
    while(~scanf("%d%d",&n,&q)) {
    	for(int i = 1;i <= n;i ++) {
			g[i].clear();
		}
		while(q --) {
			int opt = read(),u = read();
			if(opt == 1) {
                int w = read(),val = read();
				if(w == 0) g[u].push_front(val);
				else g[u].push_back(val);
			}
			else if(opt == 2) {
				int w = read(),x;
				if(g[u].empty()) x = -1;
				else if(w == 0) x = g[u].front(),g[u].pop_front();
				else x = g[u].back(),g[u].pop_back();
				printf("%d\n",x);
			}
			else {
				int v = read(),w = read();
                if(w == 0) {
					while(g[v].size())
						g[u].push_back(g[v].front()),g[v].pop_front();
				}
				else {
					while(g[v].size())
						g[u].push_back(g[v].back()),g[v].pop_back();
				}
			}
		}
    }
    return 0;
}




