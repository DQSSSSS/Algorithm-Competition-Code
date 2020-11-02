#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 5010;
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

int sg[SZ];

vector<int> get(int x) {
	vector<int> g;
	for(int i = 1;i * i <= x;i ++)
		if(x % i == 0) {
			g.push_back(i);
            if(i * i == x || i == 1) continue;
            g.push_back(x / i);
		}
	return g;
}

int main() {
	memset(sg,-1,sizeof(sg));
    sg[0] = 0; sg[1] = 0;
    for(int i = 2;i <= 1000;i ++) {
        vector<int> g = get(i);
        bool vis[SZ] = {0};
        for(int j = 0;j < g.size();j ++) {
        	int t = 0;
        	for(int k = 0;k < g.size();k ++) {
        		if(j == k) continue;
				t ^= sg[g[k]];
        	}
        	vis[t] = 1;
        }
        for(int j = 0;;j ++)
        	if(!vis[j]) {
        		sg[i] = j;
        		break;
        	}
    }
    int n;
    while(~scanf("%d",&n)) {
    	int ans = 0;
		for(int i = 1;i <= n;i ++)
			ans ^= sg[read()];
		if(ans) puts("freda");
		else puts("rainbow");
    }
}
