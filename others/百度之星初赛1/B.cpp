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

struct node {
	node *pr,*nx;
	int v;
    node(int val):pr(NULL),nx(NULL),v(val) {}
};

struct haha {
	node *t,*w;
    int sz;
    haha() { t = w = NULL; sz = 0; }
	int front() {
		return t -> v;
	}
	int back() {
		return w -> v;
	}
	void push_front(int x) {
        sz ++;
        if(sz == 1) {
        	t = w = new node(x);
        	return ;
        }
        t -> pr = new node(x);
        t -> pr -> nx = t;
        t = t -> pr;
	}
	void push_back(int x) {
        sz ++;
        if(sz == 1) {
        	t = w = new node(x);
        	return ;
        }
        w -> nx = new node(x);
        w -> nx -> pr = w;
        w = w -> nx;
	}
	bool empty() { return sz == 0; }
	int size() { return sz; }
	void pop_front() {
        sz --;
        if(sz == 0) {
            delete t;
            t = w = NULL;
            return ;
        }
        t = t -> nx;
        delete t -> pr;
        t -> pr = NULL;
	}
	void pop_back() {
        sz --;
        if(sz == 0) {
            delete w;
            t = w = NULL;
            return ;
        }
        w = w -> pr;
        delete w -> nx;
        w -> nx = NULL;
	}
	void clear() {
        while(sz)
            pop_front();
	}
}g[SZ];

int n,q;
bool rev[SZ];
int pr[SZ];

int ask_front(int id) {
    if(rev[id]) return g[id].back();
    else return g[id].front();
}

void del_front(int id) {
	if(rev[id]) g[id].pop_back();
    else g[id].pop_front();
}

int ask_back(int id) {
    if(!rev[id]) return g[id].back();
    else return g[id].front();
}

void del_back(int id) {
	if(!rev[id]) g[id].pop_back();
    else g[id].pop_front();
}

void add_back(int id,int w) {
	if(!rev[id]) g[id].push_back(w);
    else g[id].push_front(w);
}

void add_front(int id,int w) {
	if(rev[id]) g[id].push_back(w);
    else g[id].push_front(w);
}

int main() {
	//freopen("B.txt","r",stdin);
	//freopen("my.txt","w",stdout);

    while(~scanf("%d%d",&n,&q)) {
    	for(int i = 1;i <= n;i ++) {
			pr[i] = i;
			rev[i] = 0;
		}
		while(q --) {
			int opt = read(),u = read(),uu = u;
			u = pr[u];
			if(opt == 1) {
                int w = read(),val = read();
				if(w == 0) add_front(u,val);
				else add_back(u,val);
			}
			else if(opt == 2) {
				int w = read(),x;
				if(g[u].empty()) x = -1;
				else if(w == 0) x = ask_front(u),del_front(u);
				else x = ask_back(u),del_back(u);
				printf("%d\n",x);
			}
			else {
				int v = read(),w = read();
				int vv = v;
                v = pr[v];
                if(g[v].size() > g[u].size()) {
                	pr[uu] = v;
                	pr[vv] = u;
                    swap(u,v);

                    if(w == 0) {
						while(g[v].size())
							add_front(u,ask_back(v)),del_back(v);
					}
					else {
						while(g[v].size())
							add_back(u,ask_back(v)),del_back(v);
						rev[u] ^= 1;
					}
                }
                else {
					if(w == 0) {
						while(g[v].size())
							add_back(u,ask_front(v)),del_front(v);
					}
					else {
						while(g[v].size())
							add_back(u,ask_back(v)),del_back(v);
					}
				}
			}
		}
		for(int i = 1;i <= n;i ++) {
			g[i].clear();
		}
    }
    return 0;
}



