#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e3 + 10;

LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

int n,m;
int a[SZ][SZ],mp[SZ][SZ];
bool isin(int x,int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

void jian(int x,int y) {
    for(int i = -1;i <= 1;i ++)
        for(int j = -1;j <= 1;j ++) {
            if(isin(x+i,y+j))
                a[x+i][y+j] --;
        }
}

bool work(int id) {
    for(int i = 2;i < m;i ++) {
        if(a[id-1][i-1]) {
            mp[id][i] = 1;
            jian(id,i);
        }
    }
    for(int i = 1;i <= m;i ++) if(a[id-1][i]) return false;
    return true;
}

int main() {
    n = read() + 2,m = read() + 2;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            a[i][j] = read();
    for(int i = 2;i < n;i ++) {
        if(!work(i)) return puts("impossible"),0;
    }
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(a[i][j] != 0)
                return puts("impossible"),0;

    for(int i = 2;i < n;i ++,puts(""))
        for(int j = 2;j < m;j ++)
            putchar(mp[i][j] ? 'X' : '.');
}
