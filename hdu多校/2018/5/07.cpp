#include<bits/stdc++.h>
///#define Min(x,y) ((x) < (y) ? (x) : (y))
#define Min(x,y) min(x,y)
#define Max(x,y) max(x,y)
///#define Max(x,y) ((x) > (y) ? (x) : (y))
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 100010;
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

unsigned int X,Y,Z;

unsigned int RNG61() {
	X = X ^ (X << 11u);
	X = X ^ (X >> 4u);
	X = X ^ (X << 5u);
	X = X ^ (X >> 14u);
	unsigned int W = X ^ (Y ^ Z);
	X = Y;
	Y = Z;
	Z = W;
	return Z;
}

vector<pii> add[SZ];
int tree[SZ],n,m,use[SZ];

int ask(int pos) {
	pos = n - pos + 1;
	int ans = 0;
    for(int i = pos;i > 0;i -= i & -i)
    	ans = max(ans,tree[i]);
    return ans;
}

void Add(int pos,int d) {
	pos = n - pos + 1;
	for(int i = pos;i <= n;i += i & -i)
		tree[i] = max(tree[i],d);
}

int main() {
	int T = read();
	while(T --) {
        n = read(),m = read();
        X = read(),Y = read(),Z = read();
        for(register int i = 1;i <= n;i ++) add[i].clear(),tree[i] = use[i] = 0;
        for(register int i = 1;i <= m;i ++) {
            unsigned int a = RNG61();
            unsigned int b = RNG61();
            unsigned int c = RNG61();
            int l = Min(a % n + 1,b % n + 1);
            int r = Max(a % n + 1,b % n + 1);
            int v = c & ((1u << 30u) - 1);
			add[l].push_back(make_pair(v,r));
        }
        LL ans = 0;
		for(register int i = 1;i <= n;i ++) {
			for(int j = 0;j < add[i].size();j ++) {
                int c = add[i][j].first;
                int id = add[i][j].second;
                if(use[id] < c)
	                Add(id,c),use[id] = c;
			}
			ans ^= 1ll * i * ask(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
100000 5000000 654165 47894968 48964689

69084190466054
*/
