#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int INF = 1e9 + 10;
const int SZ = 1e5 + 10;

map<int,LL> mp;
map<int,int> lst;
int t,w,top,q[SZ];

bool iscz(int u) {
	for(int i = t;i <= w;i ++)
		if(q[i] == u) return true;
	return false;
}


int main() {
//	freopen("B.in","r",stdin); freopen("B.out","w",stdout);
	//freopen("233.in","w",stdout);
	int T;
	scanf("%d",&T);
	while(T --) {
		int n;
		scanf("%d",&n);
		t = 1,w = 0;
		mp.clear(); lst.clear();
		top = -1;
		for(int cc = 1;cc <= n;cc ++) {
			char opt[11];
			scanf("%s",opt);
			printf("Operation #%d: ",cc);
			if(opt[0] == 'A') { ///ADD
				int u;
				scanf("%d",&u);
				if(iscz(u)) puts("same priority.");
				else { q[++ w] = u; mp[u] = 0; puts("success."); }
			}
			else if(opt[0] == 'C' && opt[1] == 'l') { ///Close
				int u;
				scanf("%d",&u);
				if(!iscz(u)) puts("invalid priority.");
				else {
					int id = -1;
					for(int i = t;i <= w;i ++) {
						if(q[i] == u) id = i;
					}
					for(int i = id - 1;i >= t;i --) q[i + 1] = q[i];
					t ++;
					printf("close %d with %I64d.\n",u,mp[u]);
					mp[u] = 0;
					//if(u == top) top = -1;
					lst[u] = 0;
				}
			}
			else if(opt[0] == 'C' && opt[1] == 'h' && opt[2] == 'a') { ///chat
				LL w;
				scanf("%I64d",&w);
				if(t > ::w) puts("empty.");
				else {
					if(top == -1) mp[q[t]] += w,lst[q[t]] = cc;
					else mp[top] += w,lst[top] = cc;
					puts("success.");
				}
			}
			else if(opt[0] == 'R') { ///Rotate
				int x; scanf("%d",&x);
				if(x < 1 || w - t + 1 < x) puts("out of range.");
				else {
					int p = q[t + x - 1];
					for(int i = t + x - 2;i >= t;i --) q[i + 1] = q[i];
					q[t] = p;
					puts("success.");
				}
			}
			else if(opt[0] == 'P') { ///Prior
				if(t > w) puts("empty.");
				else {
					int maxn = -1,id = -1;
					for(int i = t;i <= w;i ++) {
						if(maxn < q[i]) maxn = q[i],id = i;
					}
					for(int i = id - 1;i >= t;i --) q[i + 1] = q[i];
					q[t] = maxn;
					puts("success.");
				}
			}
			else if(opt[0] == 'C' && opt[1] == 'h' && opt[2] == 'o') { ///Choose
				int u; scanf("%d",&u);
				if(iscz(u)) {
					int id = -1;
					for(int i = t;i <= w;i ++) {
						if(q[i] == u) id = i;
					}
					for(int i = id - 1;i >= t;i --) q[i + 1] = q[i];
					q[t] = u;
					puts("success.");
				}
				else puts("invalid priority.");
			}
			else if(opt[0] == 'T') { ///Top
				int u; scanf("%d",&u);
				if(iscz(u)) {
					top = u;
					puts("success.");
				}
				else puts("invalid priority.");
			}
			else { ///Untop
				if(top == -1) puts("no such person.");
				else {
					/*int id = -1;
					for(int i = t;i <= w;i ++) {
						if(q[i] == top) id = i;
					}
					for(int i = id - 1;i >= t;i --) q[i + 1] = q[i];
					q[t] = top;*/
					top = -1,puts("success.");
				}
			}
			//cout << "-- " << top << " --" << endl;
			//for(int i = t;i <= w;i ++) cout << q[i] << " "; puts("");
			//for(int i = t;i <= w;i ++) cout << mp[q[i]] << " "; puts("");
		}
		if(top != -1 && mp[top]) {
			printf("Bye %d: %I64d\n",top,mp[top]);
			int id = -1;
			for(int i = t;i <= w;i ++) {
				if(q[i] == top) id = i;
			}
			for(int i = id - 1;i >= t;i --) q[i + 1] = q[i];
			t ++;
			mp[top] = 0;
		}
		for(int i = t;i <= w;i ++) {
			if(lst[q[i]]) {
				printf("Bye %d: %I64d\n",q[i],mp[q[i]]);
			}
		}
	}
	return 0;
}


