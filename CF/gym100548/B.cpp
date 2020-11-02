#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned int UI;
typedef pair<LL,LL> pii;
typedef pair<UI,UI> puu;
const int SZ = 8e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

const int n = 5;
const int m = 6;

pii get_nxt(int x,int y,char dir) {
    if(dir == 'L') return make_pair(x,y-1);
    if(dir == 'R') return make_pair(x,y+1);
    if(dir == 'U') return make_pair(x-1,y);
    if(dir == 'D') return make_pair(x+1,y);
}

bool isin(int x,int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int combo,length,ansx,ansy,md;
char ansl[11];
char num[11];
char a[11][11];

void down() {
    for(int i = 1;i <= m;i ++) {
        int j = n,k = n;
        while(j >= 1 && a[j][i]) j --,k --;
        while(k >= 1) {
            while(k >= 1 && a[k][i] == 0) k --;
            if(k == 0) break;
            a[j][i] = a[k][i];
            a[k][i] = 0;
            j --; k --;
        }
    }
}

int mark[11][11];
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};


void clr(int x,int y,char c) {
    mark[x][y] = 0;
    a[x][y] = 0;
    for(int i = 0;i < 4;i ++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isin(nx,ny)) {
            if(a[nx][ny] == c && mark[nx][ny]) {
                clr(nx,ny,c);
            }
        }
    }
}

int check() {
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            mark[i][j] = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(!a[i][j]) continue;
            if(i+2<=n) {
                if(a[i][j] == a[i+1][j] && a[i+1][j] == a[i+2][j]) {
                    mark[i][j] = 1;
                    mark[i+1][j] = 1;
                    mark[i+2][j] = 1;
                }
            }
            if(j+2<=m) {
                if(a[i][j] == a[i][j+1] && a[i][j+1] == a[i][j+2]) {
                    mark[i][j] = 1;
                    mark[i][j+1] = 1;
                    mark[i][j+2] = 1;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++) {
            if(mark[i][j] == 1) {
                ans ++;
                clr(i,j,a[i][j]);
            }
        }
    return ans;
}

void print() {
    for(int i = 1;i <= n;i ++,puts(""))
        for(int j = 1;j <= m;j ++)
            printf("%c",a[i][j]);
    puts("");
}

int flag = 0;

void work(int sx,int sy,int l) {
    int c = 0;
   // printf("(%d,%d) ",sx,sy);
    //for(int i = 0;i < l;i ++) cout << num[i]; puts("");
    while(1) {
        int nc = check();
      //  print();
        if(nc == 0) break;
        down();
        c += nc;
    }
    if(c < combo) return ;
    int d = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(a[i][j] == 0)
                d ++;
    if(c > combo || (c == combo && d > md)
       || (c == combo && d == md && length > l)) {
        combo = c;
        md = d;
        length = l;
        for(int i = 0;i < l;i ++) ansl[i] = num[i];
        ansx = sx;
        ansy = sy;

      /*  flag = 1;
        int F=0,W=0,P=0,L=0,D=0,C=0;
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++) {
                if(a[i][j] == 'F') if(++F>=3) flag = 0;
                if(a[i][j] == 'W') if(++W>=3) flag = 0;
                if(a[i][j] == 'P') if(++P>=3) flag = 0;
                if(a[i][j] == 'L') if(++L>=3) flag = 0;
                if(a[i][j] == 'D') if(++D>=3) flag = 0;
                if(a[i][j] == 'C') if(++C>=3) flag = 0;
            }*/
    }
}

char mp[11][11];
int sx,sy;

void dfs(int x,int y,int k) {
   // if(flag) return ;
    if(1 <= k && k <= 9) {
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
                a[i][j] = mp[i][j];
        int nx = sx,ny = sy;
        for(int i = 0;i < k;i ++) {
            pii dd = get_nxt(nx,ny,num[i]);
            int x = dd.first;
            int y = dd.second;
           // printf("%d %d | %d %d\n",x,y,nx,ny);
            swap(a[nx][ny],a[x][y]);
            nx = x; ny = y;
        }
        work(sx,sy,k);
    }
   // printf("(%d,%d) %d\n",x,y,k);
    if(k < 9) {
        char b[] = "DRLU";
        for(int i = 0;i < 4;i ++) {
            pii d = get_nxt(x,y,b[i]);
            if(k && (num[k-1] == 'L' && b[i] == 'R')) continue;
            if(k && (num[k-1] == 'R' && b[i] == 'L')) continue;
            if(k && (num[k-1] == 'U' && b[i] == 'D')) continue;
            if(k && (num[k-1] == 'D' && b[i] == 'U')) continue;
            if(isin(d.first,d.second)) {
                num[k] = b[i];
                dfs(d.first,d.second,k+1);
            }
        }
    }
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        combo = -1;
        flag = 0;
        for(int i = 1;i <= n;i ++) scanf("%s",mp[i]+1);
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                sx = i,sy = j;
                dfs(i,j,0);
               // cout << i << " " << j << endl;
            }
        }
        printf("Case #%d:\n",++ cc);
        printf("Combo:%d Length:%d\n",combo,length);
        printf("%d %d\n",ansx,ansy);
        for(int i = 0;i < length;i ++) printf("%c",ansl[i]);
        puts("");
    }
}

/**

1
CFFLLW
CPDPDC
FLDWFD
LFCFCD
CDPLWL

C F  F  L  L  W
C P  D  P  D  C
F L  D  W  F  D
L F  C  F  C  D
C D  P  L  W  L

C F  F  L  L  W
C P  D  P [C  D]
F L  D [F  C] D
L F [F  W  W] D
C D  P  L [C] L

*/
