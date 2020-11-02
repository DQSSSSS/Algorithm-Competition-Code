#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

char mp[222][222],Ans[SZ];

char get_you_dir(char c) {
    if(c == 'D') return 'L';
    if(c == 'U') return 'R';
    if(c == 'L') return 'U';
    if(c == 'R') return 'D';
}

pii get_zb(int x,int y,char c) {
    if(c == 'D') return make_pair(x+1,y);
    if(c == 'U') return make_pair(x-1,y);
    if(c == 'L') return make_pair(x,y-1);
    if(c == 'R') return make_pair(x,y+1);
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) scanf("%s",mp[i]+1);
    int x,y;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            if(mp[i][j] == 'S') x = i,y = j;
        }
    }
    char dir = 'R';
    int len = 0;
    while(1) {
            bool flag = 0;
        if(mp[x][y] == 'T') flag = 1;
        pii t = get_zb(x,y,get_you_dir(dir));
        if(mp[t.first][t.second] != '#') {
            dir = get_you_dir(dir);
            x = t.first; y = t.second;
        }
        else {
            Ans[++ len] = get_you_dir(dir);
            t = get_zb(x,y,dir);
            if(mp[t.first][t.second] == '.') {
                x = t.first; y = t.second;
            }
            else {
                dir = get_you_dir(dir);
                dir = get_you_dir(dir);
                dir = get_you_dir(dir);
            }
        }
        if(flag) break;
    }
    printf("%s\n",Ans + 1);
}

