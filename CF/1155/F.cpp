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

vector<int> g[22];

struct haha {
    int id,S,S1;
}pre[5000010];

map<pii,int> mp;
pii ori[5000010];
int n,m,a[210],b[210];
int f[5000010];
int G[5000010];
bool vis[5000010];

int get(int S,int S1) {
    return mp[make_pair(S,S1)];
}

void print(int S,int S1) {
    for(int i = 0;i < n;i ++)
        if(S >> i & 1) printf("%d,",i+1);
    printf("\t---\t");
    for(int i = 0;i < n;i ++)
        if(S1 >> i & 1) printf("%d,",i+1);
    cout << "\t\t";
   // puts("");
}

int dfs(int S,int S1);

void tryupdate(int &ans,int S,int S1,int SS,int SS1,int i) {
    if(ans > dfs(SS,SS1)+1)
        ans = dfs(SS,SS1)+1,pre[get(S,S1)]=(haha){i,SS,SS1};
}

int dfs(int S,int S1) {
    int id = mp[make_pair(S,S1)];
    if(!G[id]) return 1e9;
    if(vis[id]) return f[id];
    vis[id] = 1;
    int ans = 1e9;
    for(int i = 1;i <= m;i ++) {
        int x = a[i],y = b[i];
        if((S >> x & 1) && (S >> y & 1)) {
            if((S1 >> x & 1) == 0 && (S1 >> y & 1) == 0) {
                tryupdate(ans,S,S1,S,S1^(1<<x)^(1<<y),i);
                tryupdate(ans,S,S1,S,S1^(1<<x),i);
                tryupdate(ans,S,S1,S,S1^(1<<y),i);
            }

            if((S1 >> x & 1) == 1 && (S1 >> y & 1) == 0) {
                tryupdate(ans,S,S1,S^(1<<x),S1^(1<<x)^(1<<y),i);
                tryupdate(ans,S,S1,S^(1<<x),S1^(1<<x),i);
            }

            if((S1 >> x & 1) == 0 && (S1 >> y & 1) == 1) {
                tryupdate(ans,S,S1,S^(1<<y),S1^(1<<y)^(1<<x),i);
                tryupdate(ans,S,S1,S^(1<<y),S1^(1<<y),i);
            }
        }
    }
    return f[id] = ans;
}

void pre_dfs(int S,int S1) {
    int id = mp[make_pair(S,S1)];
    if(G[id]) return ;
    G[id] = 1;
    for(int u = 0;u < n;u ++) {
        if(S >> u & 1) {
            if(S1 >> u & 1) {
                for(int v : g[u]) {
                    if(S >> v & 1) {
                        if(S1 >> v & 1)
                            pre_dfs(S,S1^(1<<u)^(1<<v));
                        else
                            pre_dfs(S,S1^(1<<u));
                    }
                }
            }
        }
        else {
            for(int v : g[u]) {
                if(S >> v & 1) {
                    if(S1 >> v & 1)
                        pre_dfs(S^(1<<u),S1^(1<<u)^(1<<v));
                    else
                        pre_dfs(S^(1<<u),S1^(1<<u));
                }
            }
        }
    }
}

vector<int> Ans;
bool use[210];

bool tryupdateans(int S,int S1,int SS,int SS1) {
    int id = mp[make_pair(S,S1)];
    if(pre[id].S == SS && pre[id].S1 == SS1) return true;
    return false;
}


/**
        if((S >> x & 1) && (S >> y & 1)) {
            if((S1 >> x & 1) == 0 && (S1 >> y & 1) == 0) {
                tryupdate(ans,S,S1,S,S1^(1<<x)^(1<<y));
                tryupdate(ans,S,S1,S,S1^(1<<x));
                tryupdate(ans,S,S1,S,S1^(1<<y));
            }

            if((S1 >> x & 1) == 1 && (S1 >> y & 1) == 0) {
                tryupdate(ans,S,S1,S^(1<<x),S1^(1<<x)^(1<<y));
                tryupdate(ans,S,S1,S^(1<<x),S1^(1<<x));
            }

            if((S1 >> x & 1) == 0 && (S1 >> y & 1) == 1) {
                tryupdate(ans,S,S1,S^(1<<y),S1^(1<<y)^(1<<x));
                tryupdate(ans,S,S1,S^(1<<y),S1^(1<<y));
            }
        }


void dfs2(int S,int S1) {
    print(S,S1); puts("");
    int id = mp[make_pair(S,S1)];
    int ans = f[id];
    for(int i = 1;i <= m;i ++) {
        int x = a[i],y = b[i];
        if(use[i]) continue;
        if((S >> x & 1) && (S >> y & 1)) {
            if((S1 >> x & 1) == 0 && (S1 >> y & 1) == 0) {
                if(tryupdateans(S,S1,S,S1^(1<<x)^(1<<y))) {
                    Ans.push_back(i),use[i]=1,dfs2(S,S1^(1<<x)^(1<<y));
                    return ;
                }
                if(tryupdateans(S,S1,S,S1^(1<<x))) {
                    Ans.push_back(i),use[i]=1,dfs2(S,S1^(1<<x));
                    return ;
                }

                if(tryupdateans(S,S1,S,S1^(1<<y))) {
                    Ans.push_back(i),use[i]=1,dfs2(S,S1^(1<<y));
                    return ;
                }
            }
            if((S1 >> x & 1) == 1 && (S1 >> y & 1) == 0) {
                if(tryupdateans(S,S1,S^(1<<x),S1^(1<<x)^(1<<y))) {
                    Ans.push_back(i),use[i]=1,dfs2(S^(1<<x),S1^(1<<x)^(1<<y));
                    return ;
                }
                else if(tryupdateans(S,S1,S^(1<<x),S1^(1<<x))) {
                    Ans.push_back(i),use[i]=1,dfs2(S^(1<<x),S1^(1<<x));
                    return ;
                }
            }
            if((S1 >> x & 1) == 0 && (S1 >> y & 1) == 1) {
                if(tryupdateans(S,S1,S^(1<<y),S1^(1<<y)^(1<<x))) {
                    Ans.push_back(i),use[i]=1,dfs2(S^(1<<y),S1^(1<<y)^(1<<x));
                    return ;
                }
                else if(tryupdateans(S,S1,S^(1<<y),S1^(1<<y))) {
                    Ans.push_back(i),use[i]=1,dfs2(S^(1<<y),S1^(1<<y));
                    return ;
                }
            }


            if(S1 == S && ((1<<x)^(1<<y)) == S) {
                Ans.push_back(i); use[i] = 1;
                return ;
            }
        }
    }
}
*/
int main() {
    n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read()-1,y = read()-1;
        g[x].push_back(y);
        g[y].push_back(x);
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



    for(int i = 1;i <= m;i ++) {
        int x = a[i],y = b[i];
        pre_dfs((1<<x)^(1<<y),(1<<x)^(1<<y));
    }

    for(int S = 0;S < (1<<n);S ++) {
        for(int S1 = S;S1 > 0;S1 = (S1 - 1) & S) {
            if(G[mp[make_pair(S,S1)]]) {
                print(S,S1); cout << f[mp[make_pair(S,S1)]] << endl;
               // puts("");
            }
        }
        if(G[mp[make_pair(S,0)]]) {
            print(S,0); cout << f[mp[make_pair(S,0)]] << endl;
            //puts("");
        }
    }

    int id = mp[make_pair(0,0)]; vis[id] = 1; f[id] = 0;
    for(int i = 1;i <= m;i ++) {
        int x = a[i],y = b[i],id;
        id = mp[make_pair((1<<x)|(1<<y),0)];
        vis[id] = 1; f[id] = 1e9;
        id = mp[make_pair((1<<x)|(1<<y),1<<x)];
        vis[id] = 1; f[id] = 1e9;
        id = mp[make_pair((1<<x)|(1<<y),1<<y)];
        vis[id] = 1; f[id] = 1e9;
        id = mp[make_pair((1<<x)|(1<<y),(1<<x)|(1<<y))];
        vis[id] = 1; f[id] = 1; pre[id].id = i;
    }
    for(int x = 0;x < n;x ++) {
        int id = mp[make_pair((1<<x),0)]; vis[id] = 1; f[id] = 1e9;
        id = mp[make_pair((1<<x),1<<x)]; vis[id] = 1; f[id] = 1e9;
        for(int y = 0;y < n;y ++) {
            if(x == y) continue;
            int id = mp[make_pair((1<<x)|(1<<y),0)];
            if(vis[id]) continue;
            vis[id] = 1; f[id] = 1e9;
            id = mp[make_pair((1<<x)|(1<<y),1<<x)];
            vis[id] = 1; f[id] = 1e9;
            id = mp[make_pair((1<<x)|(1<<y),1<<y)];
            vis[id] = 1; f[id] = 1e9;
            id = mp[make_pair((1<<x)|(1<<y),(1<<x)|(1<<y))];
            vis[id] = 1; f[id] = 1e9;
        }
    }


   // cout << dfs(26,10) << endl;
    int ans = dfs(mask,0);
    cout << ans << endl;

    for(int i = 1,S = mask,S1 = 0;i <= ans;i ++) {
        print(S,S1); puts("");
        haha p = pre[get(S,S1)];
        Ans.push_back(p.id);
        S = p.S; S1 = p.S1;
     //   S = p.first; S1 = p.second;
    }
/*
    for(int S = 0;S < (1<<n);S ++) {
        for(int S1 = S;S1 > 0;S1 = (S1 - 1) & S) {
            if(vis[mp[make_pair(S,S1)]]) {
                print(S,S1); cout << f[mp[make_pair(S,S1)]] << endl;
            }
        }
        if(vis[mp[make_pair(S,0)]]) {
            print(S,0); cout << f[mp[make_pair(S,0)]] << endl;
        }
    }*/

   // dfs2(mask,0);
    for(int i : Ans) printf("%d %d\n",a[i]+1,b[i]+1);
}
