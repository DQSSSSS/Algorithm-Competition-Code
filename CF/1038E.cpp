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

int id[5][5],ff[22],tt[22];

int tr[5],tc[5],rd[5],cd[5];

bool check(const int &S) {
	for(int i = 1;i <= 4;i ++) tr[i] = rd[i],tc[i] = cd[i];
	for(int i = 0;i < 16;i ++) {
		cur[ff[i]][tt[i]] = 0;
		if(S >> i & 1) {
			if(g[i].empty()) return false;
			cur[ff[i]][tt[i]] = 1;
			tc[ff[i]] --;
			tr[tt[i]] --;
		}
	}
			
}

int main() {
	for(int i = 1,k = 0;i <= 4;i ++)
		for(int j = 1;j <= 4;j ++)
            id[i][j] = k,ff[k] = i,tt[k] = j,k ++;
    int n = read(),sum = 0;
    for(int i = 1;i <= n;i ++) {
        int x = read(),y = read(),z = read();
        g[id[x][z]].push_back(y);
    	sum += y;
        cd[x] ++; rd[z] ++;
    }
    for(int i = 0;i < 16;i ++) sort(g[i].begin(),g[i].end());
    int ans = 0;
    for(int S = 0;S < (1 << 16);S ++) {
        if(check(S)) {
            for(int i = 0;i < 16;i ++)
            	if((S >> i & 1) && g[i].size())
	                tmp += g[i][0];
	        ans = max(ans,sum - tmp);
        }
    }
    printf("%d\n",ans);
    return 0;
}
