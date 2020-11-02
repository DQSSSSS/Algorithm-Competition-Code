#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
const int SZ = 210;
const int mod = 78294349;

LL read() {
    LL n = 0;
    bool flag = 0;
    char a = getchar();
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

int mp[SZ][SZ];
int n,m;

void print(int mp[SZ][SZ]) {
    for(int i = 1;i <= n;i ++,puts(""))
        for(int j = 1;j <= m;j ++)
            printf("%3d",mp[i][j]);
    puts("");
}

ULL get_hash() {
    ULL ans = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            ans = ans * 233 + mp[i][j] + 1;
    return ans;
}
void up() {
    for(int j = 1;j <= m;j ++) {
        int tot = 0;
        for(int i = 1;i <= n;i ++) {
            if(mp[i][j]) mp[++tot][j]=mp[i][j];
        }
        for(int i = tot + 1;i <= n;i ++) mp[i][j] = 0;
    }
}

void down() {
    for(int j = 1;j <= m;j ++) {
        int tot = n + 1;
        for(int i = n;i >= 1;i --) {
            if(mp[i][j]) mp[--tot][j]=mp[i][j];
        }
        for(int i = tot - 1;i >= 1;i --) mp[i][j] = 0;
    }
}

void left() {
    for(int i = 1;i <= n;i ++) {
        int tot = 0;
        for(int j = 1;j <= m;j ++) {
            if(mp[i][j]) mp[i][++tot] = mp[i][j];
        }
        for(int j = tot + 1;j <= m;j ++) mp[i][j] = 0;
    }
}

void right() {
    for(int i = 1;i <= n;i ++) {
        int tot = m + 1;
        for(int j = m;j >= 1;j --) {
            if(mp[i][j]) mp[i][--tot] = mp[i][j];
        }
        for(int j = tot - 1;j >= 1;j --) mp[i][j] = 0;
    }
}

void work() {
    map<ULL,bool> h;
    puts("----------------");
    h.clear();
    memset(mp,0,sizeof mp);
    int x = rand() % m + 1,tot = 0;
    for(int j = 1;j <= x;j ++) {
        int y = rand() % n + 1;
        for(int i = 1;i <= y;i ++) mp[n-i+1][j] = ++ tot;
    }
    left();

    cout << n << " " << m << endl;
    for(int i = 1;i <= n;i ++,puts(""))
        for(int j = 1;j <= m;j ++)
            printf("%c",mp[i][j] ? '#' : '.');

    for(int j = 1;j <= m;j ++) {
        int ans = 0;
        for(int i = 1;i <= n;i ++) ans += mp[i][j] != 0;
        printf("%3d",ans);
    }
    puts("");

   // print();
    int ans = 1;
    h[get_hash()] = 1;
    while(233) {
        up(); right(); down(); left();
        ULL x = get_hash();
        if(h.count(x)) break;
        h[x] = 1;
        ans ++;
       // print();
    }
    printf("number : %d\n",ans);
}

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int pri[] = {7,1321,8467};
char str[SZ][SZ];
int ini[SZ][SZ],a[SZ*SZ];
bool vis[SZ*SZ];

int dfs(int u) {
    if(vis[u]) return 0;
    vis[u] = 1;
    return dfs(a[u]) + 1;
}

int main() {
    n = 50,m = 50;
    work();
   // cout << 6*1320*8466 << endl;
    int T = read();
    while(T --) {
        n = read(),m = read();
        for(int i = 1;i <= n;i ++)
            scanf("%s",str[i]+1);
        int tot = 0;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                if(str[i][j] == '#')
                    mp[i][j] = ini[i][j] = ++ tot;
                else
                    mp[i][j] = ini[i][j] = 0;
            }
        }
        up(); right(); down(); left();
        map<ULL,bool> h;
        int ans = 1;
        h[get_hash()] = 1;
        print(mp);
        while(233) {
            up(); right(); down(); left();
            ULL x = get_hash();
            if(h.count(x)) break;
            h[x] = 1;
            ans ++;
            print(mp);
        }
        printf("number : %d\n",ans);
    }
}

/**
2 3
#..
###
*/
