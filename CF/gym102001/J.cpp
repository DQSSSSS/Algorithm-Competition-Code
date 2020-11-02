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

int n;
vector<pair<string,int> > str[22];
string s[22];
int f[22][1<<16];
int g[1<<16];
int dy[22][1<<16],len[22];

int main() {
    n = read();
    for(int i = 0;i < n;i ++) {
        cin >> s[i];
        len[i] = s[i].length();
        for(int j = 0;j < (1<<len[i]);j ++) {
            string ss;
            for(int k = 0;k < len[i];k ++) {
                if(j >> k & 1) ss += s[i][k];
            }
            str[i].push_back(make_pair(ss,j));
        }
        sort(str[i].begin(),str[i].end());
        for(int j = 0;j < (1<<len[i]);j ++) dy[i][str[i][j].second] = j;
    }
    for(int i = 0;i < n;i ++) {
        for(int S = 1;S < (1<<len[i]);S ++) {
            int t = 0;
            string ss;
            for(int j = 0;j < len[i];j ++) if(S>>j&1) t++,ss += s[i][j];
            if(i == 0) { f[i][S] = t; continue; }
            int it = lower_bound(str[i-1].begin(),str[i-1].end(),
                                 make_pair(ss,0)) - str[i-1].begin() - 1;
            if(it == -1) f[i][S] = -INF;
            else f[i][S] = g[it] + t;
        }
        f[i][0] = -INF;
     //   puts("------");
       // for(int S = 0;S < (1<<len[i]);S ++) printf("%s %d\n",str[i][dy[i][S]].first.c_str(),f[i][S]);
        for(int S = 0;S < (1<<len[i]);S ++) g[dy[i][S]] = f[i][S];
        for(int S = 1;S < (1<<len[i]);S ++) g[S] = max(g[S-1],g[S]);
    }
    int ans = -1;
    for(int i = 1;i < (1<<len[n-1]);i ++) ans = max(ans,f[n-1][i]);
    cout << ans << endl;
}
