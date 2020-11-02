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

string S1[22],S2[22];
int n;
int f[111][111];

void work() {
    map<string,int> mp;
    int tot = 0;
    for(int i = 1;i <= n;i ++) {
        string s1 = S1[i],s2 = S2[i];
        if(!mp[s1]) mp[s1] = ++ tot;
        if(!mp[s2]) mp[s2] = ++ tot;
    }

    for(int i = 1;i <= tot;i ++) {
        for(int j = 1; j <= tot;j ++) {
            f[i][j] = 0;
        }
    }

    for(int i = 1;i <= n;i ++) {
        string s1 = S1[i],s2 = S2[i];
        int x = mp[s1],y = mp[s2];
        if(f[y][x]) {
            cout << s1 << " " << s2 << endl;
            return ;
        }
        f[x][y] = 1;
        for(int k = 1;k <= tot;k ++) {
            for(int u = 1;u <= tot;u ++) {
                for(int v = 1;v <= tot;v ++) {
                    if(f[u][k] && f[k][v]) {
                        f[u][v] = 1;
                    }
                }
            }
        }
        for(int u = 1;u <= tot;u ++) {
            for(int v = 1;v <= tot;v ++) {
                if(f[u][v]) {
                    if(u == v || f[v][u]) {
                        cout << s1 << " " << s2 << endl;
                        return ;
                    }
                }
            }
        }
       /* for(int u = 1;u <= tot;u ++,puts(""))
            for(int v = 1;v <= tot;v ++)
                printf("%d ",f[u][v]);
        puts("");*/
    }
    puts("0");
    return ;
}

int main() {
    while(~scanf("%d",&n)) {
        for(int i = 1;i <= n;i ++) {
            string s1,s2;
            cin >> s1 >> s2;
            S1[i] = s1;
            S2[i] = s2;
        }
        work();
    }
}
