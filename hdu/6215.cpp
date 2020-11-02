#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef double LD;
typedef pair<LL,LL> pii;
const int SZ = 2100010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;
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

int a[SZ],nx[SZ],pr[SZ];
bool is_del[SZ];

bool can_del(int id) {
	bool f1 = 1,f2 = 1;
	if(!pr[id] || a[pr[id]] <= a[id]) f1 = 0;
	if(!nx[id] || a[id] <= a[nx[id]]) f2 = 0;
	return f1 | f2;
}

void del(int id) {
	is_del[id] = 1;
	nx[pr[id]] = nx[id];
	pr[nx[id]] = pr[id];
}

int S[SZ],tmp[SZ],top,need_del_node[SZ];

int main() {
	int T = read();
	while(T --) {
		int n = read();
		top = 0;
		for(int i = 1;i <= n;i ++) {
			a[i] = read();
			is_del[i] = 0;
			pr[i] = i - 1; nx[i] = i + 1;
		}
		nx[n] = 0; nx[0] = 1; pr[0] = n;
		for(int i = 1;i <= n;i ++) {
			if((i == 1 || !can_del(i - 1)) && can_del(i))
				S[++ top] = i;
		}
		//for(int i = 0;i <= n;i ++) cout << pr[i] << " "; puts("");
		//for(int i = 0;i <= n;i ++) cout << nx[i] << " "; puts("");
		//cout << top << endl;
		while(top) {
			tmp[tmp[0] = 0] = 0;
		//	for(int i = 1;i <= top;i ++) cout << S[i] << " "; puts("");
			while(top) {
				int x = S[top --];
				if(is_del[x]) continue;
				if(pr[x] && !is_del[pr[x]])
					tmp[++ tmp[0]] = pr[x];
				int t = 0;
				while(x && can_del(x)) {
					need_del_node[++ need_del_node[0]] = x;
					x = nx[x];
	//				for(int i = 0;i <= n;i ++) cout << pr[i] << " "; puts("");
	//				for(int i = 0;i <= n;i ++) cout << nx[i] << " "; puts("");
	//				cout << x << " ";
				}
	//			puts("");
//				cout << need_del_node[0] << endl;
//				puts("");
			}
		//	cout << need_del_node[0] << endl;
			while(need_del_node[0]) 
				del(need_del_node[need_del_node[0] --]);
		//	cout << "233" << endl;
		//	for(int i = nx[0];i;i = nx[i])
		//		printf("%d ",a[i]); puts("");
			while(tmp[0]) {
				int x = tmp[tmp[0] --];
				if((!pr[x] || !can_del(pr[x])) && can_del(x))
					S[++ top] = x;
			}
		}
		int ans = 0;
		for(int i = nx[0],t = 1;i;i = nx[i],t ++) ans ++;
		printf("%d\n",ans);
		for(int i = nx[0],t = 1;i;i = nx[i],t ++)
			printf("%d ",a[i],t == ans ? '\n' : ' ');
		puts("");
	}
	return 0;
}
/**
233
13
5 6 5 4 6 10 9 4 5 4 9 8 7
1  2 3 4 5  6 7 8 9 10 11 12 13
5 6 5 4 6 10 9 4 5 4 9 8 7
*/
