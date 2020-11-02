/**
给一个n点m边的无向图，问最少留下多少条边使得剩下的图是一个仙人掌

代码需要修改
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e6 + 3;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

vector<pii> g[22];

struct haha {
    int id,S,S1,id2;
}nx[5000010];

map<pii,int> mp;
pii ori[5000010];
int n,m,a[210],b[210];
int f[5000010];
int G[5000010];
bool vis[5000010];

int get(int S,int S1) {
    return mp[make_pair(S,S1)];
}

string get(int x) {
    string s;
    while(x) s += (char)(x%10)+'0',x /= 10;
    reverse(s.begin(),s.end());
    return s;
}

void print(int S,int S1) {
    string s,s1;
    for(int i = 0;i < n;i ++)
        if(S >> i & 1) s += get(i+1),s += ",";
    for(int i = 0;i < n;i ++)
        if(S1 >> i & 1) s1 += get(i+1),s1 += ",";
    printf("%25s --- %25s ",s.c_str(),s1.c_str());
    //cout << "\t\t";
   // puts("");
}

int dfs(int S,int S1);

void tryupdate(int &ans,int S,int S1,int SS,int SS1,int i,int i2 = 0) {
    if(ans > dfs(SS,SS1)+1+(i2!=0)) {
        //if(S==0&&S1==0) printf("["),print(S,S1),printf("]\t\t\t->\t"),printf("["),print(SS,SS1),printf("] %d %d\n",i,i2);
        ans = dfs(SS,SS1)+1+(i2!=0),nx[get(S,S1)]=(haha){i,SS,SS1,i2};
    }
}

int dfs(int S,int S1) {
    int id = mp[make_pair(S,S1)];
    if(vis[id]) return f[id];
    vis[id] = 1;
    int ans = 1e9;
    for(int u = 0;u < n;u ++) {
        if(S >> u & 1) continue;
        for(pii p : g[u]) {
            int v = p.first;
            if(S1 >> v & 1) tryupdate(ans,S,S1,S^(1<<u),S1^(1<<u)^(1<<v),p.second);
            if((S^S1) >> v & 1) tryupdate(ans,S,S1,S^(1<<u),S1^(1<<u),p.second);
            for(pii p2 : g[u]) {
                int v2 = p2.first;
                if(v2 == v) continue;
                if((S1 >> v & 1) && (S1 >> v2 & 1))
                    tryupdate(ans,S,S1,S^(1<<u),S1^(1<<v)^(1<<v2),p.second,p2.second);
                if(((S^S1) >> v & 1) && ((S^S1) >> v2 & 1))
                    tryupdate(ans,S,S1,S^(1<<u),S1,p.second,p2.second);
            }
        }
    }
    return f[id] = ans;
}

vector<int> Ans;
bool use[210];

int main() {
    n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read()-1,y = read()-1;
        g[x].push_back(make_pair(y,i));
        g[y].push_back(make_pair(x,i));
        a[i] = x; b[i] = y;
    }

    int tot = 0,mask = (1<<n)-1;
    for(int S = 0;S < (1<<n);S ++) {
        for(int S1 = S;S1 > 0;S1 = (S1 - 1) & S) {
            tot ++;
            ori[tot] = make_pair(S,S1);
            mp[make_pair(S,S1)] = tot;
        }
        mp[make_pair(S,0)] = ++ tot;
    }

    int id = mp[make_pair(mask,0)];
    vis[id] = 1; f[id] = 0;

    int ans = 1e9;
    for(int i = 1;i <= m;i ++) {
        int x = a[i],y = b[i],id;
        id = mp[make_pair((1<<x)|(1<<y),0)];
        vis[id] = 1; f[id] = 1e9;
        id = mp[make_pair((1<<x)|(1<<y),1<<x)];
        vis[id] = 1; f[id] = 1e9;
        id = mp[make_pair((1<<x)|(1<<y),1<<y)];
        vis[id] = 1; f[id] = 1e9;
        id = mp[make_pair((1<<x)|(1<<y),(1<<x)|(1<<y))];
        tryupdate(ans,0,0,(1<<x)|(1<<y),(1<<x)|(1<<y),i);
    }
/*
    for(int S = 0;S < (1<<n);S ++) {
        for(int S1 = S;S1 > 0;S1 = (S1 - 1) & S) {
            if(nx[get(S,S1)].id) {
                print(S,S1); printf("%d %d\n",nx[get(S,S1)].id,nx[get(S,S1)].id2);
            }
        }
        if(nx[get(S,0)].id) {
            print(S,0); printf("%d %d\n",nx[get(S,0)].id,nx[get(S,0)].id2);
        }
    }
*/
    cout << ans << endl;

    for(int i = 1,S = 0,S1 = 0;S != mask || S1;i ++) {
        haha p = nx[get(S,S1)];
        Ans.push_back(p.id);
        if(p.id2) Ans.push_back(p.id2);
        //print(S,S1); printf("%d %d\n",p.id,p.id2);
        S = p.S; S1 = p.S1;
    }
    for(int i : Ans) printf("%d %d\n",a[i]+1,b[i]+1);
}

/**
5 7
1 3
2 3
3 4
5 3
4 5
2 5
1 5




































10 15
1 2
1 9
2 3
2 6
3 7
4 6
4 8
5 6
10 1
2 10
7 1
4 2
9 10
5 1
8 6


O(3^n*n^3)
*/
