#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,int> pli;
typedef pair<int,int> pii;
const int SZ = 5e7 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 +a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

bool vis[SZ];
int pri[SZ],tot = 0;

int main() {
    int n = 2e7;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j]==0) break;
        }
    }
    cout << tot << endl;
    cout << pri[1226564] << endl;
}
