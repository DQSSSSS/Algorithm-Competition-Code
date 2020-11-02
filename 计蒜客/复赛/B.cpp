#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e6 + 10;
const int mod = 998244353;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int sz[6][6],dz[6];
int len[6],l;
string s[55];

bool dfs(int pos) {
    if(pos == 14) return true;

    for(int i = 1;i <= 4;i ++)
        if(len[i] < 3) {
            bool flag = 0;
            if(len[i] == 0) flag = 1;
            else if(len[i] == 1) {
                if(s[pos] == s[sz[i][1]]) flag = 1;
                else {
                    int id = sz[i][1];
                    if(s[pos][1] != 'z')
                        if(s[pos][1] == s[id][1] &&
                            abs((int)s[pos][0] - (int)s[id][0]) <= 2) flag = 1;
                }
            }
            else if(len[i] == 2) {
                if(s[sz[i][1]] == s[sz[i][2]] && s[sz[i][1]] == s[pos]) flag = 1;
                else {
                    if(s[sz[i][1]][1] == 'z') continue;
                    if(s[sz[i][2]][1] == 'z') continue;
                    if(s[pos][1] == 'z') continue;
                    if(s[sz[i][1]][1] == s[sz[i][2]][1] && s[sz[i][2]][1] == s[pos][1]) {
                        int tmp[5] = {},L = 0;
                        tmp[++ L] = s[sz[i][1]][0] - '0';
                        tmp[++ L] = s[sz[i][2]][0] - '0';
                        tmp[++ L] = s[pos][0] - '0';
                        sort(tmp+1,tmp+1+L);
                        if(tmp[1] + 1 == tmp[2] && tmp[2] + 1 == tmp[3]) flag = 1;
                    }
                }
            }
            if(!flag) continue;
            sz[i][++ len[i]] = pos;
            if(dfs(pos + 1)) return true;
            len[i] --;
        }

    if(l < 2) {
        bool flag = 1;
        if(l) {
            if(s[dz[1]] != s[pos]) flag = 0;
        }
        if(flag) {
            dz[++ l] = pos;
            if(dfs(pos + 1)) return true;
            l --;
        }
    }
    return false;
}

bool check() {
    for(int i = 1;i <= 9;i ++) {
        int t = 0;
        string x; x += i + '0'; x += 'm';
        for(int j = 0;j < 14;j ++) {
            if(s[j] == x) t ++;
        }
        if(t > 4) return false;
    }

    for(int i = 1;i <= 9;i ++) {
        int t = 0;
        string x; x += i + '0'; x += 's';
        for(int j = 0;j < 14;j ++) {
            if(s[j] == x) t ++;
        }
        if(t > 4) return false;
    }

    for(int i = 1;i <= 9;i ++) {
        int t = 0;
        string x; x += i + '0'; x += 'p';
        for(int j = 0;j < 14;j ++) {
            if(s[j] == x) t ++;
        }
        if(t > 4) return false;
    }

    for(int i = 1;i <= 7;i ++) {
        int t = 0;
        string x; x += i + '0'; x += 'z';
        for(int j = 0;j < 14;j ++) {
            if(s[j] == x) t ++;
        }
        if(t > 4) return false;
    }
    return true;
}

void work() {

    for(int i = 1;i <= 9;i ++) {
        char c = i + '0';
        s[0] = ""; s[0] += c; s[0] += 'm';
        if(check() && dfs(0)) cout << s[0] << endl;
        l = 0; memset(len,0,sizeof len);
    }
    for(int i = 1;i <= 9;i ++) {
        char c = i + '0';
        s[0] = ""; s[0] += c; s[0] += 's';
        if(check() && dfs(0)) cout << s[0] << endl;
        l = 0; memset(len,0,sizeof len);
    }
    for(int i = 1;i <= 9;i ++) {
        char c = i + '0';
        s[0] = ""; s[0] += c; s[0] += 'p';
        if(check() && dfs(0)) cout << s[0] << endl;
        l = 0; memset(len,0,sizeof len);
    }
    for(int i = 1;i <= 7;i ++) {
        char c = i + '0';
        s[0] = ""; s[0] += c; s[0] += 'z';
        if(check() && dfs(0)) cout << s[0] << endl;
        l = 0; memset(len,0,sizeof len);
    }
}

string haha() {}

char input[SZ];

int main() {
    while(~scanf("%s",input)) {
        s[1] = input;
        for(int i = 2;i <= 13;i ++) {
            scanf("%s",input);
            s[i] = input;
        }
        work();
        haha();
    }
}

/**
1m 2m 3m 4m 5m 6m 7m 8m 9m 1z 1z 3s 4s
1s 1s 1s 9s 9s 9s 2s 3s 4s 5s 6s 7s 8s
2s 2s 2s 3s 4s 4s 4s 1p 1p 2p 2p 3p 3p
2s 3s 3s 3s 3s 4s 4s 4s 4s 5s 5s 5s 5s
2s 2s 2s 2s 3s 3s 3s 4s 4s 4s 5s 5s 5s

1z 1z 1z 2z 2z 2z 3z 3z 3z 4z 4z 4z 5z
*/
