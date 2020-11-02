#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct haha {
    int x,y,id;
}a[SZ];

bool cmp(haha a,haha b) { return a.x > b.x; }

int b[SZ],mp[SZ];

bitset<10010> f[12][2],ans,mask;

int main() {
    int n = read(),k = read();
    for(int i = 1;i <= n;i ++) {
        a[i].x = read();
        int y = read();
        while(y --) {
            int x = read() - 1;
            a[i].y |= 1 << x;
            b[i] |= 1 << x;
        }
        a[i].id = i;
    }

    sort(a+1,a+1+n,cmp);

    for(int i = 1,lst = 1;i <= n;i ++) {
        if(i == n || a[i+1].x != a[i].x) {
            for(int j = lst;j <= i;j ++)
                mp[a[j].id] = lst - 1;
            lst = i + 1;
        }
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = 0;j < k;j ++) {
            int x = a[i].y >> j & 1;
            f[j][x].set(i);
        }
        mask.set(i);
    }

    int m = read();
    while(m --) {
        int id;
        int x = mp[id = read()];
        int y = read();
        ans = mask;
        while(y --) {
            int d = read() - 1;
            int p = b[id] >> d & 1;
            ans &= f[d][p];
        }
        ans <<= n-x; ans &= mask;
        printf("%d\n",ans.count() + 1);
    }
}
