#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

const int MAXN = 2 * 31 * SZ;

struct Trie {
    int ch[MAXN][2],sz[MAXN],val[MAXN];
    int Tcnt = 0;

    void insert(pii v) {
        int p = 0;
        for(int i = 29;i >= 0;i --) {
            int c = v.first >> i & 1;
            sz[p] ++;
            if(!ch[p][c]) ch[p][c] = ++ Tcnt;
            assert(Tcnt < 310 * SZ);
            p = ch[p][c];
        }
        sz[p] ++;
        val[p] = v.second;
    }

    pii find_xor_max(int x) {
        int p = 0,ans = 0;
        for(int i = 29;i >= 0;i --) {
            int c = x >> i & 1;
            if(ch[p][c^1] && sz[ch[p][c^1]]) p = ch[p][c^1],ans |= (c^1)<<i;
            else p = ch[p][c],ans |= c<<i;
        }
        assert(sz[p]);
        return make_pair(ans,val[p]);
    }

    void erase(int x) {
        int p = 0;
        for(int i = 29;i >= 0;i --) {
            int c = x >> i & 1;
            sz[p] --;
            p = ch[p][c];
        }
        sz[p] --;
        val[p] = 0;
    }

    void clear() {
        for(int i = 0;i <= Tcnt;i ++) {
            sz[i] = 0;
            val[i] = 0;
            memset(ch[i],0,sizeof ch[i]);
        }
        Tcnt = 0;
    }
}tree[2];

struct haha {
    int v,t,type,id;
};

mt19937 rd(time(0));

int randlr(int l,int r) { return rd()%(r-l+1)+l; }

int main() {
    int T = read();
    while(T --) {
        tree[0].clear();
        tree[1].clear();

        int n;
        n = read();

        vector<haha> V;
        for(int o = 0;o < 2;o ++) {
            map<int,int> mp;
            for(int i = 1;i <= n;i ++) {
                int x = read();
                mp[x] ++;
            }
            for(pii p : mp) {
                V.push_back((haha){p.first,p.second,o,V.size()});
            }
        }
        for(int i = 0;i < V.size();i ++) {
            tree[V[i].type].insert(make_pair(V[i].v,i));
        }

        vector<int> ans,ins; ins.resize(V.size());
        for(int i = 0;i < V.size();i ++) {
            if(V[i].t == 0) continue;
            stack<int> S;
            S.push(i); ins[i] = 1;
            while(S.size()) {
                haha u = V[S.top()]; S.pop(); ins[u.id] = 0;
                pii p = tree[u.type^1].find_xor_max(u.v);
                assert(V[p.second].type != u.type);
                if(!ins[p.second]) {
                    S.push(u.id); S.push(p.second);
                    ins[u.id] = ins[p.second] = 1;
                }
                else {
                    haha v = V[p.second];
                    ins[v.id] = 0; S.pop();
                    tree[u.type].erase(u.v);
                    tree[v.type].erase(v.v);
                    while(V[u.id].t && V[v.id].t) {
                        ans.push_back(u.v^v.v);
                        V[u.id].t --; V[v.id].t --;
                    }
                    if(V[u.id].t) {
                        tree[u.type].insert(make_pair(u.v,u.id));
                    }
                    if(V[v.id].t) {
                        S.push(v.id);
                        ins[v.id] = 1;
                        tree[v.type].insert(make_pair(v.v,v.id));
                    }
                }
            }
        }
        LL sum = 0;
        for(int i = 0;i < ans.size();i ++) {
            sum += ans[i];
        }
        printf("%lld\n",sum);
    }
    return 0;
 }
