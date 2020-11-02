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

int mp[111][111];
int a[111],b[111];

bool isin(int x,int y) {
    return x >= 1 & x <= 8 && y >= 1 && y <= 8;
}

bool fz(int sx,int sy,int dx,int dy,int f) {
    int x = sx + dx;
    int y = sy + dy;
    while(isin(x,y) && mp[x][y] == (f^1)) {
        x += dx;
        y += dy;
    }
    if(!isin(x,y)) return false;
    if(mp[x][y] == -1) return false;
    if(x == sx + dx && y == sy + dy) return false;
    x = sx + dx;
    y = sy + dy;
    while(isin(x,y) && mp[x][y] == (f^1)) {
        mp[x][y] = f;
        x += dx;
        y += dy;
    }
    return true;
}

bool check(int d,int f) {
    int x = (d-1)/8+1,y = (d-1) % 8+1;
    if(mp[x][y] != -1) return false;
    const int dx[] = {0,1,0,-1,1,1,-1,-1};
    const int dy[] = {1,0,-1,0,1,-1,1,-1};
    int dd = 0;
    for(int i = 0;i < 8;i ++) {
        dd += fz(x,y,dx[i],dy[i],f);
     //   cout << i << " " << dd << endl;
    }
    if(dd) mp[x][y] = f;
    return dd != 0;
}

void print() {
    for(int i = 1;i <= 8;i ++) {
        for(int j = 1;j <= 8;j ++) {
            char c = '.';
            if(mp[i][j] == 1) c = 'B';
            if(mp[i][j] == 0) c = 'W';
            printf("%c",c);
        }
        puts("");
    }
}

int main() {
    for(int i = 1;i <= 64;i ++) a[i] = read();
    for(int i = 1;i <= 64;i ++) b[i] = read();
    memset(mp,-1,sizeof mp);
    mp[4][4] = 0;
    mp[4][5] = 1;
    mp[5][5] = 0;
    mp[5][4] = 1;
   // check(35,1);
    while(1) {
        int f1 = 0,f2 = 0;
        for(int i = 1;i <= 64;i ++) {
            if(check(a[i],1)) { f1 = i; break; }
        }
        for(int i = 1;i <= 64;i ++) {
            if(check(b[i],0)) { f2 = i; break; }
        }
      //  cout << f1 << " " << f2 << endl;
      //  print();
        if(!f1 && !f2) break;
    }
    for(int i = 1;i <= 8;i ++) {
        for(int j = 1;j <= 8;j ++) {
            char c = '.';
            if(mp[i][j] == 1) c = 'B';
            if(mp[i][j] == 0) c = 'W';
            printf("%c",c);
        }
        puts("");
    }
}
