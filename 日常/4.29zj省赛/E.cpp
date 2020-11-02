#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <ctime>
#define MAXN 100010
#define MAXM 5000010
#define INF 0x3f3f3f3f
#define nil (&node[0])
using namespace std;

struct Edge {
    int u, v, w;
};

struct Node{
    int fa, val, depth;
    vector<int> ch;
} node[MAXM];

int n, m, S, T, B, ans, tclock = 0;
vector<int> G[MAXN];
Edge edge[MAXM];
int d[MAXN];

inline int min(int a, int b) {
    return a > b ? b : a;
}

inline void addEdge(int u, int v, int w) {
    edge[B].u = u;
    edge[B].v = v;
    edge[B].w = w;
    G[u].push_back(B ++);
}

template <class T> inline void readInt(T &l) {
    char a;
    T res = 0;
    int minus = false;
    for(;;) {
        a = getchar();
        if(a == ' ' || a == '\n' || a == EOF || a == '\0') {
            l = res;
            break;
        }
        if(a == '-') {
            minus = true;
            continue;
        }
        if(a >= '0' && a <= '9') res *= 10, res += a - '0';
    }
    if(minus) l = -l;
}

inline void in() {
    int i, a, b, c;
    readInt(n);
    readInt(m);
    B = 0;
    for(i = 1;i <= n;i ++) {
        G[i].clear();
        node[i].ch.clear();
        node[i].depth = 0;
        node[i].fa = 0;
        node[i].val = 0;
    }
    S = 4009;
    for(i = 1;i <= n;i ++) {
        addEdge(S, i, 0);
    }
    for(i = 0;i < m;i ++) {
        //cout<<"aaa";
        //scanf("%d%d%d", &a, &b, &c);
        readInt(a);
        readInt(b);
        readInt(c);
        addEdge(a, b, c);
    }
}
//////////////////////////////////////////////////////////
inline void Change(int x, int val) {
    node[x].val = val;
    for(int i = 0;i < node[x].ch.size();i ++) {
        node[node[x].ch[i]].val = val;
        Change(node[x].ch[i], val);
    }
}

inline void Maintain(int x) {
    for(int i = 0;i < node[x].ch.size();i ++) {
        node[node[x].ch[i]].depth = node[x].depth + 1;
        Maintain(node[x].ch[i]);
    }
}

inline int Query(int x) {
    return node[x].val;
}

inline void Link(int x, int y) {
    node[x].fa = y;
    node[x].depth = node[y].depth + 1;
    Maintain(x);
    node[y].ch.push_back(x);
}

inline void Cut(int x) {
    Node &s = node[node[x].fa];
    node[x].depth = 1;
    Maintain(x);
    for(int i = 0;i < s.ch.size();i ++) {
        if(s.ch[i] == x) {
            for(int j = i;j < s.ch.size() - 1;j ++) {
                s.ch[j] = s.ch[j + 1];
            }
            s.ch.pop_back();
            break;
        }
    }
    node[x].fa = 0;
}

inline int lca(int x, int y) {
    //cout << node[x].depth <<' '<<node[y].depth<<' '<<x<<' '<<y<<' '<<node[x].fa<<' '<<node[y].fa<<endl;
    if(x == y) return x;
    if(node[x].depth < node[y].depth) swap(x, y);
    for(;node[x].depth == node[y].depth;) x = node[x].fa;
    for(;x == y;x = node[x].fa, y = node[y].fa);
    return x;
}

inline bool SPFA() {
    int i, j, x, cnt = 0;
    queue<int> Q;
    memset(d, 0x3f, sizeof(d));
    d[0] = 0;
    node[0].depth = 1;
    Q.push(0);
    Change(0, 1);
    while(!Q.empty()) {
        x = Q.front();
        Q.pop();
        cnt ++;
        if(!Query(x)) continue;
        for(i = 0;i < G[x].size();i ++) {
            Edge &e = edge[G[x][i]];
            //cout << G[x][i] << endl;
            //cout << d[x] << ' ' << e.w << ' ' << d[e.v] << ' ' << x << ' ' << e.v << endl;
            if(d[x] + e.w < d[e.v]) {
                if(lca(x, e.v) == e.v) {
                    return 0;
                }
                d[e.v] = d[x] + e.w;
                Q.push(e.v);
                Change(e.v, 0);
                node[e.v].val = 1;
                Cut(e.v);
                Link(e.v, x);
            }
        }
    }
    return 1;
    //cout<<cnt<<endl;
}

int a[200010],L[200010],R[200010];
int b[200010];

int main()
{
	int T;
	readInt(T);
	while(T --)
	{
		readInt(n);
		G[0].clear(); B = 0; tclock = 0;
		for(int i = 1;i <= n;i ++) readInt(a[i]),b[i] = 0,G[i].clear();
		for(int i = 1;i <= n;i ++) readInt(L[i]),readInt(R[i]);
		for(int i = 1;i <= n;i ++)
		{
			int j = b[a[i]];
			if(!j) b[a[i]] = i;
			else addEdge(i,j,0);
			j = b[a[i] - 1];
			if(j) addEdge(j,i,1);
		}
		for(int i = 1;i <= n;i ++) addEdge(i,0,-R[i]),addEdge(0,i,L[i]);
		SPFA();
		for(int i = 1;i <= n;i ++)
			printf("%d%c",d[i],i == n ? '\n' : ' ');
	}
	return 0;
}

