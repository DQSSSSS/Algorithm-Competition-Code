#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 6e6 + 10;
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

int id[22][22];
int pos[22][22],len[110];
int tong[22];
char s[110][10100];
char ans[10100];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m*(m-1)/2;i ++) {
        char o[3]; scanf("%s%d",o,&len[i]);
        if(len[i] == 0) {
            getchar();
            continue;
        }
        int x = o[0]-'a',y = o[1]-'a';
        id[x][y] = id[y][x] = i;
        scanf("%s",s[i]);
      //  cout << s[i] << " -- " << len[i] << endl;
        if(len[i]) tong[s[i][0]-'a'] ++;
    }
    for(int l = 0;l < n;l ++) {
        int o = -1,t = 0;
       // for(int i = 0;i < m;i ++) cout << tong[i] << " "; puts("");
        for(int i = 0;i < m;i ++)
            if(tong[i] == m-1)
                o = i,t ++;

        if(o == -1) return puts("-1"),0;
        if(t > 1) return puts("-1"),0;
        ans[l] = o+'a';
        tong[o] = 0;
        for(int i = 0;i < m;i ++) {
            if(o == i) continue;
            if(pos[i][o] == len[id[i][o]]) continue;
            pos[i][o] ++;
            pos[o][i] ++;
            if(pos[i][o] == len[id[i][o]]) continue;
          //  cout << id[i][o] << " " << pos[i][o] << " " << len[i] << endl;
            tong[s[id[i][o]][pos[i][o]]-'a'] ++;
        }
    }
    for(int i = 0;i < m;i ++) {
        for(int j = 0;j < m;j ++){
            int x = id[i][j];
            if(pos[i][j] != len[x]) { return puts("-1"),0; }
        }
    }
    for(int i = 0;i < n;i ++) printf("%c",ans[i]);
}
