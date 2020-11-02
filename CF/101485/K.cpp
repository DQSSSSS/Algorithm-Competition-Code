#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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

int r,s,m,d,n;
vector<int> g[SZ];
int mp[222][222],b[SZ];

LL get(int x,int y,int z) {
    vector<int> tmp;
    for(int p : g[x]) tmp.push_back(p);
    for(int p : g[y]) tmp.push_back(p);
    for(int p : g[z]) tmp.push_back(p);
    sort(tmp.begin(),tmp.end());
  //  cout << tmp.size() << endl;
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
  //  printf("%d %d %d\n",x,y,z);
    //cout << tmp.size() << endl;
    LL ans = 1;
    for(int p : tmp) {
        if(ans > 1e18 / b[p]) return -1;
        ans *= b[p];
    }
    return ans;
}

int main() {
    r = read(),s = read(),m = read(),d = read(),n = read();
    for(int i = 1;i <= r;i ++) b[i] = read();
    for(int i = 1;i <= s+m+d;i ++) {
        int k = read();
        while(k --) {
            g[i].push_back(read());
        }
    }
    for(int i = 1;i <= n;i ++) {
        int x = read(),y = read();
        mp[x][y] = 1;
        mp[y][x] = 1;
    }
    LL ans = 0;
    for(int i = 1;i <= s;i ++) {
        for(int j = s+1;j <= s+m;j ++) {
            for(int k = s+m+1;k <= s+m+d;k ++) {
                if(mp[i][j] || mp[j][i]) continue;
                if(mp[i][k] || mp[k][i]) continue;
                if(mp[k][j] || mp[j][k]) continue;
                LL x = get(i,j,k);
                if(x == -1) return puts("too many"),0;
                if(ans + x > 1e18) return puts("too many"),0;
                ans += x;
            }
        }
    }
    cout << ans << endl;
}
