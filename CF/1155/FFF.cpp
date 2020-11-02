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

int n,m,a[210],b[210],mp[22][22];
int f[20010],L[20010];
vector<int> G[20010],nodes[20010];
bool vis[20010];

string get(int x) {
    string s;
    while(x) s += (char)(x%10)+'0',x /= 10;
    reverse(s.begin(),s.end());
    return s;
}
void print(int S) {
    string s;
    for(int i = 0;i < n;i ++)
        if(S >> i & 1) s += get(i+1),s += ",";
    printf("%25s ",s.c_str());
    //cout << "\t\t";
   // puts("");
}

int dfs(int S) {
    if(vis[S]) return f[S];
    vis[S] = 1;
    int ans = 1e9,X = -1,Y = -1,SS = -1;
    for(int S1 = (S1-1)&S;S1 > 0;S1 = (S1 - 1) & S) {
        int S2 = S ^ S1;
        int id1 = 0,id2 = 0;
        if(nodes[S1].size() == 2 && nodes[S2].size() == 2) {
            int x1 = nodes[S1][0],y1 = nodes[S1][1];
            int x2 = nodes[S2][0],y2 = nodes[S2][1];
            if(mp[x1][x2]) id1 = mp[x1][x2],id2 = mp[y1][y2];
            else id1 = mp[x1][y2],id2 = mp[x2][y1];
        }
        else if(nodes[S1].size() == 2) {
            int x = nodes[S1][0],y = nodes[S1][1];
            for(int i = 0;i < n;i ++)
                if(S2 >> i & 1) {
                    if(id1 == 0 && mp[x][i]) id1 = mp[x][i];
                    else if(id2 == 0 && mp[y][i]) id2 = mp[y][i];
                }
            if(id1 == 0 || id2 == 0) {
                for(int i = 0;i < n;i ++)
                    if(S2 >> i & 1) {
                        if(id1 == 0 && mp[y][i]) id1 = mp[y][i];
                        else if(id2 == 0 && mp[x][i]) id2 = mp[x][i];
                    }
            }
        }
        else if(nodes[S2].size() == 2) {
            int x = nodes[S2][0],y = nodes[S2][1];
            for(int i = 0;i < n;i ++)
                if(S1 >> i & 1) {
                    if(id1 == 0 && mp[x][i]) id1 = mp[x][i];
                    else if(id2 == 0 && mp[y][i]) id2 = mp[y][i];
                }
            if(id1 == 0 || id2 == 0) {
                for(int i = 0;i < n;i ++)
                    if(S1 >> i & 1) {
                        if(id1 == 0 && mp[y][i]) id1 = mp[y][i];
                        else if(id2 == 0 && mp[x][i]) id2 = mp[x][i];
                    }
            }
        }
        else {
            for(int i = 1;i <= m;i ++) {
                int x = a[i],y = b[i];
                if(((S1>>x&1) && ((S^S1)>>y&1)) || ((S1>>y&1) && ((S^S1)>>x&1))) {
                    if(id1 == 0) id1 = i;
                    else id2 = i;
                }
            }
        }
        if(id2 == 0 || id1 == 0) continue;
        int tmp = dfs(S1) + dfs(S ^ S1) + 2;
        if(tmp<=m) {
            print(S); print(S1); print(S^S1); printf("%d=%d+%d+2 %d %d\n",tmp,dfs(S1),dfs(S^S1),id1,id2);
        }
        if(ans > tmp) ans = tmp,X = id1,Y = id2,SS = S1;
    }
    if(X) G[S].push_back(X);
    if(Y) G[S].push_back(Y);
    L[S] = SS;
    print(S); cout << ans << endl;
    return f[S] = ans;
}

vector<int> Ans;

void dfs2(int S) {
    print(S); puts("");
    for(int x : G[S]) Ans.push_back(x);
    if(L[S] > 0) dfs2(L[S]),dfs2(S^L[S]);
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read()-1,y = read()-1;
        a[i] = x; b[i] = y;
        mp[x][y] = i;
        mp[y][x] = i;
    }

    for(int i = 0;i < n;i ++) vis[1<<i]=1,f[1<<i]=0;
    for(int i = 0;i < n;i ++)
        for(int j = i+1;j < n;j ++) {
            int S = (1<<i)|(1<<j);
            vis[S] = 1;
            if(!mp[i][j]) { f[S] = INF; continue; }
            G[S].push_back(mp[i][j]);
            f[S] = 1;
        }

    for(int i = 0;i < (1<<n);i ++) {
        for(int j = 0;j < n;j ++)
            if(i >> j & 1)
                nodes[i].push_back(j);
    }

    dfs((1<<n)-1);
    cout << f[(1<<n)-1] << endl;
    dfs2((1<<n)-1);
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
*/

