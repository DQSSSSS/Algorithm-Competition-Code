#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

struct haha {
	int u,v,id;
}l[SZ];

struct edge {
	int v,id;
};

struct heihei {
	int u,id;
};

int du[SZ],n,m;
int ans = 0,tot = 1;
vector<edge> g[SZ];
vector<int> jidu;
vector<int> ansPath[50010];
bool ji[SZ];
int path[SZ * 2];
int pathEdge[SZ * 2];
bool vis[SZ * 2];
bool found[SZ];
int nodeArray[SZ],t;

void init() {
	jidu.clear();
	path[0] = pathEdge[0] = 0;
	tot = 1; ans = 0; t = m + 1;
	for(int i = 1;i <= 100000;i ++) g[i].clear(),du[i] = 0,ji[i] = 0;
	for(int i = 1;i <= 200000;i ++) vis[i] = 0;
	for(int i = 1;i <= 50000;i ++) ansPath[i].clear();
}

void dfs(int u,int edgeId) {
	for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i].v;
        if(vis[g[u][i].id]) continue;
        vis[g[u][i].id] = 1;
        dfs(v,g[u][i].id);
    }
	path[++ path[0]] = u;
	if(edgeId <= m && u == l[edgeId].u)
		edgeId *= -1;
	pathEdge[++ pathEdge[0]] = edgeId;
}

void rev(int *a,int l,int r) {
	for(int i = l;i <= (r - l + 1) / 2;i ++)
        swap(a[i],a[l + r - i]);
}

void dfsNode(int u,int fa) {
	found[u] = 1;
	nodeArray[++ nodeArray[0]] = u;
	for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i].v;
        if(v == fa || found[v]) continue;
        dfsNode(v,u);
    }
}

void get_path(int s) {
	path[0] = pathEdge[0] = 0;
	for(int i = 1,lst = -1;i <= nodeArray[0];i ++) {
		int u = nodeArray[i];
		if(!ji[u]) continue;
        if(lst == -1) { lst = u; continue; }
        int x = lst,y = u;
		g[x].push_back((edge){y,t});
		g[y].push_back((edge){x,t});
		t ++; lst = u;
	}
    dfs(nodeArray[1],0);
    rev(path,1,path[0]);
	rev(pathEdge,1,path[0]);
	int firstId = 1;
	for(int i = 2;i <= path[0];i ++)
		if(pathEdge[i] > m) { firstId = i; break; }
	//cout << firstId << endl;
	for(int i = firstId + 1;i <= path[0];i ++) {
		int x = pathEdge[i];
		if(x > m) {
			if(ansPath[tot].size() != 0) tot ++;
			assert(tot < 50010);
			continue;
		}
		ansPath[tot].push_back(x);
	}
	for(int i = 2;i < firstId;i ++) {
		int x = pathEdge[i];
		ansPath[tot].push_back(x);
	}
	if(ansPath[tot].size()) tot ++;
	//for(int i = 1;i <= path[0];i ++) printf("%3d",path[i]); puts("");
	//for(int i = 1;i <= path[0];i ++) printf("%3d",pathEdge[i]); puts("");
}

int get_ans() {
    for(int i = 1;i <= n;i ++) found[i] = 0;
    nodeArray[0] = 0;
    ans = 0;
    for(int i = 1;i <= n;i ++) {
        if(!found[i]) {
            nodeArray[0] = 0;
            dfsNode(i,0);
			int s = i,tmp = 0;
			for(int j = 1;j <= nodeArray[0];j ++)
				if(ji[nodeArray[j]]) { tmp ++; s = nodeArray[j]; }
            if(nodeArray[0] == 1) continue;
            get_path(s);
			if(tmp == 0) ans ++;
			else ans += tmp / 2;
		}
    }
    if(ansPath[tot].size() == 0) tot --;
	return tot;
}

bool use[SZ];

int main() {
    while(~scanf("%d%d",&n,&m)) {
		init();

		for(int i = 1;i <= m;i ++) use[i] = 0;
		for(int i = 1;i <= m;i ++) {
            int x = read(),y = read();
            l[i] = (haha){x,y,i};
			g[x].push_back((edge){y,i});
			g[y].push_back((edge){x,i});
			du[x] ++; du[y] ++;
		}
		for(int i = 1;i <= n;i ++)
			if(du[i] % 2 == 1)
				jidu.push_back(i),ji[i] = 1;

        int tot = get_ans();
        while(tot > ans);
        int sumSize = 0;
        printf("%d\n",ans);
        for(int i = 1;i <= tot;i ++) {
			assert(ansPath[i].size() > 0);
			printf("%d ",ansPath[i].size());
			sumSize += ansPath[i].size();
			int lst = -1;
			for(int j = 0;j < ansPath[i].size();j ++) {
				printf("%d%c",ansPath[i][j],j == ansPath[i].size() - 1 ? '\n' : ' ');

				assert(abs(ansPath[i][j]) <= m);
				assert(use[abs(ansPath[i][j])] == 0);
				use[abs(ansPath[i][j])] = 1;
				//cout << lst << " ";
				if(j > 0) {
					if(ansPath[i][j] < 0) assert(lst == l[abs(ansPath[i][j])].v);
					else assert(lst == l[ansPath[i][j]].u);
				}
				lst = ansPath[i][j] < 0 ? l[abs(ansPath[i][j])].u : l[ansPath[i][j]].v;
			}
        }
        assert(sumSize == m);
    }
    return 0;
}
/*
13 12
1 2
1 3
2 3
3 4
2 5
7 6
7 10
7 8
7 9
11 12
12 13
13 11


100 18
1 2
2 3
3 1
3 4
5 6
6 7
7 8
7 9
9 10
10 11
11 9
21 22
22 23
23 24
24 21
23 25
24 26
5 8


5 5
1 2
2 3
1 4
4 5
5 1

*/
